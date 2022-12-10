#include "../test.h"

MU_TEST_SUITE(test_calloc_passing_array_type_char_with_5_bytes_should_be_5_bytes_zero)
{
	//ARRANGE
	size_t	nmemb = 5;
	size_t	size_type = sizeof(char);
	char	*expected_result = (char *) calloc(nmemb, size_type);
	char	*actual_result;
	size_t	i;

	//ACT
	actual_result = (char *)ft_calloc(nmemb, size_type);

	//ASSERT
	i = 0;
	while (i < (nmemb * size_type))
	{
		mu_assert_int_eq(expected_result[i], actual_result[i]);
		i++;
	}
	free(expected_result);
	free(actual_result);
}

MU_TEST_SUITE(test_calloc_passing_array_type_char_with_6_bytes_should_be_6_bytes_zero)
{
	//ARRANGE
	size_t	nmemb = 6;
	size_t	size_type = sizeof(char);
	char	*expected_result = (char *) calloc(nmemb, size_type);
	char	*actual_result;
	size_t	i;

	//ACT
	actual_result = (char *)ft_calloc(nmemb, size_type);

	//ASSERT
	i = 0;
	while (i < (nmemb * size_type))
	{
		mu_assert_int_eq(expected_result[i], actual_result[i]);
		i++;
	}
	free(expected_result);
	free(actual_result);
}

MU_TEST_SUITE(test_calloc_passing_array_type_char_with_nmemb_zero_should_be_NULL)
{
	//ARRANGE
	size_t	nmemb = 0;
	size_t	size_type = sizeof(int);
	int		*expected_result = NULL;
	int		*actual_result;

	//ACT
	actual_result = (int *)ft_calloc(nmemb, size_type);

	//ASSERT
	mu_assert(expected_result == actual_result, "Expected actual result should be NULL");
	free(actual_result);
}

MU_TEST_SUITE(test_calloc_passing_array_size_0_with_nmemb_2_should_be_NULL)
{
	//ARRANGE
	size_t	nmemb = 2;
	size_t	size_type = 0;
	int		*expected_result = NULL;
	int		*actual_result;

	//ACT
	actual_result = (int *)ft_calloc(nmemb, size_type);

	//ASSERT
	mu_assert(expected_result == actual_result, "Expected actual result should be NULL");
	free(actual_result);
}

MU_TEST_SUITE(test_calloc_passing_array_int_with_nmemb_MAX_INT_should_be_killed)
{
	//ARRANGE
	size_t	nmemb = ~(1<<31);
	size_t	size_type = sizeof(int);
	int		*expected_result = NULL;
	int		*actual_result;

	//ACT
	actual_result = (int *)ft_calloc(nmemb, size_type);

	//ASSERT
	mu_assert(expected_result == actual_result, "Expected actual result should be NULL");
	free(actual_result);
}

MU_TEST_SUITE(test_calloc_passing_array_MAX_INT_with_nmemb_MAX_INT_should_be_NULL)
{
	//ARRANGE
	size_t	nmemb = ~(1<<31);
	size_t	size_type = ~(1<<31);
	int		*expected_result = NULL;
	int		*actual_result;

	//ACT
	actual_result = (int *)ft_calloc(nmemb, size_type);

	//ASSERT
	mu_assert(expected_result == actual_result, "Expected actual result should be NULL");
	free(actual_result);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_calloc_passing_array_MAX_INT_with_nmemb_MAX_INT_should_be_NULL);
    MU_RUN_TEST(test_calloc_passing_array_int_with_nmemb_MAX_INT_should_be_killed);
	MU_RUN_TEST(test_calloc_passing_array_size_0_with_nmemb_2_should_be_NULL);
	MU_RUN_TEST(test_calloc_passing_array_type_char_with_nmemb_zero_should_be_NULL);
	MU_RUN_TEST(test_calloc_passing_array_type_char_with_5_bytes_should_be_5_bytes_zero);
	MU_RUN_TEST(test_calloc_passing_array_type_char_with_6_bytes_should_be_6_bytes_zero);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}