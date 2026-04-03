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

static char*   buff = NULL;

static inline void  sb_free_buff(void)
{
    if (buff == NULL)
        return;

    delete[] buff;
    buff = NULL;
}

namespace signal
{

void    ft_strcpy_signal(int signum)
{
    (void)signum;

    sb_free_buff();
    exit(test::symbol::e_symbol::TOO_LONG);
}

}

namespace cases
{

static void sb_strcpy_test(
                test::log::Logger* logger, 
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

    // parent
    if (pid != 0)
    {
        test::utils::parent_wait(logger, case_name, pid, max_time);
        return;
    }

    // child
    try
    {
        buff = new char[strlen(str) + 1];

        // start to test
        std::string tmp0(str);
        char*       libasm_ret = ft_strcpy(buff, str);

        // check return ptr
        if (libasm_ret != buff)
        {
            sb_free_buff();
            exit(test::symbol::e_symbol::RETVAL_FAIL);
        }

        // check content
        int src_diff = strncmp(tmp0.c_str(), str, tmp0.length());
        int dst_diff = strncmp(tmp0.c_str(), buff, tmp0.length());

        sb_free_buff();
        if (src_diff != 0 || dst_diff != 0)
        {
            exit(test::symbol::e_symbol::CONTENT_FAIL);
        }
        exit(test::symbol::e_symbol::SUCCESS);
    }
    catch (std::bad_alloc const&)
    {
        exit(test::symbol::e_symbol::MEM_ERROR);
    }
    catch (std::exception const&)
    {
        exit(test::symbol::e_symbol::UNKNOWN);
    }
}

void    ft_strcpy_test(const char* path)
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
