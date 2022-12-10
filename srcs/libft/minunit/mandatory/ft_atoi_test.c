#include "../test.h"

MU_TEST_SUITE(test_atoi_passing_a_character_0_should_be_a_int_zero)
{
	//ARRANGE
	char		str[] = "0";
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_atoi(str);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_atoi_passing_a_string_123_should_be_123_int)
{
	//ARRANGE
	char	str[] = "123";
	int		expected_result = 123;
	int		actual_result;

	//ACT
	actual_result = ft_atoi(str);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_atoi_passing_a_string_minus_123_should_be_minus_123_int)
{
	//ARRANGE
	char	str[] = "-123";
	int		expected_result = -123;
	int		actual_result;

	//ACT
	actual_result = ft_atoi(str);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_atoi_passing_a_string_with_spaces_123_should_be_123_int)
{
	//ARRANGE
	char	str[] = "     123";
	int		expected_result = 123;
	int		actual_result;

	//ACT
	actual_result = ft_atoi(str);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_atoi_passing_a_string_with_spaces_t123_should_be_zero)
{
	//ARRANGE
	char	str[] = "     t123";
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_atoi(str);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_atoi_passing_a_string_with_MAX_POS_should_be_2147483647)
{
	//ARRANGE
	char	str[] = "2147483647";
	int		expected_result = ~(1<<31);
	int		actual_result;

	//ACT
	actual_result = ft_atoi(str);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_atoi_passing_a_string_with_MAX_POS_should_be_minus_2147483648)
{
	//ARRANGE
	char	str[] = "-2147483648";
	int		expected_result = (1<<31);
	int		actual_result;

	//ACT
	actual_result = ft_atoi(str);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_atoi_passing_a_string_with_MAX_POS_should_be_minus_2147483648);
	MU_RUN_TEST(test_atoi_passing_a_string_with_MAX_POS_should_be_2147483647);
	MU_RUN_TEST(test_atoi_passing_a_string_with_spaces_t123_should_be_zero);
	MU_RUN_TEST(test_atoi_passing_a_string_with_spaces_123_should_be_123_int);
	MU_RUN_TEST(test_atoi_passing_a_string_minus_123_should_be_minus_123_int);
	MU_RUN_TEST(test_atoi_passing_a_string_123_should_be_123_int);
	MU_RUN_TEST(test_atoi_passing_a_character_0_should_be_a_int_zero);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}