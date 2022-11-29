#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"

MU_TEST_SUITE(passing_a_11_flag_for_the_string_One_Ring_and_return_three_spaces_One_Ring)
{
    //CONFIG
    char            *file               = "./files/string/one-ring";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 's';
    shape->flags                        = ft_strdup("11");
    char            *str                = "One Ring";
    char            *expected_result    = "   One Ring";
    int             bsr;
    int             expected_bsr        = 11;

    //ACT
    bsr = printstring(fd, str, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str)
        free(str);
}

MU_TEST_SUITE(passing_a_minus_11_flag_for_the_string_One_Ring_and_return_One_Ring_three_spaces)
{
    //CONFIG
    char            *file               = "./files/string/one-ring-reverse";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 's';
    shape->flags                        = ft_strdup("-11");
    char            *str                = "One Ring";
    char            *expected_result    = "One Ring   ";
    int             bsr;
    int             expected_bsr        = 11;

    //ACT
    bsr = printstring(fd, str, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str)
        free(str);
}

MU_TEST_SUITE(passing_a_flag_11_dot_3_and_a_string_One_Ring_should_be_8_spaces_One)
{
    //CONFIG
    char            *file               = "./files/string/one";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 's';
    shape->flags                        = ft_strdup("11.3");
    char            *str                = "One Ring";
    char            *expected_result    = "        One";
    int             bsr;
    int             expected_bsr        = 11;

    //ACT
    bsr = printstring(fd, str, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str)
        free(str);
}

MU_TEST_SUITE(passing_a_flag_4_dot_5_and_a_string_One_Ring_should_be_One_R)
{
    //CONFIG
    char            *file               = "./files/string/4dot5";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 's';
    shape->flags                        = ft_strdup("4.5");
    char            *str                = "One Ring";
    char            *expected_result    = "One R";
    int             bsr;
    int             expected_bsr        = 5;

    //ACT
    bsr = printstring(fd, str, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str)
        free(str);
}

MU_TEST_SUITE(passing_a_flag_5_dot_2_and_a_string_One_Ring_should_be_On)
{
    //CONFIG
    char            *file               = "./files/string/5dot2";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 's';
    shape->flags                        = ft_strdup("5.2");
    char            *str                = "One Ring";
    char            *expected_result    = "   On";
    int             bsr;
    int             expected_bsr        = 5;

    //ACT
    bsr = printstring(fd, str, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str)
        free(str);
}

MU_TEST_SUITE(passing_a_flag_3_dot_0_and_a_string_One_Ring_should_be_3_spaces)
{
    //CONFIG
    char            *file               = "./files/string/3dot0";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 's';
    shape->flags                        = ft_strdup("3.0");
    char            *str                = "One Ring";
    char            *expected_result    = "   ";
    int             bsr;
    int             expected_bsr        = 3;

    //ACT
    bsr = printstring(fd, str, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str)
        free(str);
}

MU_TEST_SUITE(passing_a_flag_minus_30_dot_20_and_a_string_One_Ring_should_be_3_spaces)
{
    //CONFIG
    char            *file               = "./files/string/minus30dot20";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 's';
    shape->flags                        = ft_strdup("-30.20");
    char            *str                = "One Ring";
    char            *expected_result    = "One Ring                      ";
    int             bsr;
    int             expected_bsr        = 30;

    //ACT
    bsr = printstring(fd, str, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str)
        free(str);
}

MU_TEST_SUITE(passing_a_flag_6_minus_30_dot_20_and_a_string_One_Ring_should_be_3_spaces)
{
    //CONFIG
    char            *file               = "./files/string/sixminus30dot20";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 's';
    shape->flags                        = ft_strdup("------30.20");
    char            *str                = "One Ring";
    char            *expected_result    = "One Ring                      ";
    int             bsr;
    int             expected_bsr        = 30;

    //ACT
    bsr = printstring(fd, str, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str)
        free(str);
}

MU_TEST_SUITE(passing_a_flag_1_and_a_empty_string_should_be_space)
{
    //CONFIG
    char            *file               = "./files/string/space1";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 's';
    shape->flags                        = ft_strdup("1");
    char            *str                = "";
    char            *expected_result    = " ";
    int             bsr;
    int             expected_bsr        = 1;

    //ACT
    bsr = printstring(fd, str, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str)
        free(str);
}

MU_TEST_SUITE(passing_a_flag_1_and_a_NULL_string_should_be_printf_null)
{
    //CONFIG
    char            *file               = "./files/string/null";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 's';
    shape->flags                        = ft_strdup("1");
    char            *str                = NULL;
    char            *expected_result    = "(null)";
    int             bsr;
    int             expected_bsr        = 6;

    //ACT
    bsr = printstring(fd, str, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (str)
        free(str);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(passing_a_11_flag_for_the_string_One_Ring_and_return_three_spaces_One_Ring);
    MU_RUN_TEST(passing_a_minus_11_flag_for_the_string_One_Ring_and_return_One_Ring_three_spaces);
    MU_RUN_TEST(passing_a_flag_11_dot_3_and_a_string_One_Ring_should_be_8_spaces_One);
    MU_RUN_TEST(passing_a_flag_4_dot_5_and_a_string_One_Ring_should_be_One_R);
    MU_RUN_TEST(passing_a_flag_5_dot_2_and_a_string_One_Ring_should_be_On);
    MU_RUN_TEST(passing_a_flag_3_dot_0_and_a_string_One_Ring_should_be_3_spaces);
    MU_RUN_TEST(passing_a_flag_minus_30_dot_20_and_a_string_One_Ring_should_be_3_spaces);
    MU_RUN_TEST(passing_a_flag_6_minus_30_dot_20_and_a_string_One_Ring_should_be_3_spaces);
    MU_RUN_TEST(passing_a_flag_1_and_a_empty_string_should_be_space);
    MU_RUN_TEST(passing_a_flag_1_and_a_NULL_string_should_be_printf_null);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
