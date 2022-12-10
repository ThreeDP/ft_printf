#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"

t_format *setup(char *file, int  *fd)
{
    t_format    *shape;

    *fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!*fd)
        return (NULL);
    shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return (NULL);
    return (shape);
}

char *unset(int fd, char *file)
{
    char *text;

    close(fd);
    fd = open(file, O_RDONLY);
    text = get_next_line(fd);
    remove(file);
    return (text);
}

void    free_shape(t_format **shape, char *str)
{
    if (str)
        free(str);
    if ((*shape)->arg)
        free((*shape)->arg);
    if ((*shape)->flags)
        free((*shape)->flags);
    if ((*shape))
        free((*shape));
}

MU_TEST_SUITE(passing_a_11_flag_for_the_string_One_Ring_and_return_three_spaces_One_Ring)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/one-ring";
    t_format        *shape              = setup(file, &fd);

    //ARRANGE
    int             bsr;
    char            *result_str;
    char            *str                = "One Ring";
    char            *expected_result    = "   One Ring";
    int             expected_bsr        = 11;
    shape->type                         = 's';
    shape->flags                        = ft_strdup("11");

    //ACT
    bsr = printstring(fd, str, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_a_minus_11_flag_for_the_string_One_Ring_and_return_One_Ring_three_spaces)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/one-ring-reverse";
    t_format        *shape              = setup(file, &fd);

    //ARRANGE
    int             bsr;
    char            *result_str;
    char            *str                = "One Ring";
    char            *expected_result    = "One Ring   ";
    int             expected_bsr        = 11;
    shape->type                         = 's';
    shape->flags                        = ft_strdup("-11");

    //ACT
    bsr = printstring(fd, str, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_a_flag_11_dot_3_and_a_string_One_Ring_should_be_8_spaces_One)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/one";
    t_format        *shape              = setup(file, &fd);

    //ARRANGE
    int             bsr;
    char            *result_str;
    char            *str                = "One Ring";
    char            *expected_result    = "        One";
    int             expected_bsr        = 11;
    shape->type                         = 's';
    shape->flags                        = ft_strdup("11.3");

    //ACT
    bsr = printstring(fd, str, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_a_flag_4_dot_5_and_a_string_One_Ring_should_be_One_R)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/4dot5";
    t_format        *shape              = setup(file, &fd);

    //ARRANGE
    int             bsr;
    char            *result_str;
    char            *str                = "One Ring";
    char            *expected_result    = "One R";
    int             expected_bsr        = 5;
    shape->type                         = 's';
    shape->flags                        = ft_strdup("4.5");

    //ACT
    bsr = printstring(fd, str, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_a_flag_5_dot_2_and_a_string_One_Ring_should_be_On)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/5dot2";
    t_format        *shape              = setup(file, &fd);

    //ARRANGE
    int             bsr;
    char            *result_str;
    char            *str                = "One Ring";
    char            *expected_result    = "   On";
    int             expected_bsr        = 5;
    shape->type                         = 's';
    shape->flags                        = ft_strdup("5.2");

    //ACT
    bsr = printstring(fd, str, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_a_flag_3_dot_0_and_a_string_One_Ring_should_be_3_spaces)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/3dot0";
    t_format        *shape              = setup(file, &fd);

    //ARRANGE
    int             bsr;
    char            *result_str;
    char            *str                = "One Ring";
    char            *expected_result    = "   ";
    int             expected_bsr        = 3;
    shape->type                         = 's';
    shape->flags                        = ft_strdup("3.0");

    //ACT
    bsr = printstring(fd, str, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_a_flag_minus_30_dot_20_and_a_string_One_Ring_should_be_3_spaces)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/minus30dot20";
    t_format        *shape              = setup(file, &fd);

    //ARRANGE
    int             bsr;
    char            *result_str;
    char            *str                = "One Ring";
    char            *expected_result    = "One Ring                      ";
    int             expected_bsr        = 30;
    shape->type                         = 's';
    shape->flags                        = ft_strdup("-30.20");

    //ACT
    bsr = printstring(fd, str, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_a_flag_6_minus_30_dot_20_and_a_string_One_Ring_should_be_3_spaces)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/6minus30dot20";
    t_format        *shape              = setup(file, &fd);

    //ARRANGE
    int             bsr;
    char            *result_str;
    char            *str                = "One Ring";
    char            *expected_result    = "One Ring                      ";
    int             expected_bsr        = 30;
    shape->type                         = 's';
    shape->flags                        = ft_strdup("------30.20");

    //ACT
    bsr = printstring(fd, str, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_a_flag_1_and_a_empty_string_should_be_space)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/space1";
    t_format        *shape              = setup(file, &fd);

    //ARRANGE
    int             bsr;
    char            *result_str;
    char            *str                = "";
    char            *expected_result    = " ";
    int             expected_bsr        = 1;
    shape->type                         = 's';
    shape->flags                        = ft_strdup("1");

    //ACT
    bsr = printstring(fd, str, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_a_flag_1_and_a_NULL_string_should_be_printf_null)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/null";
    t_format        *shape              = setup(file, &fd);

    //ARRANGE
    int             bsr;
    char            *result_str;
    char            *str                = NULL;
    char            *expected_result    = "(null)";
    int             expected_bsr        = 6;
    shape->type                         = 's';
    shape->flags                        = ft_strdup("1");

    //ACT
    bsr = printstring(fd, str, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_a_flag_dot_2_and_a_string_gol_should_be_print_go)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/printgo";
    t_format        *shape              = setup(file, &fd);

    //ARRANGE
    int             bsr;
    char            *result_str;
    char            *str                = "gol";
    char            *expected_result    = "go";
    int             expected_bsr        = 2;
    shape->type                         = 's';
    shape->flags                        = ft_strdup(".2");

    //ACT
    bsr = printstring(fd, str, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_a_flag_10_and_a_NULL_should_be_4_spaces_null)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/one";
    t_format        *shape              = setup(file, &fd);

    //ARRANGE
    int             bsr;
    char            *result_str;
    char            *str                = "(null)";
    char            *expected_result    = "    (null)";
    int             expected_bsr        = 10;
    shape->type                         = 's';
    shape->flags                        = ft_strdup("10");

    //ACT
    bsr = printstring(fd, str, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
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
    MU_RUN_TEST(passing_a_flag_dot_2_and_a_string_gol_should_be_print_go);
    MU_RUN_TEST(passing_a_flag_10_and_a_NULL_should_be_4_spaces_null);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
