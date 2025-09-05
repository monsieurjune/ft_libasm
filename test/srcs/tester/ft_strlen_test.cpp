extern "C" {
    #include "../../lib/include/libasm.h"
}

#include "tester/tester.hpp"
#include "utils/utils.hpp"
#include "symbol/symbol.hpp"
#include "logger/Logger.hpp"

#include <string.h>
#include <unistd.h>

#include <deque>
#include <string>

namespace test
{

namespace cases
{

void    ft_strlen_signal(int signum)
{
    (void)signum;
    exit(test::symbol::e_symbol::TOO_LONG);
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
    test::utils::parent_wait(logger, case_name, pid, max_time);
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
