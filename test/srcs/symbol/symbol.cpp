#include "symbol/symbol.hpp"

#define COLOR_RESET     "\033[0m"
#define COLOR_BOLD      "\033[1m"
#define COLOR_BLACK     "\033[30m"
#define COLOR_RED       "\033[31m"
#define COLOR_GREEN     "\033[32m"
#define COLOR_YELLOW    "\033[33m"
#define COLOR_BLUE      "\033[34m"
#define COLOR_MAGENTA   "\033[35m"
#define COLOR_CYAN      "\033[36m"
#define COLOR_WHITE     "\033[37m"

namespace test
{

namespace symbol
{

const char* get_symbol(t_symbol symbol)
{
    static const char success_sym[] = COLOR_GREEN "success" COLOR_RESET;
    static const char fail_sym[] = COLOR_RED "fail" COLOR_RESET;
    static const char too_long_sym[] = COLOR_YELLOW "too long" COLOR_RESET;
    static const char unknown_sym[] = COLOR_CYAN "unknown" COLOR_RESET;

    switch (symbol)
    {
        case SUCCESS:
            return success_sym;
        case FAIL:
            return fail_sym;
        case TOO_LONG:
            return too_long_sym;
        default:
            return unknown_sym;
    }
}

}

}
