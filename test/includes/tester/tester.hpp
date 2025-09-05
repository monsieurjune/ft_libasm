#ifndef __TESTER_HPP__
#define __TESTER_HPP__

namespace test
{

namespace cases
{

constexpr int max_time = 2;  // second

void    ft_strlen_test(const char* path);
void    ft_strlen_signal(int signum);

void    ft_strcpy_test(const char* path);
void    ft_strcpy_signal(int signum);

void    ft_strcmp_test(const char* path);
void    ft_strcmp_signal(int signum);

}

}

#endif
