extern "C" {
    #include "../../lib/include/libasm.h"
}

#include "tester/tester.hpp"
#include "utils/utils.hpp"
#include "symbol/symbol.hpp"
#include "logger/Logger.hpp"

#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

#include <deque>
#include <string>
#include <sstream>
#include <iostream>

namespace test
{

namespace cases
{

void    ft_strlen_signal(int signum)
{
    (void)signum;
    exit(2);
}

static void sb_strcpy_test(test::log::Logger& logger, const char* case_name, const char* str)
{
    pid_t   pid = fork();

    // error
    if (pid == -1)
    {
        return;
    }

    // child
    if (pid == 0)
    {
        size_t  libasm_ret  = ft_strlen(str);
        size_t  std_ret     = strlen(str);

        exit(!(libasm_ret == std_ret));
    }

    // parent
    int                 status;
    std::stringstream   ss;
    time_t              start   = time(NULL);

    while (1)
    {
        pid_t   child_pid   = waitpid(pid, &status, WNOHANG);

        // child is dead
        if (child_pid == pid)
        {
            if (WIFEXITED(status))
            {
                switch (WEXITSTATUS(status))
                {
                    case 0:
                        ss << "[" << case_name << "] " << test::symbol::get_symbol(test::symbol::SUCCESS);
                        logger.log(logger.INFO, ss.str());
                        break;
                    case 1:
                        ss << "[" << case_name << "] " << test::symbol::get_symbol(test::symbol::FAIL);
                        logger.log(logger.INFO, ss.str());
                        break;
                    case 2:
                        ss << "[" << case_name << "] " << test::symbol::get_symbol(test::symbol::TOO_LONG);
                        logger.log(logger.INFO, ss.str());
                        break;
                    default:
                        ss << "[" << case_name << "] " << test::symbol::get_symbol(test::symbol::UNKNOWN);
                        logger.log(logger.INFO, ss.str());
                        break;
                }
            }
            if (WIFSIGNALED(status))
            {
                ss << "[" << case_name << "] " << test::symbol::get_signal_name(WTERMSIG(status));
                logger.log(logger.INFO, ss.str());
            }
            break;
        }

        // if child isn't dead yet, kill it, if timeout
        if (time(NULL) - start > test::cases::max_time)
        {
            kill(pid, SIGINT);
        }
    }
}

void    ft_strlen_test(const char* path)
{
    test::log::Logger           logger(NULL, "ft_strlen");
    test::utils::t_cases const  deque = test::utils::get_test_cases(path);

    if (deque.size() == 0)
    {
        return;
    }

    for (auto const& pair : deque)
    {
        sb_strcpy_test(logger, pair.first.c_str(), pair.second.at(0).c_str());
    }
}

}

}
