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

MU_TEST_SUITE(passing_a_char_D_print_in_the_terminal)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/D";
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "D";
    int     expected_bytes      = 1;

    //ACT
    bytes = ft_printf("D");

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_text_of_lord_of_rings_printf_the_text_in_the_terminal)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/One-ring";
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "One Ring to rule them all, One Ring to find them, One Ring to bring them all, and in the darkness bind them, In the Land of Mordor where the Shadows lie.";
    int     expected_bytes      = 153;

    //ACT
    bytes = ft_printf("One Ring to rule them all, One Ring to find them, One Ring to bring them all, and in the darkness bind them, In the Land of Mordor where the Shadows lie.");

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_text_with_one_char_print_the_text_and_the_char_in_the_correct_position)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/initial";
    char    fisrt_letter        = 'D';
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "The initials of the name Davy Paulino are D.P";
    int     expected_bytes      = 45;

    //ACT
    bytes = ft_printf("The initials of the name Davy Paulino are %c.P", fisrt_letter);
    
    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_text_with_one_NULL_char_print_the_text_until_the_position_of_char)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/null-char";
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "The initials of the name Davy Paulino are ";
    int     expected_bytes      = 45;

    //ACT
    bytes = ft_printf("The initials of the name Davy Paulino are %c.P", NULL);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_text_with_two_chars_print_the_text_and_the_chars_in_the_correct_position)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/initials";
    char    fisrt_letter        = 'D';
    char    second_letter       = 'P';
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "The initials of the name Davy Paulino are D.P";
    int     expected_bytes      = 45;
    
    //ACT
    bytes = ft_printf("The initials of the name Davy Paulino are %c.%c", fisrt_letter, second_letter);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_text_with_one_strings_print_the_text_and_the_string_in_the_correct_position)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/you-cannot-pass-one-str";
    char    *first_string       = "You Cannot Pass!";
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "You Cannot Pass! I am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, Flame of Udun! Go back to the shadow.";
    int     expected_bytes      = 153;
    
    //ACT
    bytes = ft_printf("%s I am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, Flame of Udun! Go back to the shadow.", first_string);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_text_with_one_string_NULL_print_the_text_and_the_NULL_in_the_correct_position)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/NULL-str";
    char    *first_string       = NULL;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "(null) I am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, Flame of Udun! Go back to the shadow.";
    int     expected_bytes      = 143;
    
    //ACT
    bytes = ft_printf("%s I am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, Flame of Udun! Go back to the shadow.", first_string);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_text_with_two_strings_print_the_text_and_the_stringss_in_the_correct_position)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/you-cannot-pass-two-str";
    char    *first_string       = "You Cannot Pass!";
    char    *second_string      = "Flame of Udun!";
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "You Cannot Pass! I am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, Flame of Udun! Go back to the shadow.";
    int     expected_bytes      = 153;
    
    //ACT
    bytes = ft_printf("%s I am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, %s Go back to the shadow.", first_string, second_string);
    
    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_text_with_one_char_and_one_string_print_the_text_with_the_char_and_string_in_the_correct_position)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/you-cannot-pass-char-str";
    char    first_string        = 'I';
    char    *second_string      = "Flame of Udun!";
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "You Cannot Pass! I am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, Flame of Udun! Go back to the shadow.";
    int     expected_bytes      = 153;
    
    //ACT
    bytes = ft_printf("You Cannot Pass! %c am a servant of the Secret Fire, wielder of the Flame of Anor. The dark fire will not avail you, %s Go back to the shadow.", first_string, second_string);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_text_with_one_int_value_print_the_text_with_the_int_in_the_correct_position)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/the-ultimate-answer-int";
    int     number              = 42;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "The Ultimate Answer to Life, The Universe and Everything is...42";
    int     expected_bytes      = 64;
    
    //ACT
    bytes = ft_printf("The Ultimate Answer to Life, The Universe and Everything is...%i", number);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_text_with_one_decimal_value_print_the_text_with_the_decimal_in_the_correct_position)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/the-ultimate-answer-int";
    int     number              = 42;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "The Ultimate Answer to Life, The Universe and Everything is...42";
    int     expected_bytes      = 64;
    
    //ACT
    bytes = ft_printf("The Ultimate Answer to Life, The Universe and Everything is...%d", number);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_one_int_with_value_minus_42_shold_be_minus_42)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/minus-42-int";
    int     number              = -42;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "-42 && -42";
    int     expected_bytes      = 10;
    
    //ACT
    bytes = ft_printf("%i && %d", number, number);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_text_with_a_char_a_string_a_int_and_a_decimal_value_print_the_text_with_the_flags_in_the_correct_position)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/the-ultimate-answer-mix-flags";
    char    letter              = 'A';
    char    *string             = "Everything";
    int     number              = 42;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "The Ultimate Answer to Life, The Universe and Everything is...42, yes 42.";
    int     expected_bytes      = 73;
    
    //ACT
    bytes = ft_printf("The Ultimate %cnswer to Life, The Universe and %s is...%i, yes %d.", letter, string, number, number);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_unsigned_int_with_value_minus_42_shold_be_4294967254)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/minus-42-unsigned_int";
    int     number              = -42;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "4294967254";
    int     expected_bytes      = 10;
    
    //ACT
    bytes = ft_printf("%u", number);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
    free(result_str);
}

