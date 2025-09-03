#include <signal.h>

#define COLOR_RESET     "\033[0m"
#define COLOR_MAGENTA   "\033[35m"

namespace test
{

namespace symbol
{

const char* get_signal_name(int signum)
{
    static const char sigint_sym[16]    = COLOR_MAGENTA "SIGINT" COLOR_RESET;
    static const char sigterm_sym[20]   = COLOR_MAGENTA "SIGTERM" COLOR_RESET;
    static const char sigsegv_sym[20]   = COLOR_MAGENTA "SIGSEGV" COLOR_RESET;
    static const char sigabrt_sym[20]   = COLOR_MAGENTA "SIGABRT" COLOR_RESET;
    static const char sigfpe_sym[16]    = COLOR_MAGENTA "SIGFPE" COLOR_RESET;
    static const char sigill_sym[16]    = COLOR_MAGENTA "SIGILL" COLOR_RESET;
    static const char sigbus_sym[16]    = COLOR_MAGENTA "SIGBUS" COLOR_RESET;
    static const char sigchld_sym[20]   = COLOR_MAGENTA "SIGCHLD" COLOR_RESET;
    static const char sigpipe_sym[20]   = COLOR_MAGENTA "SIGPIPE" COLOR_RESET;
    static const char sigusr1_sym[20]   = COLOR_MAGENTA "SIGUSR1" COLOR_RESET;
    static const char sigusr2_sym[20]   = COLOR_MAGENTA "SIGUSR2" COLOR_RESET;
    static const char sigalrm_sym[20]   = COLOR_MAGENTA "SIGALRM" COLOR_RESET;
    static const char sigcont_sym[20]   = COLOR_MAGENTA "SIGCONT" COLOR_RESET;
    static const char sigstop_sym[20]   = COLOR_MAGENTA "SIGSTOP" COLOR_RESET;
    static const char sigtstp_sym[20]   = COLOR_MAGENTA "SIGTSTP" COLOR_RESET;
    static const char sigttin_sym[20]   = COLOR_MAGENTA "SIGTTIN" COLOR_RESET;
    static const char sigttou_sym[20]   = COLOR_MAGENTA "SIGTTOU" COLOR_RESET;
    static const char unknown_sym[20]   = COLOR_MAGENTA "UNKNOWN" COLOR_RESET;

    switch (signum)
    {
        case SIGINT:    return sigint_sym;
        case SIGTERM:   return sigterm_sym;
        case SIGSEGV:   return sigsegv_sym;
        case SIGABRT:   return sigabrt_sym;
        case SIGFPE:    return sigfpe_sym;
        case SIGILL:    return sigill_sym;
        case SIGBUS:    return sigbus_sym;
        case SIGCHLD:   return sigchld_sym;
        case SIGPIPE:   return sigpipe_sym;
        case SIGUSR1:   return sigusr1_sym;
        case SIGUSR2:   return sigusr2_sym;
        case SIGALRM:   return sigalrm_sym;
        case SIGCONT:   return sigcont_sym;
        case SIGSTOP:   return sigstop_sym;
        case SIGTSTP:   return sigtstp_sym;
        case SIGTTIN:   return sigttin_sym;
        case SIGTTOU:   return sigttou_sym;
        default:        return unknown_sym;
    }
}

}

}
