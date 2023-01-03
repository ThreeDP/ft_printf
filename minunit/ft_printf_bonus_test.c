#include "minunit.h"
#include "../srcs/mandatory/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"

int setup(char *file, int *fd)
{
    int     bkp;
    
    *fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!*fd)
        return (0);
    bkp = dup(1);
    dup2(*fd, 1);
    return (bkp);
}

char *unset(int fd, char *file, int *bkp)
{
    char *text;

    close(fd);
    fd = open(file, O_RDONLY);
    text = get_next_line(fd);
    dup2(*bkp, 1);
    remove(file);
    return (text);
}

MU_TEST_SUITE(passing_a_5_flag_for_the_string_davy_and_return_space_davy)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/initial-hashtag";
    char    *word               = "Davy";
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "The first name of he is Davy!";
    int     expected_bytes      = 29;
    
    //ACT
    bytes = ft_printf("The first name of he is%5s!", word);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
    free(result_str);
}

MU_TEST_SUITE(test_suite)
{	
    MU_RUN_TEST(passing_a_5_flag_for_the_string_davy_and_return_space_davy);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
