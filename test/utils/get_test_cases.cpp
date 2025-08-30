#include "utils.hpp"

#include <fstream>
#include <filesystem>
#include <exception>
#include <deque>
#include <utility>
#include <algorithm>
#include <sstream>
#include <string>
#include <iostream>

namespace test
{

namespace utils
{

std::deque<std::pair<std::string, std::string>>    get_test_cases(const char* dir)
{
    std::filesystem::path                               dir_path(dir);
    std::deque<std::pair<std::string, std::string> >    str_deque;

    try
    {
        for (auto const& entry : std::filesystem::recursive_directory_iterator(dir_path))
        {
            // check if file is normal file
            if (!entry.is_regular_file())
            {
                continue;
            }

            // open file
            std::ifstream   file(entry.path().c_str());

            if (!file.is_open())
            {
                continue;
            }

            // read file
            std::stringstream   buff;

            buff << file.rdbuf();
            if (!buff.bad())
            {
                str_deque.push_front(
                    std::make_pair<std::string, std::string>(
                        entry.path().filename().string(), buff.str()
                    )
                );
            }

            file.close();
        }
    }
    catch (std::filesystem::filesystem_error const& e)
    {
    }

    // sort pair to make it lexically
    std::sort(str_deque.begin(), str_deque.end());

    return str_deque;
}

}

}
