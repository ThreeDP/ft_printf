#include "../test.h"

MU_TEST_SUITE(test_if_enter_the_letter_a_lowercase_in_isalpha_func_result_in_true)
{
	//ARRANGE
	int	letter = 97;
	int	returned_result;

	//ACT
	returned_result = ft_isalpha(letter);

	//ASSERT
	mu_assert(returned_result > 0, "the returned result should be TRUE");
}

MU_TEST_SUITE(test_if_enter_the_letter_A_uppercase_in_isalpha_func_result_in_true)
{
	//ARRANGE
	int	letter = 65;
	int	returned_result;

	//ACT
	returned_result = ft_isalpha(letter);

	//ASSERT
	mu_assert(returned_result > 0, "the returned result should be TRUE");
}

MU_TEST_SUITE(test_if_enter_the_digit_0_in_isalpha_func_result_in_false)
{
	//ARRANGE
	int	letter = 48;
	int	returned_result;

	//ACT
	returned_result = ft_isalpha(letter);

	//ASSERT
	mu_assert(returned_result == 0, "the returned result should be FALSE");
}

MU_TEST_SUITE(test_if_enter_the_character_DEL_in_isalpha_func_result_in_false)
{
	//ARRANGE
	int	letter = 127;
	int	returned_result;

	//ACT
	returned_result = ft_isalpha(letter);

	//ASSERT
	mu_assert(returned_result == 0, "the returned result should be FALSE");
}

MU_TEST_SUITE(test_if_enter_the_character_asterisk_in_isalpha_func_result_in_false)
{
	//ARRANGE
	int	letter = 42;
	int	returned_result;

	//ACT
	returned_result = ft_isalpha(letter);

	//ASSERT
	mu_assert(returned_result == 0, "the returned result should be FALSE");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_if_enter_the_letter_a_lowercase_in_isalpha_func_result_in_true);
	MU_RUN_TEST(test_if_enter_the_letter_A_uppercase_in_isalpha_func_result_in_true);
	MU_RUN_TEST(test_if_enter_the_digit_0_in_isalpha_func_result_in_false);
	MU_RUN_TEST(test_if_enter_the_character_DEL_in_isalpha_func_result_in_false);
	MU_RUN_TEST(test_if_enter_the_character_asterisk_in_isalpha_func_result_in_false);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}