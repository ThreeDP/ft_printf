#include "../test.h"

MU_TEST_SUITE(test_strtrim_passing_ll_for_trim_in_the_string_One_Ring_to_rule_them_all_should_be_e_them_a)
{
	//ARRANGE
	char	s1[] = "One Ring to rule them all";
	char	set[] = "ll";
	char	expected_result[] = "One Ring to rule them a";
	char	*actual_result;

	//ACT
	actual_result = ft_strtrim(s1, set);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strtrim_passing_tab_chr_for_trim_in_the_string_One_Ring_to_rule_them_all_should_be_Ring)
{
	//ARRANGE
	char	s1[] = "\tOne Ring to rule them all\t";
	char	set[] = "\t";
	char	expected_result[] = "One Ring to rule them all";
	char	*actual_result;

	//ACT
	actual_result = ft_strtrim(s1, set);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strtrim_passing_string_without_trims_should_be_the_same)
{
	//ARRANGE
	char	s1[] = "One \n Ring \t to rule \n them \t all";
	char	set[] = "\t";
	char	expected_result[] = "One \n Ring \t to rule \n them \t all";
	char	*actual_result;

	//ACT
	actual_result = ft_strtrim(s1, set);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_strtrim_passing_string_without_trims_should_be_the_same);
	MU_RUN_TEST(test_strtrim_passing_tab_chr_for_trim_in_the_string_One_Ring_to_rule_them_all_should_be_Ring);
	MU_RUN_TEST(test_strtrim_passing_ll_for_trim_in_the_string_One_Ring_to_rule_them_all_should_be_e_them_a);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}