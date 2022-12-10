#include "../test.h"

MU_TEST_SUITE(test_strjoin_concat_One_with_Ring_should_be_One_Ring)
{
	//ARRANGE
	char	s1[] = "One ";
	char	s2[] = "Ring";
	char	expected_result[] = "One Ring";
	char	*actual_result;

	//ACT
	actual_result = ft_strjoin(s1, s2);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test_strjoin_concat_One_Ring_to_rule_them_all_should_be_One_Ring_to_rule_them_all)
{
	//ARRANGE
	char	s1[] = "One Ring ";
	char	s2[] = "to rule them all";
	char	expected_result[] = "One Ring to rule them all";
	char	*actual_result;

	//ACT
	actual_result = ft_strjoin(s1, s2);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_strjoin_concat_One_Ring_to_rule_them_all_should_be_One_Ring_to_rule_them_all);
	MU_RUN_TEST(test_strjoin_concat_One_with_Ring_should_be_One_Ring);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}