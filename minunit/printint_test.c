#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"

MU_TEST_SUITE(passing_the_flag_11_from_the_number_256_should_be_8_spaces_256)
{
    //CONFIG
    char            *file               = "./files/string/11flag";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 'i';
    shape->flags                        = ft_strdup("11");
    int             num                 = 256;
    char            *str_ret;
    char            *expected_result    = "        256";
    int             bsr;
    int             expected_bsr        = 11;

    //ACT
    bsr = printint(fd, num, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str_ret = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str_ret);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str_ret)
        free(str_ret);
}

MU_TEST_SUITE(passing_the_flag_minus_11_from_the_number_minus_256_should_be_minus_256_7_spaces)
{
    //CONFIG
    char            *file               = "./files/string/11flag";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 'i';
    shape->flags                        = ft_strdup("-11");
    int             num                 = -256;
    char            *str_ret;
    char            *expected_result    = "-256       ";
    int             bsr;
    int             expected_bsr        = 11;

    //ACT
    bsr = printint(fd, num, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str_ret = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str_ret);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str_ret)
        free(str_ret);
}

MU_TEST_SUITE(passing_the_flag_plus_11_from_the_number_256_should_be_minus_7_spaces_256)
{
    //CONFIG
    char            *file               = "./files/string/11flag";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 'i';
    shape->flags                        = ft_strdup("+11");
    int             num                 = 256;
    char            *str_ret;
    char            *expected_result    = "       +256";
    int             bsr;
    int             expected_bsr        = 11;

    //ACT
    bsr = printint(fd, num, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str_ret = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str_ret);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str_ret)
        free(str_ret);
}

MU_TEST_SUITE(passing_the_flag_3_plus_3_minus_11_from_the_number_256_should_be_plus_256_7_spaces)
{
    //CONFIG
    char            *file               = "./files/string/11flag-reverse";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 'i';
    shape->flags                        = ft_strdup("+-+-11");
    int             num                 = 256;
    char            *str_ret;
    char            *expected_result    = "+256       ";
    int             bsr;
    int             expected_bsr        = 11;

    //ACT
    bsr = printint(fd, num, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str_ret = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str_ret);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str_ret)
        free(str_ret);
}

MU_TEST_SUITE(passing_the_flag_3_plus_3_0_11_from_the_number_256_should_be_plus_7_0_256)
{
    //CONFIG
    char            *file               = "./files/string/11flag-reverse";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 'i';
    shape->flags                        = ft_strdup("+011");
    int             num                 = 256;
    char            *str_ret;
    char            *expected_result    = "+0000000256";
    int             bsr;
    int             expected_bsr        = 11;

    //ACT
    bsr = printint(fd, num, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str_ret = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str_ret);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str_ret)
        free(str_ret);
}

MU_TEST_SUITE(passing_the_flag_0_4_from_the_number_9_should_be_0009)
{
    //CONFIG
    char            *file               = "./files/string/04d";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 'd';
    shape->flags                        = ft_strdup("04");
    int             num                 = 9;
    char            *str_ret;
    char            *expected_result    = "0009";
    int             bsr;
    int             expected_bsr        = 4;

    //ACT
    bsr = printint(fd, num, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str_ret = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str_ret);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str_ret)
        free(str_ret);
}

MU_TEST_SUITE(passing_the_flag_0_4_dot_2_from_the_number_9_should_be_2_spaces_09)
{
    //CONFIG
    char            *file               = "./files/string/04d";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 'd';
    shape->flags                        = ft_strdup("04.2");
    int             num                 = 9;
    char            *str_ret;
    char            *expected_result    = "  09";
    int             bsr;
    int             expected_bsr        = 4;

    //ACT
    bsr = printint(fd, num, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str_ret = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str_ret);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str_ret)
        free(str_ret);
}


MU_TEST_SUITE(passing_the_flag_dot_2_from_the_number_minus_1_should_be_minus_01)
{
    //CONFIG
    char            *file               = "./files/string/04d";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 'd';
    shape->flags                        = ft_strdup(".2");
    int             num                 = -1;
    char            *str_ret;
    char            *expected_result    = "-01";
    int             bsr;
    int             expected_bsr        = 3;

    //ACT
    bsr = printint(fd, num, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str_ret = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str_ret);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str_ret)
        free(str_ret);
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
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
