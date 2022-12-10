#include "../test.h"

MU_TEST_SUITE(test_func_memset_fill_5_bytes_of_a_string_with_7_bytes_array_type_char)
{
	//ARRANGE
	char	string[] = "abacate";
	char	*expected_result = "*****te";
	int		character = 42;
	size_t	position = 5;
	char	*returned_result;

	//ACT
	returned_result = ft_memset(string, character, position);

	//ASSERT
	mu_assert_string_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_func_memset_fill_7_bytes_of_a_string_with_7_bytes_array_type_char)
{
	//ARRANGE
	char	string[] = "abacate";
	char	expected_result[] = "*******";
	int		character = 42;
	size_t	position = 7;
	char	*returned_result;

	//ACT
	returned_result = ft_memset(string, character, position);

	//ASSERT
	mu_assert_string_eq(expected_result, returned_result);
}

MU_TEST_SUITE(test_func_memset_fill_5_bytes_of_a_array_int_with_28_bytes)
{
	//ARRANGE
	int		array[] = {1, 2, 3, 4, 5, 6, 7};
	int		expected_result[] = {0, 0, 0, 0, 0, 6, 7};
	int		character = 0;
	size_t	position = 5;
	int		*returned_result;
	size_t	i = 0;

	//ACT
	returned_result = ft_memset(array, character, sizeof(int) * position);

	//ASSERT
	while (i < position)
	{
		mu_assert_int_eq(expected_result[i], returned_result[i]);
		i++;
	}
}

MU_TEST_SUITE(test_func_memset_fill_0_bytes_of_a_array_int_with_28_bytes)
{
	//ARRANGE
	int		array[] = {1, 2, 3, 4, 5, 6, 7};
	int		expected_result[] = {0, 0, 0, 0, 0, 6, 7};
	int		character = 0;
	size_t	position = 0;
	int		*returned_result;
	size_t	i = 0;

	//ACT
	returned_result = ft_memset(array, character, sizeof(int) * position);

	//ASSERT
	while (i < position)
	{
		mu_assert_int_eq(expected_result[i], returned_result[i]);
		i++;
	}
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_func_memset_fill_5_bytes_of_a_string_with_7_bytes_array_type_char);
    MU_RUN_TEST(test_func_memset_fill_7_bytes_of_a_string_with_7_bytes_array_type_char);
	MU_RUN_TEST(test_func_memset_fill_5_bytes_of_a_array_int_with_28_bytes);
	MU_RUN_TEST(test_func_memset_fill_0_bytes_of_a_array_int_with_28_bytes);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}