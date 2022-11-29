#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"

MU_TEST_SUITE(passing_a_11_flag_for_the_char_T_and_return_10_spaces_T)
{
    //CONFIG
    char            *file               = "./files/string/10spacesT";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 'c';
    shape->flags                        = ft_strdup("11");
    char            character           = 'T';
    char            *ret_str;
    char            *expected_result    = "          T";
    int             bsr;
    int             expected_bsr        = 11;

    //ACT
    bsr = printchar(fd, character, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    ret_str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, ret_str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (ret_str)
        free(ret_str);
}

MU_TEST_SUITE(passing_a_minus_11_flag_for_the_char_T_and_return_T_10_spaces)
{
    //CONFIG
    char            *file               = "./files/string/T10spaces";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 'c';
    shape->flags                        = ft_strdup("-11");
    char            character           = 'T';
    char            *ret_str;
    char            *expected_result    = "T          ";
    int             bsr;
    int             expected_bsr        = 11;

    //ACT
    bsr = printchar(fd, character, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    ret_str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, ret_str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (ret_str)
        free(ret_str);
}

MU_TEST_SUITE(passing_a_3_minus_11_flag_for_the_char_T_and_return_T_10_spaces)
{
    //CONFIG
    char            *file               = "./files/string/3minusT10spaces";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 'c';
    shape->flags                        = ft_strdup("---11");
    char            character           = 'T';
    char            *ret_str;
    char            *expected_result    = "T          ";
    int             bsr;
    int             expected_bsr        = 11;

    //ACT
    bsr = printchar(fd, character, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    ret_str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, ret_str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (ret_str)
        free(ret_str);
}

MU_TEST_SUITE(passing_a_7_flag_for_the_char_null_and_return_6_spaces)
{
    //CONFIG
    char            *file               = "./files/string/6spaces";
    int             fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    t_format        *shape              = (t_format *) malloc(sizeof(t_format));
    if (!shape)
        return ;
    //ARRANGE
    shape->type                         = 'c';
    shape->flags                        = ft_strdup("7");
    char            character           = 0;
    char            *ret_str;
    char            *expected_result    = "      ";
    int             bsr;
    int             expected_bsr        = 7;

    //ACT
    bsr = printchar(fd, character, &shape);
    close(fd);
    fd = open(file, O_RDONLY);
    ret_str = get_next_line(fd);
    remove(file);

    //ASSERTS
    mu_assert_string_eq(expected_result, ret_str);
    mu_assert_int_eq(expected_bsr, bsr);
    if (shape->arg)
        free(shape->arg);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
    if (ret_str)
        free(ret_str);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(passing_a_11_flag_for_the_char_T_and_return_10_spaces_T);
    MU_RUN_TEST(passing_a_minus_11_flag_for_the_char_T_and_return_T_10_spaces);
    MU_RUN_TEST(passing_a_3_minus_11_flag_for_the_char_T_and_return_T_10_spaces);
    MU_RUN_TEST(passing_a_7_flag_for_the_char_null_and_return_6_spaces);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
