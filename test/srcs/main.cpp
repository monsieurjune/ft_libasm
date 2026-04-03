#include "tester/tester.hpp"
#include "utils/signal.hpp"

int main()
{
    if (!test::utils::signal_init())
    {
        return 1;
    }

    test::cases::ft_strlen_test("cases/rules/ft_strlen");
    test::cases::ft_strcpy_test("cases/rules/ft_strcpy");
    test::cases::ft_strcmp_test("cases/rules/ft_strcmp");

    return 0;
}
