#ifndef __TESTER_HPP__
#define __TESTER_HPP__
#include "../utils/utils.hpp"

namespace test
{

namespace cases
{

constexpr time_t max_time = 3;  // second

void    ft_strlen_test(const char* path);
void    ft_strlen_signal(int signum);

}

}

#endif
