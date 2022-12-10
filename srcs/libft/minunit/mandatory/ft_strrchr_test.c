#include "../test.h"

MU_TEST_SUITE(test_strrchr_look_up_character_in_empty_string_should_return_null)
{
	//ARRANGE
	char		string[] = "";
	int			character = 'c';
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strrchr(string, character);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_strrchr_passing_the_letter_A_to_find_in_Amora_must_return_the_address_of_indice_zero)
{
	//ARRANGE
	int		chr = 'A';
	char	string[] = "Amora";
	char	*expected_result = &string[0];
	char	*actual_result;

	//ACT
	actual_result = ft_strrchr(string, chr);

	//ASSERT
	mu_assert(expected_result == actual_result, "Expected and Actual result should be de same!");
}

MU_TEST_SUITE(test_strrchr_look_up_character_in_null_string_should_return_null)
{
	//ARRANGE
	char		string[0];
	int			character = 'c';
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strrchr(string, character);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_strrchr_look_up_NULL_character_in_Amora_string_should_return_null)
{
	//ARRANGE
	char		string[] = "Amora";
	int			character = '\0';
	char		*expected_result = &string[5];
	char		*actual_result;

	//ACT
	actual_result = ft_strrchr(string, character);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_strrchr_look_up_NULL_character_in_Amora_string_should_return_null);
	MU_RUN_TEST(test_strrchr_look_up_character_in_null_string_should_return_null);
	MU_RUN_TEST(test_strrchr_look_up_character_in_empty_string_should_return_null);
	MU_RUN_TEST(test_strrchr_passing_the_letter_A_to_find_in_Amora_must_return_the_address_of_indice_zero);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}