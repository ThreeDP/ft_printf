#include "minunit.h"
#include "get_next_line.h"

MU_TEST_SUITE(passing_a_char_D_print_in_the_terminal)
{
    //ARRANGE
    char    *file = "./file"
    char    *expected_result = "D";
    int     expected_bytes = 1;
    char    *result_str;
    int     bytes;
    int     fd = open(file, O_WRONLY);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf("D");
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
}

int main() {
	MU_RUN_SUITE(passing_a_char_D_print_in_the_terminal);
	MU_REPORT();
	return MU_EXIT_CODE;
}