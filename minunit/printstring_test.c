#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"

MU_TEST_SUITE(test)
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
    shape->flags                        = ft_strdup("%3s");
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
    mu_assert_int_eq(expected_bsr, bsr);
    mu_assert_string_eq(expected_result, str);
    if (shape->flags)
        free(shape->flags);
    if (shape)
        free(shape);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
