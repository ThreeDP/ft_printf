#include "../test.h"

MU_TEST_SUITE(test_func_memchr_locating_R_inside_AURORA_should_return_first_R_position)
{
	//ARRANGE
	char	string[] = "AURORA";
	int		find = 'R';
	size_t	size = 6;
	char	*expected_result = &string[2];
	char	*actual_result;

	//ACT]
	actual_result = ft_memchr(string, find, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be the same address");
}

MU_TEST_SUITE(test_func_memchr_locating_O_inside_AURORA_should_return_O_position)
{
	//ARRANGE
	char	string[] = "AURORA";
	int		find = 'O';
	size_t	size = 6;
	char	*expected_result = &string[3];
	char	*actual_result;

	//ACT
	actual_result = ft_memchr(string, find, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be the same address");
}

MU_TEST_SUITE(test_func_memchr_locating_X_inside_AURORA_should_return_NULL)
{
	//ARRANGE
	char	string[] = "AURORA";
	int		find = 'X';
	size_t	size = 6;
	char	*expected_result = 0;
	char	*actual_result;

	//ACT
	actual_result = ft_memchr(string, find, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_func_memchr_locating_O_inside_AURORA_with_a_range_of_3_should_return_NULL)
{
	//ARRANGE
	char	string[] = "AURORA";
	int		find = 'O';
	size_t	size = 3;
	char	*expected_result = 0;
	char	*actual_result;

	//ACT
	actual_result = ft_memchr(string, find, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_func_memchr_passing_size_0_should_return_NULL)
{
	//ARRANGE
	char	string[] = "AURORA";
	int		find = 'O';
	size_t	size = 0;
	char	*expected_result = 0;
	char	*actual_result;

	//ACT
	actual_result = ft_memchr(string, find, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}


// Why this test works ? i really do'nt undestand
MU_TEST_SUITE(test_func_memchr_passing_a_array_int_with_7_elements_should_be_a_pointer_for_3_index)
{
	//ARRANGE
	int 	tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	int		find = -1;
	size_t	size = 7;
	int		*expected_result = memchr(tab, find, size);
	int		*actual_result;

	//ACT
	actual_result = ft_memchr(tab, find, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be pointer for index 3");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_func_memchr_passing_a_array_int_with_7_elements_should_be_a_pointer_for_3_index);
	MU_RUN_TEST(test_func_memchr_passing_size_0_should_return_NULL);
	MU_RUN_TEST(test_func_memchr_locating_O_inside_AURORA_with_a_range_of_3_should_return_NULL);
	MU_RUN_TEST(test_func_memchr_locating_X_inside_AURORA_should_return_NULL);
	MU_RUN_TEST(test_func_memchr_locating_O_inside_AURORA_should_return_O_position);
	MU_RUN_TEST(test_func_memchr_locating_R_inside_AURORA_should_return_first_R_position);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}