extern "C" {
    #include "../../lib/include/libasm.h"
}

#include "tester.hpp"

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include <deque>
#include <string>
#include <iostream>

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

        std::cout << '[' << case_name << "] " << "libasm: " << libasm_ret << ", std: " << std_ret << std::endl;
        exit(0);
    }

    // parent
    int status;

    if (waitpid(pid, &status, 0) >= 0)
    {
    }
}

namespace test
{

namespace cases
{

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
