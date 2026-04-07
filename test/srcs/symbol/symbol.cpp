#include "symbol/symbol.hpp"
#include "utils/color.hpp"

namespace test
{

namespace symbol
{

struct __attribute__((aligned(64))) s_status_symbol {
    char success_sym[20];
    char retval_fail_sym[24];
    char content_fail_sym[24];
    char errno_fail_sym[20];
    char file_error_sym[20];
    char too_long_sym[20];
    char mem_error_sym[16];
    char unknown_sym[20];
};

const char* get_symbol(t_symbol symbol)
{
    static const struct s_status_symbol box = {
        .success_sym      = COLOR_GREEN "success" COLOR_RESET,
        .retval_fail_sym  = COLOR_RED "retval fail" COLOR_RESET,
        .content_fail_sym = COLOR_RED "content fail" COLOR_RESET,
        .errno_fail_sym   = COLOR_RED "errno fail" COLOR_RESET,
        .file_error_sym   = COLOR_RED "open fail" COLOR_RESET,
        .too_long_sym     = COLOR_YELLOW "too long" COLOR_RESET,
        .mem_error_sym    = COLOR_BLUE "memory" COLOR_RESET,
        .unknown_sym      = COLOR_CYAN "unknown" COLOR_RESET,
    };

    switch (symbol)
    {
        case SUCCESS:       return box.success_sym;
        case RETVAL_FAIL:   return box.retval_fail_sym;
        case CONTENT_FAIL:  return box.content_fail_sym;
        case ERRNO_FAIL:    return box.errno_fail_sym;
        case OPEN_FAIL:     return box.file_error_sym;
        case TOO_LONG:      return box.too_long_sym;
        case MEM_ERROR:     return box.mem_error_sym;
        case UNKNOWN:
        default:            return box.unknown_sym;
    }
}

}

}
