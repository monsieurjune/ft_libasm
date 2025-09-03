#ifndef __SYMBOL_HPP__
#define __SYMBOL_HPP__

namespace test
{

namespace symbol
{

typedef enum e_symbol
{
    SUCCESS,
    FAIL,
    TOO_LONG,
    UNKNOWN
}   t_symbol;

const char* get_symbol(t_symbol symbol);
const char* get_signal_name(int signum);

}

}

#endif
