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

namespace signal
{

void    ft_strcmp_signal(int signum)
{
    (void)signum;
    exit(test::symbol::e_symbol::TOO_LONG);
}

}

namespace cases
{

static void sb_strcmp_test(
                test::log::Logger& logger, 
                const char* case_name, 
                const char* s1,
                const char* s2
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
            // create buffer
            std::string tmp_s1(s1);
            std::string tmp_s2(s2);

            // start to test
            int std_ret     = strcmp(s1, s2);
            int libasm_ret  = ft_strcmp(s1, s2);

            if (libasm_ret != std_ret)
            {
                exit(test::symbol::e_symbol::RETVAL_FAIL);
            }

            if (tmp_s1 != s1 || tmp_s2 != s2)
            {
                exit(test::symbol::e_symbol::CONTENT_FAIL);
            }

            exit(test::symbol::e_symbol::SUCCESS);
        }
        catch (std::bad_alloc const&)
        {
            exit(test::symbol::e_symbol::UNKNOWN);
        }
    }

    // parent
    test::utils::parent_wait(logger, case_name, pid, max_time);
}

void    ft_strcmp_test(const char* path)
{
    test::log::Logger           logger(NULL, "ft_strcmp");
    test::utils::t_cases const  deque = test::utils::get_test_cases(path);

    if (deque.size() == 0)
    {
        return;
    }

    for (auto const& pair : deque)
    {
        sb_strcmp_test(
            logger, 
            pair.first.c_str(), 
            pair.second.at(0).c_str(),
            pair.second.at(1).c_str()
        );
    }
}

}

}
