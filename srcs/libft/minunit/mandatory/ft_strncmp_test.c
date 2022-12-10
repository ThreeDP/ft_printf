#include "../test.h"

MU_TEST_SUITE(test_strncmp_passing_two_strings_DIA_compare_to_DIA_with_range_three_and_should_be_zero)
{
	//ARRANGE
	char	s1[] = "DIA";
	char	s2[] = "DIA";
	size_t	size = 3;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(s1, s2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strncmp_passing_two_strings_DIA_bar_200_compare_to_DIA_bar_0_with_range_5_and_should_be_1)
{
	//ARRANGE
	char	s1[] = "DIA\200";
	char	s2[] = "DIA\0";
	size_t	size = 5;
	int		expected_result = 128;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(s1, s2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strncmp_passing_two_strings_LUA_compare_to_MUA_with_range_three_and_should_be_one_less)
{
	//ARRANGE
	char	s1[] = "LUA";
	char	s2[] = "MUA";
	size_t	size = 3;
	int		expected_result = -1;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(s1, s2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strncmp_passing_two_empty_strings_and_range_3_should_be_zero)
{
	//ARRANGE
	char	s1[] = "";
	char	s2[] = "";
	size_t	size = 3;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(s1, s2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strncmp_passing_two_strings_index_4_with_a_diff_inside_the_index_4_with_range_3)
{
	//ARRANGE
	char	s1[] = "LUA1";
	char	s2[] = "LUA2";
	size_t	size = 3;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(s1, s2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strncmp_passing_two_strings_equal_with_range_zero)
{
	//ARRANGE
	char	s1[] = "LUA";
	char	s2[] = "LUA";
	size_t	size = 0;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(s1, s2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_strncmp_passing_two_strings_DIA_bar_200_compare_to_DIA_bar_0_with_range_5_and_should_be_1);
	MU_RUN_TEST(test_strncmp_passing_two_strings_equal_with_range_zero);
	MU_RUN_TEST(test_strncmp_passing_two_strings_index_4_with_a_diff_inside_the_index_4_with_range_3);
	MU_RUN_TEST(test_strncmp_passing_two_empty_strings_and_range_3_should_be_zero);
	MU_RUN_TEST(test_strncmp_passing_two_strings_LUA_compare_to_MUA_with_range_three_and_should_be_one_less);
	MU_RUN_TEST(test_strncmp_passing_two_strings_DIA_compare_to_DIA_with_range_three_and_should_be_zero);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}