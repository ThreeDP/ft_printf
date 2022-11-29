#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"
#include <stdio.h>

MU_TEST_SUITE(test_passing_a_flag_55_with_the_number_7_for_the_formatint)
{
    //ARRANGE
    t_typeint      *format;
    char            *flags      = "55";
    char            signal      = '+';
    int             num         = 7;
    t_bool          minus       = f;
    int             bytes       = 55;
    t_bool          dot         = f;
    int             bytes_s     = 0;
    int             valid_bytes = 2;

    //ACT
    format = formatint(num, flags);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(signal == format->signal, "Signal Error");
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_minus_55_dot_10_with_the_number_256_for_the_formatint)
{
    //ARRANGE
    t_typeint      *format;
    char            *flags      = "-55.10";
    //COMPARE VARS
    int             num         = 256;
    char            signal      = '+';
    t_bool          minus       = t;
    int             bytes       = 55;
    t_bool          dot         = t;
    int             bytes_s     = 10;
    int             valid_bytes = 6;

    //ACT
    format = formatint(num, flags);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(signal == format->signal, "Signal Error");
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_minus_55_dot_10_with_the_number_minus_256_for_the_formatint)
{
    //ARRANGE
    t_typeint      *format;
    char            *flags      = "-55.10";
    int             sendnum     =   -256;
    //COMPARE VARS
    int             num         = 256;
    char            signal      = '-';
    t_bool          minus       = t;
    int             bytes       = 55;
    t_bool          dot         = t;
    int             bytes_s     = 10;
    int             valid_bytes = 6;

    //ACT
    format = formatint(sendnum, flags);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(signal == format->signal, "Signal Error");
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_passing_a_flag_55_with_the_number_7_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_minus_55_dot_10_with_the_number_256_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_minus_55_dot_10_with_the_number_minus_256_for_the_formatint);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}


/*
Categorias:
    minus ( - )
    zero  ( 0 )
    point ( . )
    space (   )
    plus  ( + )
*/