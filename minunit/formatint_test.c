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

MU_TEST_SUITE(test_passing_a_flag_0_10_with_the_number_256_for_the_formatint)
{
    //ARRANGE
    t_typeint      *format;
    char            *flags      = "010";
    int             sendnum     = 256;
    //COMPARE VARS
    int             num         = 256;
    t_bool          zero        = t;
    char            signal      = '+';
    t_bool          minus       = f;
    int             bytes       = 10;
    t_bool          dot         = f;
    int             bytes_s     = 0;
    int             valid_bytes = 3;

    //ACT
    format = formatint(sendnum, flags);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(signal == format->signal, "Signal Error");
    mu_assert(zero == format->fzero, "Zero flag Error");
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_minus_space_10_with_the_number_256_for_the_formatint)
{
    //ARRANGE
    t_typeint      *format;
    char            *flags      = "- 10";
    int             sendnum     = 256;
    //COMPARE VARS
    int             num         = 256;
    t_bool          space       = t;
    t_bool          zero        = f;
    char            signal      = '+';
    t_bool          minus       = t;
    int             bytes       = 10;
    t_bool          dot         = f;
    int             bytes_s     = 0;
    int             valid_bytes = 4;

    //ACT
    format = formatint(sendnum, flags);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(signal == format->signal, "Signal Error");
    mu_assert(space == format->space, "Space Error");
    mu_assert(zero == format->fzero, "Zero flag Error");
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_3_space_3_minus_10_with_the_number_256_for_the_formatint)
{
    //ARRANGE
    t_typeint      *format;
    char            *flags      = " - - -10";
    int             sendnum     = 256;
    //COMPARE VARS
    int             num         = 256;
    t_bool          space       = t;
    t_bool          zero        = f;
    char            signal      = '+';
    t_bool          minus       = t;
    int             bytes       = 10;
    t_bool          dot         = f;
    int             bytes_s     = 0;
    int             valid_bytes = 8;

    //ACT
    format = formatint(sendnum, flags);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(signal == format->signal, "Signal Error");
    mu_assert(space == format->space, "Space Error");
    mu_assert(zero == format->fzero, "Zero flag Error");
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_3_plus_3_minus_10_with_the_number_256_for_the_formatint)
{
    //ARRANGE
    t_typeint      *format;
    char            *flags      = "-+-+-+10";
    int             sendnum     = 256;
    //COMPARE VARS
    int             num         = 256;
    t_bool          plus        = t;
    t_bool          space       = f;
    t_bool          zero        = f;
    char            signal      = '+';
    t_bool          minus       = t;
    int             bytes       = 10;
    t_bool          dot         = f;
    int             bytes_s     = 0;
    int             valid_bytes = 8;

    //ACT
    format = formatint(sendnum, flags);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(signal == format->signal, "Signal Error");
    mu_assert(plus == format->plus, "Plus Error");
    mu_assert(space == format->space, "Space Error");
    mu_assert(zero == format->fzero, "Zero flag Error");
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_3_plus_3_zeros_10_dot_5_with_the_number_256_for_the_formatint)
{
    //ARRANGE
    t_typeint      *format;
    char            *flags      = "0+0+0+10.5";
    int             sendnum     = 256;
    //COMPARE VARS
    int             num         = 256;
    t_bool          plus        = t;
    t_bool          space       = f;
    t_bool          zero        = t;
    char            signal      = '+';
    t_bool          minus       = f;
    int             bytes       = 10;
    t_bool          dot         = t;
    int             bytes_s     = 5;
    int             valid_bytes = 10;

    //ACT
    format = formatint(sendnum, flags);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(signal == format->signal, "Signal Error");
    mu_assert(plus == format->plus, "Plus Error");
    mu_assert(space == format->space, "Space Error");
    mu_assert(zero == format->fzero, "Zero flag Error");
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_3_spaces_3_zeros_10_dot_5_with_the_number_minus_256_for_the_formatint)
{
    //ARRANGE
    t_typeint      *format;
    char            *flags      = "0 0 0 10.5";
    int             sendnum     = -256;
    //COMPARE VARS
    int             num         = 256;
    t_bool          plus        = f;
    t_bool          space       = t;
    t_bool          zero        = t;
    char            signal      = '-';
    t_bool          minus       = f;
    int             bytes       = 10;
    t_bool          dot         = t;
    int             bytes_s     = 5;
    int             valid_bytes = 10;

    //ACT
    format = formatint(sendnum, flags);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(signal == format->signal, "Signal Error");
    mu_assert(plus == format->plus, "Plus Error");
    mu_assert(space == format->space, "Space Error");
    mu_assert(zero == format->fzero, "Zero flag Error");
    mu_assert(minus == format->minus, "Minus error!");
    mu_assert_int_eq(bytes, format->bytes);
    mu_assert(dot == format->dot, "Dot Error");
    mu_assert_int_eq(bytes_s, format->bytes_s);
    mu_assert_int_eq(valid_bytes, format->valid_bytes);
    if (format)
        free(format);
}

MU_TEST_SUITE(test_passing_a_flag_dot_2_with_the_number_minus_1_for_the_formatint)
{
    //ARRANGE
    t_typeint      *format;
    char            *flags      = ".2";
    int             sendnum     = -1;
    //COMPARE VARS
    int             num         = 1;
    t_bool          plus        = f;
    t_bool          space       = f;
    t_bool          zero        = f;
    char            signal      = '-';
    t_bool          minus       = f;
    int             bytes       = 0;
    t_bool          dot         = t;
    int             bytes_s     = 2;
    int             valid_bytes = 2;

    //ACT
    format = formatint(sendnum, flags);

    //ASSERTS
    mu_assert_int_eq(num, format->value);
    mu_assert(signal == format->signal, "Signal Error");
    mu_assert(plus == format->plus, "Plus Error");
    mu_assert(space == format->space, "Space Error");
    mu_assert(zero == format->fzero, "Zero flag Error");
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
    MU_RUN_TEST(test_passing_a_flag_0_10_with_the_number_256_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_minus_space_10_with_the_number_256_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_3_space_3_minus_10_with_the_number_256_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_3_plus_3_minus_10_with_the_number_256_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_3_plus_3_zeros_10_dot_5_with_the_number_256_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_3_spaces_3_zeros_10_dot_5_with_the_number_minus_256_for_the_formatint);
    MU_RUN_TEST(test_passing_a_flag_dot_2_with_the_number_minus_1_for_the_formatint);
    printf("\n'%s'\n", ft_itoa_base(5408, 16));
    printf("testetsetstete");
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
