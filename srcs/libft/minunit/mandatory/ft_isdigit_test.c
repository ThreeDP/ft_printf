#include "../test.h"

MU_TEST_SUITE(test_isdigit_entering_c_returns_false)
{
	//ARRANGE
	int		input = 'c';
	int		expected_result = 0; // false
	int		actual_result;

	//ACT
	actual_result = ft_isdigit(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_isdigit_entering_c_returns_false);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}