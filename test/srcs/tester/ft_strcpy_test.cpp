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

char*   buff = NULL;

namespace signal
{

void    ft_strcpy_signal(int signum)
{
    (void)signum;

    delete[] buff;
    buff = NULL;

    exit(test::symbol::e_symbol::TOO_LONG);
}

}

namespace cases
{

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
            // create buffer
            std::string tmp0(str);

            buff = new char[strlen(str) + 1];

            // start to test
            char*   libasm_ret = ft_strcpy(buff, str);

            // check return ptr
            if (libasm_ret != buff)
            {
                delete[] buff;
                buff = NULL;
                exit(test::symbol::e_symbol::RETVAL_FAIL);
            }

            // check content
            int origin_diff = strcmp(tmp0.c_str(), str);
            int asm_diff = strcmp(tmp0.c_str(), buff);

            // free
            delete[] buff;
            buff = NULL;

            if (origin_diff != 0 || asm_diff != 0)
            {
                exit(test::symbol::e_symbol::CONTENT_FAIL);
            }
            exit(test::symbol::e_symbol::SUCCESS);
        }
        catch (std::bad_alloc const&)
        {
            exit(test::symbol::e_symbol::MEM_ERROR);
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
