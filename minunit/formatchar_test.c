#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"
#include <stdio.h>

MU_TEST_SUITE(test_passing_the_flag_55_and_the_char_C)
{
    //ARRANGE
    t_typechar      *format;
    char            *flags      = "55";
    char            c           = 'C';
    t_bool          minus       = f;
    int             bytes       = 55;
    int             valid_bytes = 2;

    //ACT
    format = formatchar(c, flags);

    //ASSERTS
    mu_assert_int_eq(c, format->value);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
}

MU_TEST_SUITE(test_passing_nothing_in_the_flag_and_the_char_D)
{
    //ARRANGE
    t_typechar      *format;
    char            *flags      = "";
    char            c           = 'D';
    t_bool          minus       = f;
    int             bytes       = 0;
    int             valid_bytes = 0;

    //ACT
    format = formatchar(c, flags);

    //ASSERTS
    mu_assert_int_eq(c, format->value);
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
}

MU_TEST_SUITE(test_passing_invalid_flag_yjkw_and_a_char_Y)
{
    //ARRANGE
    t_typechar      *format;
    char            *flags      = "yjkw";
    char            c           = 'Y';
    t_bool          minus       = f;
    int             bytes       = 0;
    int             valid_bytes = 0;

    //ACT
    format = formatchar(c, flags);

    //ASSERTS
    mu_assert_int_eq(c, format->value);
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
}

MU_TEST_SUITE(test_passing_the_flag_minus_7_and_a_char_Z)
{
    //ARRANGE
    t_typechar      *format;
    char            *flags      = "-7";
    char            c           = 'Z';
    t_bool          minus       = t;
    int             bytes       = 7;
    int             valid_bytes = 2;

    //ACT
    format = formatchar(c, flags);

    //ASSERTS
    mu_assert_int_eq(c, format->value);
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
}

MU_TEST_SUITE(test_passing_the_flag_3_minus_7_and_a_char_Z)
{
    //ARRANGE
    t_typechar      *format;
    char            *flags      = "---7";
    char            c           = 'Z';
    t_bool          minus       = t;
    int             bytes       = 7;
    int             valid_bytes = 4;

    //ACT
    format = formatchar(c, flags);

    //ASSERTS
    mu_assert_int_eq(c, format->value);
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_passing_the_flag_55_and_the_char_C);
    MU_RUN_TEST(test_passing_nothing_in_the_flag_and_the_char_D);
    MU_RUN_TEST(test_passing_invalid_flag_yjkw_and_a_char_Y);
    MU_RUN_TEST(test_passing_the_flag_minus_7_and_a_char_Z);
    MU_RUN_TEST(test_passing_the_flag_3_minus_7_and_a_char_Z);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
