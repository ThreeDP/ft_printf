#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"

MU_TEST_SUITE(test)
{
    //ARRANGE
    t_typestring    *format;
    char            *flags      = "55.10";
    char            *str        = "chocolate";
    int             bytes       = 55;
    t_bool          dot         = TRUE;
    int             bytes_s     = 10;
    int             valid_bytes = 5;

    //ACT
    format = formatstring(str, flags);

    //ASSERTS
    mu_assert_string_eq(str, format->value);
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot error!");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}