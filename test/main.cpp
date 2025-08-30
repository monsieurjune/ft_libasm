#include "srcs/tester.hpp"
#include "utils/utils.hpp"
#include "logger/Logger.hpp"

#include <unistd.h>


int main()
{
    test::log::Logger   logger(NULL, "main");

    if (int ret = test::utils::signal_init())
    {
        switch (ret)
        {
            case 0:
                return ret;
            case 1:
                logger.log(logger.CRITICAL, "sigemptyset() is failed");
                return ret;
            case 2:
                logger.log(logger.CRITICAL, "sigaction() is failed");
                return ret;
            default:
                logger.log(logger.CRITICAL, "unknown signal error error");
                return ret;
        }
    }

    test::cases::ft_strlen_test("cases/ft_strlen");

    return 0;
}
