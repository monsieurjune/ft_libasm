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

char*   tmp1 = NULL;

void    ft_strcpy_signal(int signum)
{
    (void)signum;
    exit(test::symbol::e_symbol::TOO_LONG);
}

static void sb_strcpy_test(
                test::log::Logger& logger, 
                const char* case_name, 
                const char* str
            )
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
        try
        {
            tmp1 = new char[strlen(str) + 1];

            // start to test
            char*   libasm_ret = ft_strcpy(tmp1, str);

            // check return ptr
            if (libasm_ret != tmp1)
            {
                delete[] tmp1;
                tmp1 = NULL;
                exit(test::symbol::e_symbol::FAIL);
            }

            // check content
            int ret = strcmp(tmp1, str);

            delete[] tmp1;
            tmp1 = NULL;
            exit(!(ret == 0));
        }
        catch (std::bad_alloc const&)
        {
            delete[] tmp1;
            tmp1 = NULL;
            exit(test::symbol::e_symbol::UNKNOWN);
        }
    }

    // parent
    test::utils::parent_wait(logger, case_name, pid, max_time);
}

void    ft_strcpy_test(const char* path)
{
    test::log::Logger           logger(NULL, "ft_strcpy");
    test::utils::t_cases const  deque = test::utils::get_test_cases(path);

    if (deque.size() == 0)
    {
        return;
    }

    for (auto const& pair : deque)
    {
        sb_strcpy_test(
            logger, 
            pair.first.c_str(), 
            pair.second.at(0).c_str()
        );
    }
}

}

}
