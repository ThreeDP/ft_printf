#include "../test.h"


MU_TEST_SUITE(test_substr_passing_One_Ring_to_rule_them_all_start_with_0_end_with_9_should_be_One_Ring)
{
	//ARRANGE
	char			s[] = "One Ring to rule them all";
	unsigned int	start = 0;
	size_t			len = 8;
	char			expected_result[] = "One Ring";
	char			*actual_result;

	//ACT
	actual_result = ft_substr(s, start, len);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test_substr_passing_Right_part_bargemen_Radagast_the_Brown_cracked_start_with_20_end_with_9_should_be_Radagast)
{
	//ARRANGE
	char			s[] = "Right part bargemen Radagast the Brown cracked.";
	unsigned int	start = 20;
	size_t			len = 8;
	char			expected_result[] = "Radagast";
	char			*actual_result;

	//ACT
	actual_result = ft_substr(s, start, len);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test_substr_passing_Gandalf_death_was_not_in_vain_start_with_0_end_with_8_with_MAX_INT_len_should_be_NULL)
{
	//ARRANGE
	char			s[] = "Gandalf's death";
	unsigned int	start = 400;
	size_t			len = 20;
	char			*expected_result = "";
	char			*actual_result;

	//ACT
	actual_result = ft_substr(s, start, len);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test)
{
	//ARRANGE
	char			s[] = "0123456789";
	unsigned int	start = 9;
	size_t			len = 10;
	char			*expected_result = "9";
	char			*actual_result;

	//ACT
	actual_result = ft_substr(s, start, len);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test);
    MU_RUN_TEST(test_substr_passing_Gandalf_death_was_not_in_vain_start_with_0_end_with_8_with_MAX_INT_len_should_be_NULL);
	MU_RUN_TEST(test_substr_passing_Right_part_bargemen_Radagast_the_Brown_cracked_start_with_20_end_with_9_should_be_Radagast);
	MU_RUN_TEST(test_substr_passing_One_Ring_to_rule_them_all_start_with_0_end_with_9_should_be_One_Ring);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}