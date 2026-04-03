#include "utils/utils.hpp"

#include "logger/Logger.hpp"
#include "symbol/symbol.hpp"

#include <time.h>
#include <sys/wait.h>

#include <sstream>
#include <string>

namespace test
{

namespace utils
{

static inline void  sb_check_dead_child(test::log::Logger* logger, const char* case_name, int status)
{
    std::stringstream   ss;

    ss << "[" << case_name << "] ";
    if (WIFEXITED(status))
    {
        ss << test::symbol::get_symbol(static_cast<test::symbol::e_symbol>(WEXITSTATUS(status)));
    }
    else if (WIFSIGNALED(status))
    {
        ss << test::symbol::get_signal_name(WTERMSIG(status));
    }
    logger->log(logger->INFO, ss.str());
}

void    parent_wait(test::log::Logger* logger, const char* case_name, pid_t pid, int max_time)
{
    int     status;
    time_t  start   = time(NULL);

    while (1)
    {
        pid_t   child_pid = waitpid(pid, &status, WNOHANG);

        // child is dead
        if (child_pid == pid)
        {
            sb_check_dead_child(logger, case_name, status);
            break;
        }

        // if child isn't dead yet and time is out, kill it
        if (time(NULL) - start > static_cast<time_t>(max_time))
        {
            kill(pid, SIGINT);
        }
    }
}

}

}