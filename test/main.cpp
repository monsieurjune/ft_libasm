#include "srcs/tester.hpp"
#include "utils/utils.hpp"

int main()
{
    if (test::utils::signal_init())
    {
        return 1;
    }

    test::cases::ft_strlen_test("cases/ft_strlen");

    return 0;
}