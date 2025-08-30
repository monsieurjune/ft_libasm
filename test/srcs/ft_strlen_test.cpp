extern "C" {
    #include "../../lib/include/libasm.h"
}

#include "tester.hpp"

#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

#include <deque>
#include <string>
#include <iostream>

namespace test
{

namespace cases
{

void    ft_strlen_signal(int signum)
{
    (void)signum;
    exit(1);
}

static void sb_strlen_test(const char* case_name, const char* str)
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

        (void)libasm_ret;
        (void)std_ret;
        (void)case_name;
        exit(0);
    }

    // parent
    int     status;
    time_t  start   = time(NULL);

    while (1)
    {
        pid_t   child_pid   = waitpid(pid, &status, WNOHANG);

        // child is dead
        if (child_pid == pid)
        {
            if (WIFEXITED(status))
            {
            }
            if (WIFSIGNALED(status))
            {
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
    std::deque<std::pair<std::string, std::string>> const   deque = test::utils::get_test_cases(path);

    if (deque.size() == 0)
    {
        return;
    }

    for (auto const& pair : deque)
    {
        sb_strlen_test(pair.first.c_str(), pair.second.c_str());
    }
}

}

}
