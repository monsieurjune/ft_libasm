#include "../srcs/tester.hpp"

#include <signal.h>

#include <iostream>

namespace test
{

namespace utils
{

static inline int  sb_init_mask(struct sigaction* sig, void (*handler)(int))
{
    // do literal nothing if handler is null
    if (handler == NULL)
        return 0;

    if (sigemptyset(&sig->sa_mask) == -1)
		return 1;
    sig->sa_flags = SA_RESTART | SA_NOCLDSTOP;
	sig->sa_handler = handler;

    return (0);
}

int signal_init()
{
    struct sigaction    sig_ft_strlen;
    struct sigaction    sig_ft_strcpy;
    struct sigaction    sig_ft_strcmp;
    struct sigaction    sig_ft_write;
    struct sigaction    sig_ft_read;
    struct sigaction    sig_ft_strdup;

    // init mask
    if (sb_init_mask(&sig_ft_strlen, &test::cases::ft_strlen_signal))
        return 1;
    if (sb_init_mask(&sig_ft_strcpy, NULL))
        return 1;
    if (sb_init_mask(&sig_ft_strcmp, NULL))
        return 1;
    if (sb_init_mask(&sig_ft_write, NULL))
        return 1;
    if (sb_init_mask(&sig_ft_read, NULL))
        return 1;
    if (sb_init_mask(&sig_ft_strdup, NULL))
        return 1;

    // init signal
    if (sigaction(SIGINT, &sig_ft_strlen, NULL) == -1)
        return 2;

    return 0;
}

}

}