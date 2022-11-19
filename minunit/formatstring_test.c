#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"
#include <stdio.h>

MU_TEST_SUITE(test_passing_55_dot_10_int_the_flags)
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

MU_TEST_SUITE(test_passing_55_in_the_flags)
{
    //ARRANGE
    t_typestring    *format;
    char            *flags      = "55";
    char            *str        = "chocolate";
    int             bytes       = 55;
    t_bool          dot         = FALSE;
    int             bytes_s     = 0;
    int             valid_bytes = 2;

    //ACT
    format = formatstring(str, flags);

    //ASSERTS
    mu_assert_string_eq(str, format->value);
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot error!");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
}

MU_TEST_SUITE(test_passing_dot_5_in_the_flags)
{
    //ARRANGE
    t_typestring    *format;
    char            *flags      = ".5";
    char            *str        = "chocolate";
    int             bytes       = 0;
    t_bool          dot         = TRUE;
    int             bytes_s     = 5;
    int             valid_bytes = 2;

    //ACT
    format = formatstring(str, flags);

    //ASSERTS
    mu_assert_string_eq(str, format->value);
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot error!");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
}

MU_TEST_SUITE(test_passing_nothing_int_the_flags)
{
    //ARRANGE
    t_typestring    *format;
    char            *flags      = "";
    char            *str        = "chocolate";
    int             bytes       = 0;
    t_bool          dot         = FALSE;
    int             bytes_s     = 0;
    int             valid_bytes = 0;

    //ACT
    format = formatstring(str, flags);

    //ASSERTS
    mu_assert_string_eq(str, format->value);
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot error!");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
}

MU_TEST_SUITE(test_passing_yjkw_int_the_flags)
{
    //ARRANGE
    t_typestring    *format;
    char            *flags      = "yjkw";
    char            *str        = "chocolate";
    int             bytes       = 0;
    t_bool          dot         = FALSE;
    int             bytes_s     = 0;
    int             valid_bytes = 0;

    //ACT
    format = formatstring(str, flags);

    //ASSERTS
    mu_assert_string_eq(str, format->value);
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot error!");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
}

MU_TEST_SUITE(test_passing_minus_5_dot_7_int_the_flags)
{
    //ARRANGE
    t_typestring    *format;
    char            *flags      = "-5.7";
    char            *str        = "chocolate";
    t_bool          minus       = TRUE;
    int             bytes       = 5;
    t_bool          dot         = TRUE;
    int             bytes_s     = 7;
    int             valid_bytes = 4;

    //ACT
    format = formatstring(str, flags);

    //ASSERTS
    mu_assert_string_eq(str, format->value);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot error!");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
}

MU_TEST_SUITE(test_passing_multiples_minus_5_dot_7_int_the_flags)
{
    //ARRANGE
    t_typestring    *format;
    char            *flags      = "---5.7";
    char            *str        = "chocolate";
    t_bool          minus       = TRUE;
    int             bytes       = 5;
    t_bool          dot         = TRUE;
    int             bytes_s     = 7;
    int             valid_bytes = 6;

    //ACT
    format = formatstring(str, flags);

    //ASSERTS
    mu_assert_string_eq(str, format->value);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot error!");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_passing_55_dot_10_int_the_flags);
    MU_RUN_TEST(test_passing_55_in_the_flags);
    MU_RUN_TEST(test_passing_dot_5_in_the_flags);
    MU_RUN_TEST(test_passing_nothing_int_the_flags);
    MU_RUN_TEST(test_passing_yjkw_int_the_flags);
    MU_RUN_TEST(test_passing_minus_5_dot_7_int_the_flags);
    MU_RUN_TEST(test_passing_multiples_minus_5_dot_7_int_the_flags);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

/*
( - ) -> alinha á direita
( 5 ) -> quantidade de bytes á se apresentar
( .5 ) -> quantidades de bytes a string a se apresentar
*/