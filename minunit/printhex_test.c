#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"
#include <stdio.h>
#include <limits.h>

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
    if (!text)
        text = ft_strdup("");
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

MU_TEST_SUITE(passing_the_flag_0_4_from_the_number_9_should_be_0009)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/04d";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 0;
    char            *expected_result    = "0";
    int             expected_bsr        = 1;
    shape->type                         = 'x';
    shape->flags                        = ft_strdup("#");

    //ACT
    bsr = printhex(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(test)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/04d";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    long             num                 = LONG_MIN;
    char            *expected_result    = "0";
    int             expected_bsr        = 1;
    shape->type                         = 'x';
    shape->flags                        = ft_strdup("#");

    //ACT
    bsr = printhex(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(test2)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/04d";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    long             num                 = 17;
    char            *expected_result    = "0x11";
    int             expected_bsr        = 4;
    shape->type                         = 'p';
    shape->flags                        = ft_strdup("-4");

    //ACT
    bsr = printhex(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(test3)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/04d";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    long             num                 = 0;
    char            *expected_result    = "(nil)     ";
    int             expected_bsr        = 10;
    shape->type                         = 'p';
    shape->flags                        = ft_strdup("-10");

    //ACT
    bsr = printhex(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(test4)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/04d";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    long             num                 = 0;
    char            *expected_result    = "";
    int             expected_bsr        = 0;
    shape->type                         = 'x';
    shape->flags                        = ft_strdup(".0");

    //ACT
    bsr = printhex(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(test5)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/04d";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    long             num                 = (unsigned int) - 1;
    char            *expected_result    = "ffffffff";
    int             expected_bsr        = 8;
    shape->type                         = 'x';
    shape->flags                        = ft_strdup(".0");

    //ACT
    bsr = printhex(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(passing_the_flag_0_4_from_the_number_9_should_be_0009);
    MU_RUN_TEST(test);
    MU_RUN_TEST(test2);
    MU_RUN_TEST(test3);
    MU_RUN_TEST(test4);
    MU_RUN_TEST(test5);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
