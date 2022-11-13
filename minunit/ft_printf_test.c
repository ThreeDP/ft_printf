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
    int     fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf(fd, "D");
    close(fd);
    fd = open(file, O_RDONLY);
    result_str = get_next_line(fd);
    close(fd);
    remove(file);

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
    int     fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf(fd, "One Ring to rule them all, One Ring to find them, One Ring to bring them all, and in the darkness bind them, In the Land of Mordor where the Shadows lie.");
    close(fd);
    fd = open(file, O_RDONLY);
    result_str = get_next_line(fd);
    close(fd);
    remove(file);

    //ASSERT
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
}

MU_TEST_SUITE(passing_a_text_with_one_char_print_the_text_and_the_char_in_the_correct_position)
{
    //ARRANGE
    char    *file = "./files/initial";
    char    fisrt_letter        = 'D';
    char    *expected_result = "The initials of the name Davy Paulino are D.P";
    int     expected_bytes = 45;
    char    *result_str;
    int     bytes;
    int     fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf(fd, "The initials of the name Davy Paulino are %c.P", fisrt_letter);
    close(fd);
    fd = open(file, O_RDONLY);
    result_str = get_next_line(fd);
    close(fd);
    remove(file);

    //ASSERT
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
}

MU_TEST_SUITE(passing_a_text_with_two_chars_print_the_text_and_the_chars_in_the_correct_position)
{
    //ARRANGE
    char    *file = "./files/initials";
    char    fisrt_letter        = 'D';
    char    second_letter       = 'P';
    char    *expected_result = "The initials of the name Davy Paulino are D.P";
    int     expected_bytes = 45;
    char    *result_str;
    int     bytes;
    int     fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf(fd, "The initials of the name Davy Paulino are %c.%c", fisrt_letter, second_letter);
    close(fd);
    fd = open(file, O_RDONLY);
    result_str = get_next_line(fd);
    close(fd);
    remove(file);

    //ASSERT
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
}

MU_TEST_SUITE(passing_a_text_with_one_strings_print_the_text_and_the_string_in_the_correct_position)
{
    //ARRANGE
    char    *file = "./files/you-cannot-pass-one-str";
    char    first_string[]   = "You Cannot Pass!";
    char    *expected_result = "You Cannot Pass! I am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, Flame of Udun! Go back to the shadow.";
    int     expected_bytes = 153;
    char    *result_str;
    int     bytes;
    int     fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf(fd, "%s I am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, Flame of Udun! Go back to the shadow.", first_string);
    close(fd);
    fd = open(file, O_RDONLY);
    result_str = get_next_line(fd);
    close(fd);
    remove(file);

    //ASSERT
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
}

MU_TEST_SUITE(passing_a_text_with_two_strings_print_the_text_and_the_stringss_in_the_correct_position)
{
    //ARRANGE
    char    *file = "./files/you-cannot-pass-two-str";
    char    first_string[]   = "You Cannot Pass!";
    char    second_string[]  = "Flame of Udun!";
    char    *expected_result = "You Cannot Pass! I am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, Flame of Udun! Go back to the shadow.";
    int     expected_bytes = 153;
    char    *result_str;
    int     bytes;
    int     fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf(fd, "%s I am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, %s Go back to the shadow.", first_string, second_string);
    close(fd);
    fd = open(file, O_RDONLY);
    result_str = get_next_line(fd);
    close(fd);
    remove(file);

    //ASSERT
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
}

MU_TEST_SUITE(passing_a_text_with_one_char_and_one_string_print_the_text_with_the_char_and_string_in_the_correct_position)
{
    //ARRANGE
    char    *file = "./files/you-cannot-pass-char-str";
    char    first_string   = 'I';
    char    second_string[]  = "Flame of Udun!";
    char    *expected_result = "You Cannot Pass! I am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, Flame of Udun! Go back to the shadow.";
    int     expected_bytes = 153;
    char    *result_str;
    int     bytes;
    int     fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf(fd, "You Cannot Pass! %c am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, %s Go back to the shadow.", first_string, second_string);
    close(fd);
    fd = open(file, O_RDONLY);
    result_str = get_next_line(fd);
    close(fd);
    remove(file);

    //ASSERT
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
}

MU_TEST_SUITE(passing_a_text_with_one_int_value_print_the_text_with_the_int_in_the_correct_position)
{
    //ARRANGE
    char    *file = "./files/you-cannot-pass";
    int     number = 42;
    char    *expected_result = "The Ultimate Answer to Life, The Universe and Everything is...42";
    int     expected_bytes = 64;
    char    *result_str;
    int     bytes;
    int     fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return ;
    
    //ACT
    bytes = ft_printf(fd, "The Ultimate Answer to Life, The Universe and Everything is...%i", number);
    close(fd);
    fd = open(file, O_RDONLY);
    result_str = get_next_line(fd);
    close(fd);
    remove(file);

    //ASSERT
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
}

MU_TEST_SUITE(test_suite)
{	
    MU_RUN_TEST(passing_a_char_D_print_in_the_terminal);
    MU_RUN_TEST(passing_a_text_of_lord_of_rings_printf_the_text_in_the_terminal);
    MU_RUN_TEST(passing_a_text_with_one_char_print_the_text_and_the_char_in_the_correct_position);
    MU_RUN_TEST(passing_a_text_with_two_chars_print_the_text_and_the_chars_in_the_correct_position);
    MU_RUN_TEST(passing_a_text_with_one_strings_print_the_text_and_the_string_in_the_correct_position);
    MU_RUN_TEST(passing_a_text_with_two_strings_print_the_text_and_the_stringss_in_the_correct_position);
    MU_RUN_TEST(passing_a_text_with_one_char_and_one_string_print_the_text_with_the_char_and_string_in_the_correct_position);
    MU_RUN_TEST(passing_a_text_with_one_int_value_print_the_text_with_the_int_in_the_correct_position);
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