#include "../test.h"

MU_TEST_SUITE(test_enter_a_string_empty_in_func_strlen)
{
	//ARRANGE
	char	string[] = "";
	int		expected_result = 0;
	int		returned_result;

	//ACT
	returned_result = ft_strlen(string);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_enter_a_string_with_seven_characters_in_func_strlen)
{
	//ARRANGE
	char	string[] = "abacate";
	int		expected_result = 7;
	int		returned_result;

	//ACT
	returned_result = ft_strlen(string);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_enter_a_string_with_a_NULL_character_in_func_strlen)
{
	//ARRANGE
	char	string[] = "\0";
	int		expected_result = 0;
	int		returned_result;

	//ACT
	returned_result = ft_strlen(string);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_enter_a_string_empty_in_func_strlen);
	MU_RUN_TEST(test_enter_a_string_with_seven_characters_in_func_strlen);
	MU_RUN_TEST(test_enter_a_string_with_a_NULL_character_in_func_strlen);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}