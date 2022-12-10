#include "../test.h"

MU_TEST_SUITE(test_tolower_passing_a_char_number_should_be_itself)
{
	//ARRANGE
	int		chr = '5';
	int		returned_result;
	int		expected_result = '5';

	//ACT
	returned_result = ft_tolower(chr);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_tolower_passing_the_letter_Z_uppercase_should_be_z_lowercase)
{
	//ARRANGE
	int		chr = 'Z';
	int		returned_result;
	int		expected_result = 'z';

	//ACT
	returned_result = ft_tolower(chr);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_tolower_passing_the_int_128_should_be_itself)
{
	//ARRANGE
	int		chr = 128;
	int		returned_result;
	int		expected_result = 128;

	//ACT
	returned_result = ft_tolower(chr);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_tolower_passing_z_lowercase_char_should_be_itself)
{
	//ARRANGE
	int		chr = 'z';
	int		returned_result;
	int		expected_result = 'z';

	//ACT
	returned_result = ft_tolower(chr);

	//ASSERT
	mu_assert_int_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_tolower_passing_z_lowercase_char_should_be_itself);
	MU_RUN_TEST(test_tolower_passing_a_char_number_should_be_itself);
	MU_RUN_TEST(test_tolower_passing_the_letter_Z_uppercase_should_be_z_lowercase);
	MU_RUN_TEST(test_tolower_passing_the_int_128_should_be_itself);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}