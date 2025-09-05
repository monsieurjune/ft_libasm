#include "symbol/symbol.hpp"
#include "utils/color.hpp"

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
