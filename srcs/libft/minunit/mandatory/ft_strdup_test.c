#include "../test.h"

MU_TEST_SUITE(test_strdup_passing_largatixa_should_be_pointer_to_index_1_of_largatixa_copy)
{
	//ARRANGE
	char	src[] = "largatixa";
	char	*expected_dest = &src[0];
	char	*actual_result;

	//ACT
	actual_result = ft_strdup(src);

	//ASSERT
	mu_assert_string_eq(expected_dest, actual_result);
	mu_assert(expected_dest != actual_result, "The result of actual_result should be different of src!!");
	free(actual_result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_strdup_passing_largatixa_should_be_pointer_to_index_1_of_largatixa_copy);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}