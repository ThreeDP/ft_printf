#include "../test.h"

MU_TEST_SUITE(test_func_bzero_fill_5_positions_in_a_string_of_7_bytes)
{
	//ARRANGE
	char	string[] = "abacate";
	char	expected_result[] = "\0\0\0\0\0te";
	size_t	position = 5;
	size_t	i = 0;

	//ACT
	ft_bzero(string, position);

	//ASSERT
	while (i < 7)
	{
		mu_assert_int_eq(expected_result[i], string[i]);
		i++;
	}
}

MU_TEST_SUITE(test_func_bzero_fill_7_positions_in_a_string_of_7_bytes)
{
	//ARRANGE
	char	string[] = "abacate";
	char	expected_result[] = "\0\0\0\0\0\0\0";
	size_t	position = 7;
	size_t	i = 0;

	//ACT
	ft_bzero(string, position);

	//ASSERT
	while (i < 7)
	{
		mu_assert_int_eq(expected_result[i], string[i]);
		i++;
	}
}

MU_TEST_SUITE(test_func_bzero_fill_7_positions_in_a_array_int_with_28_bytes)
{
	//ARRANGE
	int		array[] = {1, 2, 3, 4, 5, 6, 7};
	char	expected_result[] = {0, 0, 0, 0, 0, 0, 0};
	size_t	position = 7;
	size_t	i = 0;

	//ACT
	ft_bzero(array, sizeof(int) * position);

	//ASSERT
	while (i < 7)
	{
		mu_assert_int_eq(expected_result[i], array[i]);
		i++;
	}
}

MU_TEST_SUITE(test_func_bzero_fill_0_positions_in_a_array_int_with_28_bytes)
{
	//ARRANGE
	int		array[] = {1, 2, 3, 4, 5, 6, 7};
	char	expected_result[] = {1, 2, 3, 4, 5, 6, 7};
	size_t	position = 0;
	size_t	i = 0;

	//ACT
	ft_bzero(array, sizeof(int) * position);

	//ASSERT
	while (i < 7)
	{
		mu_assert_int_eq(expected_result[i], array[i]);
		i++;
	}
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_func_bzero_fill_7_positions_in_a_string_of_7_bytes);
	MU_RUN_TEST(test_func_bzero_fill_7_positions_in_a_array_int_with_28_bytes);
	MU_RUN_TEST(test_func_bzero_fill_0_positions_in_a_array_int_with_28_bytes);
	MU_RUN_TEST(test_func_bzero_fill_5_positions_in_a_string_of_7_bytes);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}