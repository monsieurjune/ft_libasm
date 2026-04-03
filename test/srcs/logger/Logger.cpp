#include "logger/Logger.hpp"
#include "utils/color.hpp"

#include <ctime>

#include <iostream>
#include <fstream>
#include <sstream>

namespace test
{

namespace log
{

static inline const char*	sb_timestamp()
{
	static char         buffer[24];
	static std::time_t  now;
	static std::tm*	    tm_info;

	// Get format time
    std::time(&now);
    tm_info = std::localtime(&now);
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);

	return buffer;
}

static inline const char*	sb_color_level(Logger::t_loglevel level)
{
    static const char   debug_tag[8] = " DEBUG ";
    static const char   info_tag[16] = COLOR_GREEN " INFO " COLOR_RESET;
    static const char   warn_tag[16] = COLOR_YELLOW " WARN " COLOR_RESET;
    static const char   error_tag[16] = COLOR_MAGENTA " ERR " COLOR_RESET;
    static const char   critical_tag[16] = COLOR_RED " CRIT " COLOR_RESET;

	// Get color
	switch (level)
	{
		case Logger::DEBUG:
            return debug_tag;
		case Logger::INFO:
            return info_tag;
		case Logger::WARN:
            return warn_tag;
		case Logger::ERROR:
            return error_tag;
		case Logger::CRITICAL:
            return critical_tag;
		default:
            return debug_tag;
	}
}

Logger::Logger(const char *filename, std::string const& name) : _name(name)
{
    if (filename == NULL)
    {
        std::stringstream   ss;

        ss << "doesn't choose log file" << ", only output on stderr";
        this->log(Logger::WARN, ss.str());
        return;
    }

    _out.open(filename);
    if (!_out.is_open())
    {
        std::stringstream   ss;

        ss << "can't open log file: " << filename << ", only output on stderr";
        this->log(Logger::WARN, ss.str());
    }
}

Logger::~Logger()
{
    _out.close();
}

void    Logger::log(t_loglevel level, std::string const& msg)
{
    static const char*  tag;
    static const char*  time;
    std::stringstream   ss;

    // get info
    tag = sb_color_level(level);
    time = sb_timestamp();

    // create log
	ss << COLOR_CYAN << time << COLOR_RESET
        << tag
        << COLOR_BLUE << '[' << this->_name << ']' << COLOR_RESET 
        << ": " << msg;

    // print out
    std::cerr << ss.str() << std::endl;

    // write on log file, if it is writable
    if (this->_out.good())
    {
        this->_out << ss.str() << std::endl;
    }
}

}

}
