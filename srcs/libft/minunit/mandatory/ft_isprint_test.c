#include "../test.h"

MU_TEST_SUITE(test_enter_caracter_new_line_in_func_isprint)
{
	//ARRANGE
	int	letter = 10;
	int	returned_result;

	//ACT
	returned_result = ft_isprint(letter);

	//ASSERT
	mu_assert(returned_result == 0, "the returned result should be FALSE");
}

MU_TEST_SUITE(test_enter_caracter_space_in_func_isprint)
{
	//ARRANGE
	int	letter = 32;
	int	returned_result;

	//ACT
	returned_result = ft_isprint(letter);

	//ASSERT
	mu_assert(returned_result > 0, "the returned result should be TRUE");
}

MU_TEST_SUITE(test_enter_caracter_NULL_in_func_isprint)
{
	//ARRANGE
	int	letter = 0;
	int	returned_result;

	//ACT
	returned_result = ft_isprint(letter);

	//ASSERT
	mu_assert(returned_result == 0, "the returned result should be FALSE");
}

MU_TEST_SUITE(test_enter_caracter_asterisk_in_func_isprint)
{
	//ARRANGE
	int	letter = 42;
	int	returned_result;

	//ACT
	returned_result = ft_isprint(letter);

	//ASSERT
	mu_assert(returned_result > 0, "the returned result should be TRUE");
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_enter_caracter_new_line_in_func_isprint);
	MU_RUN_TEST(test_enter_caracter_space_in_func_isprint);
	MU_RUN_TEST(test_enter_caracter_NULL_in_func_isprint);
	MU_RUN_TEST(test_enter_caracter_asterisk_in_func_isprint);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}