MU_TEST_SUITE(passing_a_text_with_three_zeros_in_decimal_unsigned_int_and_int_print_the_text_with_the_zeros_in_the_correct_position)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/the-ultimate-answer-int";
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "0, 0 or 0";
    int     expected_bytes      = 9;
    
    //ACT
    bytes = ft_printf("%u, %i or %d", NULL, NULL, NULL);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_int_with_value_10_shold_be_A_in_hex)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/10-in-hex-uppercase";
    int     number              = 10;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "A";
    int     expected_bytes      = 1;
    
    //ACT
    bytes = ft_printf("%X", number);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}


MU_TEST_SUITE(passing_a_int_with_value_minus_42_shold_be_FFFFFFD6_in_hex)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/minus-42-hex-uppercase";
    int     number              = -42;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "FFFFFFD6";
    int     expected_bytes      = 8;
    
    //ACT
    bytes = ft_printf("%X", number);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
    free(result_str);
}

MU_TEST_SUITE(passing_two_int_with_value_minus_42_and_42_shold_be_ffffffd6_or_2a)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/minus-42-hex-lowercase";
    int     number1             = -42;
    int     number2             = 42;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "ffffffd6 or 2a";
    int     expected_bytes      = 14;
    
    //ACT
    bytes = ft_printf("%x or %x", number1, number2);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_NULL_from_hex_shold_be_ZERO)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/NULL-hex";
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "0 or 0";
    int     expected_bytes      = 6;
    
    //ACT
    bytes = ft_printf("%x or %X", NULL, NULL);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_int_eq(expected_bytes, bytes);
    mu_assert_string_eq(expected_result, result_str);
    free(result_str);
}

MU_TEST_SUITE(passing_a_address_print_the_value_of_the_address_in_hex)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/pointer-address";
    ssize_t address             = 68702702552;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "0xfff000bd8";
    int     expected_bytes  = 11;
    
    //ACT
    bytes = ft_printf("%p", address);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
    free(result_str);
}

MU_TEST_SUITE(passing_the_long_min_max_address_print_the_value_of_the_address_in_hex)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/max-min-long-address";
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "0x8000000000000000 0x7fffffffffffffff";
    int     expected_bytes      = 37;
    
    //ACT
    bytes = ft_printf("%p %p", LONG_MIN, LONG_MAX);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
    free(result_str);
}

MU_TEST_SUITE(passing_a_address_null_print_the_word_nil)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/pointer-address-null";
    ssize_t address             = 0;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "(nil)";
    int     expected_bytes      = 5;

    //ACT
    bytes = ft_printf("%p", address);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
    free(result_str);
}

MU_TEST_SUITE(passing_a_mix_of_flags)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/mix-flags";
    char    letter              = 'D';
    char    *string             = "dapaulin";
    int     intT                = 42;
    int     intD                = 13;
    int     intU                = -7;
    int     hexL                = 42;
    int     hexU                = 10;
    ssize_t address             = 68702702552;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "Ddapaulin421342949672892aA0xfff000bd8%";
    int     expected_bytes      = 38;

    //ACT
    bytes = ft_printf("%c%s%i%d%u%x%X%p%%", letter, string, intT, intD,  intU, hexL, hexU, address);
    
    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
    free(result_str);
}

