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

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(passing_the_flag_11_from_the_number_256_should_be_8_spaces_256);
    MU_RUN_TEST(passing_the_flag_minus_11_from_the_number_minus_256_should_be_minus_256_7_spaces);
    MU_RUN_TEST(passing_the_flag_plus_11_from_the_number_256_should_be_minus_7_spaces_256);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
