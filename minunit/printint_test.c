#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"

MU_TEST_SUITE(passing_the_flag_11_from_the_number_256_should_be_8_spaces_256)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/11flag";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 256;
    char            *expected_result    = "        256";
    int             expected_bsr        = 11;
    shape->type                         = 'i';
    shape->flags                        = ft_strdup("11");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_minus_11_from_the_number_minus_256_should_be_minus_256_7_spaces)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/minus11flag";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 256;
    char            *expected_result    = "256        ";
    int             expected_bsr        = 11;
    shape->type                         = 'i';
    shape->flags                        = ft_strdup("-11");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_plus_11_from_the_number_256_should_be_minus_7_spaces_256)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/plus11flag";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 256;
    char            *expected_result    = "       +256";
    int             expected_bsr        = 11;
    shape->type                         = 'i';
    shape->flags                        = ft_strdup("+11");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_3_plus_3_minus_11_from_the_number_256_should_be_plus_256_7_spaces)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/3plus11flag";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 256;
    char            *expected_result    = "+256       ";
    int             expected_bsr        = 11;
    shape->type                         = 'i';
    shape->flags                        = ft_strdup("+-+-11");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_3_plus_3_0_11_from_the_number_256_should_be_plus_7_0_256)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/3plus11flag";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 256;
    char            *expected_result    = "+0000000256";
    int             expected_bsr        = 11;
    shape->type                         = 'i';
    shape->flags                        = ft_strdup("+011");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_0_4_from_the_number_9_should_be_0009)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/04d";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 9;
    char            *expected_result    = "0009";
    int             expected_bsr        = 4;
    shape->type                         = 'i';
    shape->flags                        = ft_strdup("04");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_0_4_dot_2_from_the_number_9_should_be_2_spaces_09)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/04ddot2";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 9;
    char            *expected_result    = "  09";
    int             expected_bsr        = 4;
    shape->type                         = 'i';
    shape->flags                        = ft_strdup("04.2");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_dot_2_from_the_number_minus_1_should_be_minus_01)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/dot2";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = -1;
    char            *expected_result    = "-01";
    int             expected_bsr        = 3;
    shape->type                         = 'i';
    shape->flags                        = ft_strdup(".2");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_dot_1_from_the_number_0_should_be_0)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/dot2";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 0;
    char            *expected_result    = "0";
    int             expected_bsr        = 1;
    shape->type                         = 'i';
    shape->flags                        = ft_strdup(".1");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}


MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(passing_the_flag_11_from_the_number_256_should_be_8_spaces_256);
    MU_RUN_TEST(passing_the_flag_minus_11_from_the_number_minus_256_should_be_minus_256_7_spaces);
    MU_RUN_TEST(passing_the_flag_plus_11_from_the_number_256_should_be_minus_7_spaces_256);
    MU_RUN_TEST(passing_the_flag_3_plus_3_minus_11_from_the_number_256_should_be_plus_256_7_spaces);
    MU_RUN_TEST(passing_the_flag_3_plus_3_0_11_from_the_number_256_should_be_plus_7_0_256);
    MU_RUN_TEST(passing_the_flag_0_4_from_the_number_9_should_be_0009);
    MU_RUN_TEST(passing_the_flag_0_4_dot_2_from_the_number_9_should_be_2_spaces_09);
    MU_RUN_TEST(passing_the_flag_dot_2_from_the_number_minus_1_should_be_minus_01);
    MU_RUN_TEST(passing_the_flag_dot_1_from_the_number_0_should_be_0);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
