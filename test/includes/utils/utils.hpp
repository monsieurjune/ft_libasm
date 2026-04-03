#ifndef __UTILS_HPP__
#define __UTILS_HPP__
#include "logger/Logger.hpp"

#include <deque>
#include <vector>
#include <string>

namespace test
{

namespace log
{

class Logger;

}

namespace utils
{

using t_cases = std::deque<std::pair<std::string, std::vector<std::string> > >;

/**
 * 
 */
t_cases    get_test_cases(const char* dir);

/**
 * 
 */
void    parent_wait(test::log::Logger* logger, const char* case_name, pid_t pid, int max_time);

}

}

#endif
