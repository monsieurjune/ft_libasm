extern "C" {
    #include "../../lib/include/libasm.h"
}

#include "tester/tester.hpp"

#include "utils/utils.hpp"
#include "symbol/symbol.hpp"
#include "logger/Logger.hpp"

#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include <string>

constexpr const char*   TAG    = "ft_read";
constexpr const char*   LOGNAME = NULL;

namespace test
{

static uint8_t  *buff       = NULL;
static uint8_t  *ft_buff    = NULL;
static int      fd          = -1;
static int      ft_fd       = -1;

static inline void  sb_free_fd()
{
    if (buff != NULL)
    {
        delete[] buff;
        buff = NULL;
    }

    if (ft_buff != NULL)
    {
        delete[] ft_buff;
        ft_buff = NULL;
    }

    if (fd != -1)
    {
        close(fd);
        fd = -1;
    }

    if (ft_fd != -1)
    {
        close(ft_fd);
        ft_fd = -1;
    }
}

namespace signal
{

void    ft_read_signal(int signum)
{
    (void)signum;
    sb_free_fd();
    exit(test::symbol::e_symbol::TOO_LONG);
}

}

namespace cases
{


static void sb_read_test(
                test::log::Logger* logger, 
                const char* case_name, 
                const char* path,
                const char* n_str
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
        int     err = 0;
        int     ft_err  = 0;
        int     con_ret = 0;
        ssize_t ret     = 0;
        ssize_t ft_ret  = 0;
        ssize_t n       = atoll(n_str);

        // allocate buffer
        buff = new uint8_t[n + 1];
        ft_buff = new uint8_t[n + 1];

        // open file
        fd = open(path, O_RDONLY);
        ft_fd = open(path, O_RDONLY);

        if (fd == -1 || ft_fd == -1)
        {
            sb_free_fd();
            exit(test::symbol::e_symbol::OPEN_FAIL);
        }

        // test
        ret = read(fd, buff, n);
        err = errno;
        ft_ret = ft_read(ft_fd, ft_buff, n);
        ft_err = errno;
        con_ret = memcmp(buff, ft_buff, n);

        // free
        sb_free_fd();

        // check return val
        if (ret != ft_ret)
        {
            exit(test::symbol::e_symbol::RETVAL_FAIL);
        }

        // in case of error
        if (ft_ret == -1 && err != ft_err)
        {
            exit(test::symbol::e_symbol::ERRNO_FAIL);
        }

        // check buffer
        if (con_ret != 0)
        {
            exit(test::symbol::e_symbol::CONTENT_FAIL);
        }
        exit(test::symbol::e_symbol::SUCCESS);
    }
    catch (std::bad_alloc const&)
    {
        sb_free_fd();
        exit(test::symbol::e_symbol::MEM_ERROR);
    }
    catch (std::exception const&)
    {
        sb_free_fd();
        exit(test::symbol::e_symbol::UNKNOWN);
    }
}

void    ft_read_test(const char* path)
{
    test::log::Logger           logger(LOGNAME, TAG);
    test::utils::t_cases const  deque = test::utils::get_test_cases(path);

    if (deque.size() == 0)
    {
        return;
    }

    for (auto const& pair : deque)
    {
        sb_read_test(
            &logger, 
            pair.first.c_str(), 
            pair.second.at(0).c_str(),
            pair.second.at(1).c_str()
        );
    }
}

}

}
