#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"

MU_TEST_SUITE(passing_a_char_D_print_in_the_terminal)
{
    //ARRANGE
    char    *file = "./files/D";
    char    *expected_result = "D";
    int     expected_bytes = 1;
    char    *result_str;
    int     bytes;
    int     fd = open(file, O_WRONLY);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf(fd, "D");
    close(fd);
    fd = open(file, O_RDONLY);
    result_str = get_next_line(fd);
    close(fd);

    //ASSERT
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
}

MU_TEST_SUITE(passing_a_text_of_lord_of_rings_printf_the_text_in_the_terminal)
{
    //ARRANGE
    char    *file = "./files/One-ring";
    char    *expected_result = "One Ring to rule them all, One Ring to find them, One Ring to bring them all, and in the darkness bind them, In the Land of Mordor where the Shadows lie.";
    int     expected_bytes = 153;
    char    *result_str;
    int     bytes;
    int     fd = open(file, O_WRONLY);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf(fd, "One Ring to rule them all, One Ring to find them, One Ring to bring them all, and in the darkness bind them, In the Land of Mordor where the Shadows lie.");
    close(fd);
    fd = open(file, O_RDONLY);
    result_str = get_next_line(fd);
    close(fd);

    //ASSERT
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
}

MU_TEST_SUITE(test_suite)
{	
    MU_RUN_TEST(passing_a_char_D_print_in_the_terminal);
    MU_RUN_TEST(passing_a_text_of_lord_of_rings_printf_the_text_in_the_terminal);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}