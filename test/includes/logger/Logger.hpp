#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include <string>
#include <fstream>

namespace test
{

namespace log
{

/**
 * 
 */
class Logger
{
    private:
        /**
         * 
         */
        std::ofstream       _out;

        /**
         * 
         */
        std::string const   _name;

    public:
        /**
         * 
         */
        typedef enum e_loglevel
        {
            DEBUG,
            INFO,
            WARN,
            ERROR,
            CRITICAL
        }   t_loglevel;

        /**
         * 
         */
        Logger(const char *filename, std::string const& name);

        /**
         * 
         */
        ~Logger();

        /**
         * 
         */
        void    log(t_loglevel level, std::string const& msg);
};

}

}

#endif
