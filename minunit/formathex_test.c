#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"
#include <stdio.h>

MU_TEST_SUITE(test_passing_a_flag_5_with_the_number_5608_for_the_formatint)
{
    //ARRANGE
    t_typehex      *format;
    char            *flags      = "5";
    int             num         = 5608;
    t_bool          minus       = f;
    t_bool          hash        = f;
    t_bool          fzero       = f;
    int             bytes       = 5;
    t_bool          dot         = f;
    int             bytes_s     = 0;
    int             valid_bytes = 1;
    char            caset       = 'x';

    //ACT
    format = formathex(num, flags, caset);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert(hash == format->hash, "Hashtag Error!");
    mu_assert(fzero == format->fzero, "Flag Zero Error");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_minus_10_with_the_number_5608_for_the_formatint)
{
    //ARRANGE
    t_typehex      *format;
    char            *flags      = "-10";
    int             num         = 5608;
    t_bool          minus       = t;
    t_bool          hash        = f;
    t_bool          fzero       = f;
    int             bytes       = 10;
    t_bool          dot         = f;
    int             bytes_s     = 0;
    int             valid_bytes = 3;
    char            caset       = 'X';

    //ACT
    format = formathex(num, flags, caset);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert(hash == format->hash, "Hashtag Error!");
    mu_assert(fzero == format->fzero, "Flag Zero Error");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_minus_10_dot_5_with_the_number_5608_for_the_formatint)
{
    //ARRANGE
    t_typehex      *format;
    char            *flags      = "-10.5";
    int             num         = 5608;
    t_bool          minus       = t;
    t_bool          hash        = f;
    t_bool          fzero       = f;
    int             bytes       = 10;
    t_bool          dot         = t;
    int             bytes_s     = 5;
    int             valid_bytes = 5;
    char            caset       = 'x';

    //ACT
    format = formathex(num, flags, caset);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert(hash == format->hash, "Hashtag Error!");
    mu_assert(fzero == format->fzero, "Flag Zero Error");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_dot_10_with_the_number_5608_for_the_formatint)
{
    //ARRANGE
    t_typehex      *format;
    char            *flags      = ".10";
    int             num         = 5608;
    t_bool          minus       = f;
    t_bool          hash        = f;
    t_bool          fzero       = f;
    int             bytes       = 0;
    t_bool          dot         = t;
    int             bytes_s     = 10;
    int             valid_bytes = 3;

    //ACT
    format = formathex(num, flags, 'X');

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert(hash == format->hash, "Hashtag Error!");
    mu_assert(fzero == format->fzero, "Flag Zero Error");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_hashtag_dot_10_with_the_number_5608_for_the_formatint)
{
    //ARRANGE
    t_typehex      *format;
    char            *flags      = "#.10";
    int             num         = 5608;
    t_bool          minus       = f;
    t_bool          hash        = t;
    t_bool          fzero       = f;
    int             bytes       = 0;
    t_bool          dot         = t;
    int             bytes_s     = 10;
    int             valid_bytes = 4;

    //ACT
    format = formathex(num, flags, 'x');

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert(hash == format->hash, "Hashtag Error!");
    mu_assert(fzero == format->fzero, "Flag Zero Error");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_3_hashtag_3_minus_10_dot_10_with_the_number_5608_for_the_formatint)
{
    //ARRANGE
    t_typehex      *format;
    char            *flags      = "#-#-#-10.10";
    int             num         = 5608;
    t_bool          minus       = t;
    t_bool          hash        = t;
    t_bool          fzero       = f;
    int             bytes       = 10;
    t_bool          dot         = t;
    int             bytes_s     = 10;
    int             valid_bytes = 11;

    //ACT
    format = formathex(num, flags, 'X');

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert(hash == format->hash, "Hashtag Error!");
    mu_assert(fzero == format->fzero, "Flag Zero Error");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_3_zero_3_minus_20_dot_10_with_the_number_5608_for_the_formatint)
{
    //ARRANGE
    t_typehex      *format;
    char            *flags      = "#0#0#020.10";
    int             num         = 5608;
    t_bool          minus       = f;
    t_bool          hash        = t;
    t_bool          fzero       = t;
    int             bytes       = 20;
    t_bool          dot         = t;
    int             bytes_s     = 10;
    int             valid_bytes = 11;

    //ACT
    format = formathex(num, flags, 'x');

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert(hash == format->hash, "Hashtag Error!");
    mu_assert(fzero == format->fzero, "Flag Zero Error");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_passing_a_flag_5_with_the_number_5608_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_minus_10_with_the_number_5608_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_minus_10_dot_5_with_the_number_5608_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_dot_10_with_the_number_5608_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_hashtag_dot_10_with_the_number_5608_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_3_hashtag_3_minus_10_dot_10_with_the_number_5608_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_3_zero_3_minus_20_dot_10_with_the_number_5608_for_the_formatint);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

/*
Categorias:
    minus ( # )
    zero  ( 0 )
    point ( . )
    space ( - )
*/
