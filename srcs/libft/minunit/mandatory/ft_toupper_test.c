#include "../test.h"

MU_TEST_SUITE(test_toupper_passing_a_char_number_should_be_itself)
{
	//ARRANGE
	int		chr = '5';
	int		returned_result;
	int		expected_result = '5';

	//ACT
	returned_result = ft_toupper(chr);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_toupper_passing_the_letter_a_lowercase_should_be_A_uppercase)
{
	//ARRANGE
	int		chr = 'a';
	int		returned_result;
	int		expected_result = 'A';

	//ACT
	returned_result = ft_toupper(chr);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_toupper_passing_the_int_128_should_be_itself)
{
	//ARRANGE
	int		chr = 128;
	int		returned_result;
	int		expected_result = 128;

	//ACT
	returned_result = ft_toupper(chr);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_toupper_passing_A_uppercase_char_should_be_itself)
{
	//ARRANGE
	int		chr = 'A';
	int		returned_result;
	int		expected_result = 'A';

	//ACT
	returned_result = ft_toupper(chr);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_toupper_passing_A_uppercase_char_should_be_itself);
	MU_RUN_TEST(test_toupper_passing_the_int_128_should_be_itself);
	MU_RUN_TEST(test_toupper_passing_the_letter_a_lowercase_should_be_A_uppercase);
	MU_RUN_TEST(test_toupper_passing_a_char_number_should_be_itself);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}