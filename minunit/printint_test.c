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

MU_TEST_SUITE(passing_the_flag_dot_1_from_the_number_99_should_be_99)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/dot2_99";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 99;
    char            *expected_result    = "99";
    int             expected_bsr        = 2;
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

MU_TEST_SUITE(passing_the_flag_space_0_dot_3_from_the_number_minus_99_should_be_space_minus_099)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/dot2_99";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = -99;
    char            *expected_result    = "-099";
    int             expected_bsr        = 4;
    shape->type                         = 'i';
    shape->flags                        = ft_strdup(" 0.3");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_space_dot_2_from_the_number_0_should_be_space_00)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/dot2_99";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 0;
    char            *expected_result    = " 00";
    int             expected_bsr        = 3;
    shape->type                         = 'i';
    shape->flags                        = ft_strdup(" .2");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_dot_5_from_the_number_157_should_be_00157)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/00157";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 157;
    char            *expected_result    = "00157";
    int             expected_bsr        = 5;
    shape->type                         = 'u';
    shape->flags                        = ft_strdup(".5");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_minus_17_dot_12_from_the_number_minus_157_should_be_004294967139_5_spaces)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/001575spaces";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = -157;
    char            *expected_result    = "004294967139     ";
    int             expected_bsr        = 17;
    shape->type                         = 'u';
    shape->flags                        = ft_strdup("-17.12");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_0_12_from_the_number_minus_157_should_be_004294967139)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/001575spaces";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = -157;
    char            *expected_result    = "004294967139";
    int             expected_bsr        = 12;
    shape->type                         = 'u';
    shape->flags                        = ft_strdup("012");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_minus_0_12_from_the_number_minus_157_should_be_4294967139_2_spaces)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/001575spaces";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = -157;
    char            *expected_result    = "4294967139  ";
    int             expected_bsr        = 12;
    shape->type                         = 'u';
    shape->flags                        = ft_strdup("-012");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_dot_0_from_the_num_0_should_be_nothing)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/dotflag";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 0;
    char            *expected_result    = "";
    int             expected_bsr        = 0;
    shape->type                         = 'd';
    shape->flags                        = ft_strdup(".0");

    //ACT
    bsr = printint(fd, num, &shape);
    result_str = unset(fd, file);

    //ASSERTS
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bsr, bsr);
    free_shape(&shape, result_str);
}

MU_TEST_SUITE(passing_the_flag_dot_0_from_the_num_420000_should_be_420000)
{
    //CONFIG
    int             fd;
    char            *file               = "./files/string/dotflag";
    t_format        *shape              = setup(file, &fd);
    
    //ARRANGE
    int             bsr;
    char            *result_str;
    int             num                 = 420000;
    char            *expected_result    = "420000";
    int             expected_bsr        = 6;
    shape->type                         = 'd';
    shape->flags                        = ft_strdup(".0");

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
    MU_RUN_TEST(passing_the_flag_dot_1_from_the_number_99_should_be_99);
    MU_RUN_TEST(passing_the_flag_space_0_dot_3_from_the_number_minus_99_should_be_space_minus_099);
    MU_RUN_TEST(passing_the_flag_space_dot_2_from_the_number_0_should_be_space_00);
    MU_RUN_TEST(passing_the_flag_dot_5_from_the_number_157_should_be_00157);
    MU_RUN_TEST(passing_the_flag_minus_17_dot_12_from_the_number_minus_157_should_be_004294967139_5_spaces);
    MU_RUN_TEST(passing_the_flag_0_12_from_the_number_minus_157_should_be_004294967139);
    MU_RUN_TEST(passing_the_flag_minus_0_12_from_the_number_minus_157_should_be_4294967139_2_spaces);
    MU_RUN_TEST(passing_the_flag_dot_0_from_the_num_0_should_be_nothing);
    MU_RUN_TEST(passing_the_flag_dot_0_from_the_num_420000_should_be_420000);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
