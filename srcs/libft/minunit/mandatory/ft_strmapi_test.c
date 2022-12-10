#include "../test.h"

char	add_one(unsigned int i, char c)
{
	return (c + i);
}

MU_TEST_SUITE(passing_a_string_1234_should_be_1357)
{
	//ARRANGE
	char	str[] = "1234";
	char	expected_result[] = "1357";
	char	*actual_result;

	//ACT
	actual_result = ft_strmapi(str, add_one);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(passing_a_string_1234_should_be_1357);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}