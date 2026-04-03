#include "utils/color.hpp"

#include <signal.h>

namespace test
{

namespace symbol
{

struct __attribute__((aligned(64))) s_signal_symbol
{
    char sigint_sym[16];
    char sigterm_sym[20];
    char sigsegv_sym[20];
    char sigabrt_sym[20];
    char sigfpe_sym[16];
    char sigill_sym[16];
    char sigbus_sym[16];
    char sigchld_sym[20];
    char sigpipe_sym[20];
    char sigusr1_sym[20];
    char sigusr2_sym[20];
    char sigalrm_sym[20];
    char sigcont_sym[20];
    char sigstop_sym[20];
    char sigtstp_sym[20];
    char sigttin_sym[20];
    char sigttou_sym[20];
    char unknown_sym[20];
};

const char* get_signal_name(int signum)
{
    static const struct s_signal_symbol box = {
        .sigint_sym  = COLOR_MAGENTA "SIGINT" COLOR_RESET,
        .sigterm_sym = COLOR_MAGENTA "SIGTERM" COLOR_RESET,
        .sigsegv_sym = COLOR_MAGENTA "SIGSEGV" COLOR_RESET,
        .sigabrt_sym = COLOR_MAGENTA "SIGABRT" COLOR_RESET,
        .sigfpe_sym  = COLOR_MAGENTA "SIGFPE" COLOR_RESET,
        .sigill_sym  = COLOR_MAGENTA "SIGILL" COLOR_RESET,
        .sigbus_sym  = COLOR_MAGENTA "SIGBUS" COLOR_RESET,
        .sigchld_sym = COLOR_MAGENTA "SIGCHLD" COLOR_RESET,
        .sigpipe_sym = COLOR_MAGENTA "SIGPIPE" COLOR_RESET,
        .sigusr1_sym = COLOR_MAGENTA "SIGUSR1" COLOR_RESET,
        .sigusr2_sym = COLOR_MAGENTA "SIGUSR2" COLOR_RESET,
        .sigalrm_sym = COLOR_MAGENTA "SIGALRM" COLOR_RESET,
        .sigcont_sym = COLOR_MAGENTA "SIGCONT" COLOR_RESET,
        .sigstop_sym = COLOR_MAGENTA "SIGSTOP" COLOR_RESET,
        .sigtstp_sym = COLOR_MAGENTA "SIGTSTP" COLOR_RESET,
        .sigttin_sym = COLOR_MAGENTA "SIGTTIN" COLOR_RESET,
        .sigttou_sym = COLOR_MAGENTA "SIGTTOU" COLOR_RESET,
        .unknown_sym = COLOR_MAGENTA "UNKNOWN" COLOR_RESET,
    };

    switch (signum)
    {
        case SIGINT:    return box.sigint_sym;
        case SIGTERM:   return box.sigterm_sym;
        case SIGSEGV:   return box.sigsegv_sym;
        case SIGABRT:   return box.sigabrt_sym;
        case SIGFPE:    return box.sigfpe_sym;
        case SIGILL:    return box.sigill_sym;
        case SIGBUS:    return box.sigbus_sym;
        case SIGCHLD:   return box.sigchld_sym;
        case SIGPIPE:   return box.sigpipe_sym;
        case SIGUSR1:   return box.sigusr1_sym;
        case SIGUSR2:   return box.sigusr2_sym;
        case SIGALRM:   return box.sigalrm_sym;
        case SIGCONT:   return box.sigcont_sym;
        case SIGSTOP:   return box.sigstop_sym;
        case SIGTSTP:   return box.sigtstp_sym;
        case SIGTTIN:   return box.sigttin_sym;
        case SIGTTOU:   return box.sigttou_sym;
        default:        return box.unknown_sym;
    }
}

}

}
