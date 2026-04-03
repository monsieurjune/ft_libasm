#include "utils/signal.hpp"

#include "tester/tester.hpp"
#include "logger/Logger.hpp"

#include <signal.h>

constexpr const char*   TAG         = "signal";
constexpr const char*   LOGFILE     = NULL;
constexpr int           success     = 0;
constexpr int           fail_mask   = 1;
constexpr int           fail_sigact = 2;

namespace test
{

namespace utils
{

static inline int  sb_init_mask(struct sigaction* sig, void (*handler)(int))
{
    // do literal nothing if handler is null
    if (handler == NULL)
        return 1;

    if (sigemptyset(&sig->sa_mask) == -1)
		return 0;
    sig->sa_flags = SA_RESTART | SA_NOCLDSTOP;
	sig->sa_handler = handler;

    return 1;
}

static int sb_signal_init(void)
{
    struct sigaction    sig_ft_strlen;
    struct sigaction    sig_ft_strcpy;
    struct sigaction    sig_ft_strcmp;
    struct sigaction    sig_ft_write;
    struct sigaction    sig_ft_read;
    struct sigaction    sig_ft_strdup;

    // init mask
    if (!sb_init_mask(&sig_ft_strlen, &test::signal::ft_strlen_signal))
        return fail_mask;
    if (!sb_init_mask(&sig_ft_strcpy, &test::signal::ft_strcpy_signal))
        return fail_mask;
    if (!sb_init_mask(&sig_ft_strcmp, &test::signal::ft_strcmp_signal))
        return fail_mask;
    if (!sb_init_mask(&sig_ft_write, NULL))
        return fail_mask;
    if (!sb_init_mask(&sig_ft_read, NULL))
        return fail_mask;
    if (!sb_init_mask(&sig_ft_strdup, NULL))
        return fail_mask;

    // init signal
    if (sigaction(SIGINT, &sig_ft_strlen, NULL) == -1)
        return fail_sigact;
    if (sigaction(SIGINT, &sig_ft_strcpy, NULL) == -1)
        return fail_sigact;
    if (sigaction(SIGINT, &sig_ft_strcmp, NULL) == -1)
        return fail_sigact;

    return success;
}

int signal_init(void)
{
    int ret = sb_signal_init();

    if (ret == 0)
    {
        return 1;
    }

    // Fail
    log::Logger logger(LOGFILE, TAG);

    if (ret == fail_mask)
    {
        logger.log(logger.CRITICAL, "sigemptyset() is failed");
    }
    else if (ret == fail_sigact)
    {
        logger.log(logger.CRITICAL, "sigaction() is failed");
    }

    return 0;
}

}

}