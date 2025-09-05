#ifndef __UTILS_HPP__
#define __UTILS_HPP__
#include "logger/Logger.hpp"

#include <deque>
#include <vector>
#include <string>

namespace test
{

namespace utils
{

using t_cases = std::deque<std::pair<std::string, std::vector<std::string> > >;

typedef enum e_loglevel
{
    DEBUG,
    INFO,
    WARN,
    ERROR,
    CRITICAL
}   t_loglevel;

int signal_init();

t_cases    get_test_cases(const char* dir);

void    parent_wait(test::log::Logger& logger, const char* case_name, pid_t pid, int max_time);

}

}

#endif
