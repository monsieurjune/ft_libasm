#include "symbol/symbol.hpp"
#include "utils/color.hpp"

namespace test
{

namespace symbol
{

const char* get_symbol(t_symbol symbol)
{
    static const char success_sym[20]      = COLOR_GREEN "success" COLOR_RESET;
    static const char retval_fail_sym[24]  = COLOR_RED "retval fail" COLOR_RESET;
    static const char content_fail_sym[24] = COLOR_RED "content fail" COLOR_RESET;
    static const char errno_fail_sym[20]   = COLOR_RED "errno fail" COLOR_RESET;
    static const char too_long_sym[20]     = COLOR_YELLOW  "too long" COLOR_RESET;
    static const char mem_error_sym[16]    = COLOR_BLUE "memory" COLOR_RESET;
    static const char unknown_sym[20]      = COLOR_CYAN "unknown" COLOR_RESET;

    switch (symbol)
    {
        case SUCCESS:
            return success_sym;
        case RETVAL_FAIL:
            return retval_fail_sym;
        case CONTENT_FAIL:
            return content_fail_sym;
        case ERRNO_FAIL:
            return errno_fail_sym;
        case TOO_LONG:
            return too_long_sym;
        case MEM_ERROR:
            return mem_error_sym;
        case UNKNOWN:
        default:
            return unknown_sym;
    }
}

}

}
