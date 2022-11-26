#include "minunit.h"
#include "../srcs/ft_printf.h"
#include "./get_next_line.h"
#include "ft_printf_test.h"

/*
MU_TEST_SUITE(passing_a_flag_hashtag_6_times_print_in_the_correct_position_the_char)
{
    //ARRANGE
    char    *file = "./files/initial-hashtag";
    char    fisrt_letter        = 'D';
    char    *expected_result = "The initials of the name Davy Paulino are D.P";
    int     expected_bytes = 45;
    char    *result_str;
    int     bytes;
    int     fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf(fd, "The initials of the name Davy Paulino are %######3c.P", fisrt_letter);
    close(fd);
    fd = open(file, O_RDONLY);
    result_str = get_next_line(fd);
    close(fd);
    remove(file);

    //ASSERT
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
    free(result_str);
}
*/

MU_TEST_SUITE(passing_a_5_flag_for_the_string_davy_and_return_space_davy)
{
    //ARRANGE
    char    *file = "./files/initial-hashtag";
    char    *word               = "Davy";
    char    *expected_result    = "The first name of he is Davy!";
    int     expected_bytes = 29;
    char    *result_str;
    int     bytes;
    int     fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf(fd, "The first name of he is%5s!", word);
    close(fd);
    fd = open(file, O_RDONLY);
    result_str = get_next_line(fd);
    close(fd);
    remove(file);

    //ASSERT
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
    free(result_str);
}

MU_TEST_SUITE(test_suite)
{	
    //MU_RUN_TEST(passing_a_flag_hashtag_6_times_print_in_the_correct_position_the_char);
    MU_RUN_TEST(passing_a_5_flag_for_the_string_davy_and_return_space_davy);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

/*
%c
%s
> afetada por precisão de caracteres, se precisão for zero ou não existente printa toda a string.
%p
%d
%i
%u
%x
%X
%%
> Print a percent sign.
FLAGS BONUS

=======> '-0.'
minus (-)
> Substitui o zero adicionando espaços em branco, alinha valor a direita. 

zero (0)     
afta -> d i x X

dot (.)     
afeta --> f F

=======> '# +'
hashtag (#)     
afeta --> x X f F

space ( )
> formata numeros positivos com um espaço para alinha a numeros negativos, o sinal positivo sobrescreve o espaço se for usado.
afeta --> d i f x X

plus (+)        
afeta --> d i f x X

*/