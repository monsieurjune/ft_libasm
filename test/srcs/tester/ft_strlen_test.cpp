extern "C" {
    #include "../../lib/include/libasm.h"
}

#include "tester/tester.hpp"

#include "utils/utils.hpp"
#include "symbol/symbol.hpp"
#include "logger/Logger.hpp"

#include <string.h>
#include <unistd.h>

#include <string>

constexpr const char*   TAG    = "ft_strcpy";
constexpr const char*   LOGNAME = NULL;

namespace test
{

namespace signal
{

void    ft_strlen_signal(int signum)
{
    (void)signum;
    exit(test::symbol::e_symbol::TOO_LONG);
}

}

namespace cases
{

static void sb_strcpy_test(test::log::Logger* logger, const char* case_name, const char* str)
{
    pid_t   pid = fork();

    // error
    if (pid == -1)
    {
        return;
    }

    // parent
    if (pid != 0)
    {
        test::utils::parent_wait(logger, case_name, pid, max_time);
        return;
    }

    // child
    std::string tmp(str);
    size_t      std_ret     = strlen(str);
    size_t      libasm_ret  = ft_strlen(str);

    // check ret val
    if (libasm_ret != std_ret)
    {
        exit(test::symbol::e_symbol::RETVAL_FAIL);
    }

    // check content
    if (strncmp(tmp.c_str(), str, tmp.length()) != 0)
    {
        exit(test::symbol::e_symbol::CONTENT_FAIL);
    }

    exit(test::symbol::e_symbol::SUCCESS);
}

void    ft_strlen_test(const char* path)
{
    test::log::Logger           logger(LOGNAME, TAG);
    test::utils::t_cases const  deque = test::utils::get_test_cases(path);

    if (deque.size() == 0)
    {
        return;
    }

    for (auto const& pair : deque)
    {
        sb_strcpy_test(
            &logger, 
            pair.first.c_str(), 
            pair.second.at(0).c_str()
        );
    }
}

}

}
