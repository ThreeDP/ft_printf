#include "../test.h"

MU_TEST_SUITE(test_itoa_passing_the_number_one_should_be_1_string)
{
	//ARRANGE
	int			number = 1;
	char		expected_result[] = "1";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa(number);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test_itoa_passing_the_number_98_should_be_98_string)
{
	//ARRANGE
	int			number = 98;
	char		expected_result[] = "98";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa(number);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test_itoa_passing_the_number_9788_should_be_9788_string)
{
	//ARRANGE
	int			number = 9788;
	char		expected_result[] = "9788";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa(number);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test_itoa_passing_the_number_MIN_INT_should_be_minus_2147483648_string)
{
	//ARRANGE
	int			number = (1<<31);
	char		expected_result[] = "-2147483648";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa(number);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test_itoa_passing_the_number_minus_9788_should_be_minus_9788_string)
{
	//ARRANGE
	int			number = -9788;
	char		expected_result[] = "-9788";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa(number);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test_itoa_passing_the_number_MAX_INT_should_be_2147483648_string)
{
	//ARRANGE
	int			number = ~(1<<31);
	char		expected_result[] = "2147483647";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa(number);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_itoa_passing_the_number_MAX_INT_should_be_2147483648_string);
	MU_RUN_TEST(test_itoa_passing_the_number_MIN_INT_should_be_minus_2147483648_string);
	MU_RUN_TEST(test_itoa_passing_the_number_minus_9788_should_be_minus_9788_string);
	MU_RUN_TEST(test_itoa_passing_the_number_one_should_be_1_string);
	MU_RUN_TEST(test_itoa_passing_the_number_98_should_be_98_string);
	MU_RUN_TEST(test_itoa_passing_the_number_9788_should_be_9788_string);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}