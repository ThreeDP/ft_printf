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

MU_TEST_SUITE(passing_a_11_flag_for_the_char_T_and_return_10_spaces_T)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/10spacesT";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *ret_str;
    char            character           = 'T';
    char            *expected_result    = "          T";
    int             expected_bsr        = 11;
    shape->type                         = 'c';
    shape->flags                        = ft_strdup("11");

    //ACT
    bsr = printchar(fd, character, &shape);
    ret_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, ret_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, ret_str);
}

MU_TEST_SUITE(passing_a_minus_11_flag_for_the_char_T_and_return_T_10_spaces)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/T10spaces";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *ret_str;
    char            character           = 'T';
    char            *expected_result    = "T          ";
    int             expected_bsr        = 11;
    shape->type                         = 'c';
    shape->flags                        = ft_strdup("-11");

    //ACT
    bsr = printchar(fd, character, &shape);
    ret_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, ret_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, ret_str);
}

MU_TEST_SUITE(passing_a_3_minus_11_flag_for_the_char_T_and_return_T_10_spaces)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/3minusT10spaces";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *ret_str;
    char            character           = 'T';
    char            *expected_result    = "T          ";
    int             expected_bsr        = 11;
    shape->type                         = 'c';
    shape->flags                        = ft_strdup("---11");

    //ACT
    bsr = printchar(fd, character, &shape);
    ret_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, ret_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, ret_str);
}

MU_TEST_SUITE(passing_a_7_flag_for_the_char_null_and_return_6_spaces)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/6spaces";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *ret_str;
    char            character           = '\0';
    char            *expected_result    = "      ";
    int             expected_bsr        = 0;
    shape->type                         = 'c';
    shape->flags                        = ft_strdup("7");

    //ACT
    bsr = printchar(fd, character, &shape);
    ret_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, ret_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, ret_str);
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
