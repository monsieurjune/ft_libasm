#ifndef __UTILS_HPP__
#define __UTILS_HPP__
#include <deque>
#include <string>

namespace test
{

namespace utils
{

std::deque<std::pair<std::string, std::string>>    get_test_cases(const char* dir);

}

}


#endif
