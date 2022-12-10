#include "../test.h"

MU_TEST_SUITE(test_isalnum_passing_asterisk_should_be_false)
{
	//ARRANGE
	int		letter = '*';
	int		expected_result = 0;
	int		returned_result;

	//ACT
	returned_result = ft_isalnum(letter);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_isalnum_passing_number_should_be_true)
{
	//ARRANGE
	int		letter = '9';
	int		returned_result;

	//ACT
	returned_result = ft_isalnum(letter);

	//ASSERT
	mu_assert(returned_result > 0, "expected_result should be NULL");
}

MU_TEST_SUITE(test_isalnum_passing_letter_should_be_true)
{
	//ARRANGE
	int		letter = 'A';
	int		returned_result;

	//ACT
	returned_result = ft_isalnum(letter);

	//ASSERT
	mu_assert(returned_result > 0, "expected_result should be NULL");
}

MU_TEST_SUITE(test_isalnum_passing_out_of_the_range_should_be_zero)
{
	//ARRANGE
	int		letter = 128;
	int		expected_result = 0;
	int		returned_result;

	//ACT
	returned_result = ft_isalnum(letter);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_isalnum_passing_out_of_the_range_should_be_zero);
	MU_RUN_TEST(test_isalnum_passing_letter_should_be_true);
	MU_RUN_TEST(test_isalnum_passing_asterisk_should_be_false);
	MU_RUN_TEST(test_isalnum_passing_number_should_be_true);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}