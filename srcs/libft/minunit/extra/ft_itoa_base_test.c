#include "../test.h"

MU_TEST_SUITE(passing_the_number_10_with_base_HEX_should_be_A)
{
	//ARRANGE
	int			number 				= 10;
	int			base				= 16;
	char		*expected_result	= "A";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa_base(number, base);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(passing_the_number_98_with_base_2_should_be_1100010_string)
{
	//ARRANGE
	int			number				= 98;
	int			base				= 2;
	char		*expected_result	= "1100010";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa_base(number, base);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(passing_the_number_15_with_base_HEX_should_be_F)
{
	//ARRANGE
	int			number 				= 15;
	int			base				= 16;
	char		*expected_result	= "F";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa_base(number, base);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(passing_the_number_9788_with_base_10_should_be_9788_string)
{
	//ARRANGE
	int			number 				= 9788;
	int			base				= 10;
	char		*expected_result	= "9788";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa_base(number, base);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(passing_the_number_MIN_INT_with_base_10_should_be_2147483648_string)
{
	//ARRANGE
	int			number				= (1<<31);
	int			base				= 10;
	char		*expected_result	= "2147483648";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa_base(number, base);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(passing_the_number_MAX_INT_with_base_16_should_be_7FFFFFFF_string)
{
	//ARRANGE
	int			number				= 2147483647;
	int			base				= 16;
	char		*expected_result	= "7FFFFFFF";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa_base(number, base);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(passing_the_number_MAX_INT_with_base_2_should_be_1111111111111111111111111111111_string)
{
	//ARRANGE
	int			number				= ~(1<<31);
	int			base				= 2;
	char		*expected_result	= "1111111111111111111111111111111";
	char		*actual_result;

	//ACT
	actual_result = ft_itoa_base(number, base);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(passing_the_number_10_with_base_HEX_should_be_A);
	MU_RUN_TEST(passing_the_number_98_with_base_2_should_be_1100010_string);
	MU_RUN_TEST(passing_the_number_15_with_base_HEX_should_be_F);
	MU_RUN_TEST(passing_the_number_9788_with_base_10_should_be_9788_string);
	MU_RUN_TEST(passing_the_number_MIN_INT_with_base_10_should_be_2147483648_string);
	MU_RUN_TEST(passing_the_number_MAX_INT_with_base_16_should_be_7FFFFFFF_string);
	MU_RUN_TEST(passing_the_number_MAX_INT_with_base_2_should_be_1111111111111111111111111111111_string);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}