MU_TEST_SUITE(passing_str_NULL_should_be_minus_1)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/null-string";
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = NULL;
    int     expected_bytes      = -1;

    //ACT
    bytes = ft_printf(0);
    
    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
    free(result_str);
}

MU_TEST_SUITE(passing_a_address_null_with_flag_10_should_be_the_word_5_spaces_nil)
{
    //ARRANGE
    int     fd;
    int     bytes;
    char    *result_str;
    char    *file               = "./files/3-spaces-null-pointer";
    ssize_t address             = 0;
    int     bkp                 = setup(file, &fd);
    char    *expected_result    = "     (nil)";
    int     expected_bytes      = 10;

    //ACT
    bytes = ft_printf("%10p", address);

    //ASSERT
    result_str = unset(fd, file, &bkp);
    mu_assert_string_eq(expected_result, result_str);
    mu_assert_int_eq(expected_bytes, bytes);
    free(result_str);
}

MU_TEST_SUITE(test_suite)
{	
    MU_RUN_TEST(passing_a_char_D_print_in_the_terminal);
    MU_RUN_TEST(passing_a_text_of_lord_of_rings_printf_the_text_in_the_terminal);
    MU_RUN_TEST(passing_a_text_with_one_char_print_the_text_and_the_char_in_the_correct_position);
    MU_RUN_TEST(passing_a_text_with_one_NULL_char_print_the_text_until_the_position_of_char);
    MU_RUN_TEST(passing_a_text_with_two_chars_print_the_text_and_the_chars_in_the_correct_position);
    MU_RUN_TEST(passing_a_text_with_one_strings_print_the_text_and_the_string_in_the_correct_position);
    MU_RUN_TEST(passing_a_text_with_one_string_NULL_print_the_text_and_the_NULL_in_the_correct_position);
    MU_RUN_TEST(passing_a_text_with_two_strings_print_the_text_and_the_stringss_in_the_correct_position);
    MU_RUN_TEST(passing_a_text_with_one_char_and_one_string_print_the_text_with_the_char_and_string_in_the_correct_position);
    MU_RUN_TEST(passing_a_text_with_one_int_value_print_the_text_with_the_int_in_the_correct_position);
    MU_RUN_TEST(passing_a_text_with_one_decimal_value_print_the_text_with_the_decimal_in_the_correct_position);
    MU_RUN_TEST(passing_a_one_int_with_value_minus_42_shold_be_minus_42);
    MU_RUN_TEST(passing_a_text_with_a_char_a_string_a_int_and_a_decimal_value_print_the_text_with_the_flags_in_the_correct_position);
    MU_RUN_TEST(passing_a_unsigned_int_with_value_minus_42_shold_be_4294967254);
    MU_RUN_TEST(passing_a_text_with_three_zeros_in_decimal_unsigned_int_and_int_print_the_text_with_the_zeros_in_the_correct_position);
    MU_RUN_TEST(passing_a_int_with_value_10_shold_be_A_in_hex);
    MU_RUN_TEST(passing_a_int_with_value_minus_42_shold_be_FFFFFFD6_in_hex);
    MU_RUN_TEST(passing_two_int_with_value_minus_42_and_42_shold_be_ffffffd6_or_2a);
    MU_RUN_TEST(passing_a_address_print_the_value_of_the_address_in_hex);
    MU_RUN_TEST(passing_a_address_null_print_the_word_nil);
    MU_RUN_TEST(passing_the_long_min_max_address_print_the_value_of_the_address_in_hex);
    MU_RUN_TEST(passing_NULL_from_hex_shold_be_ZERO);
    MU_RUN_TEST(passing_a_mix_of_flags);
    MU_RUN_TEST(passing_str_NULL_should_be_minus_1);
    MU_RUN_TEST(passing_a_address_null_with_flag_10_should_be_the_word_5_spaces_nil);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
