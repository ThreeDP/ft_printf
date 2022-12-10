#include "../test.h"

MU_TEST_SUITE(test_func_memcpy_copy_a_string_of_5_char_in_a_string_of_5_char_in_differents_memory_locations)
{
	//ARRANGE
	char	src[] = "1234";
	char	dest[5];
	size_t	size = 5;
	char	expected_dest[] = "1234";
	char	*returned_dest;

	//ACT
	returned_dest = ft_memcpy(dest, src, size);

	//ASSERT
	mu_assert_string_eq(expected_dest, returned_dest);
}

// Qual O motivo desse comportamento ?
MU_TEST_SUITE(test_func_memcpy_copy_a_string_of_6_char_in_a_string_of_5_char_in_differents_memory_locations)
{
	//ARRANGE
	char	src[] = "12345";
	char	dest[5];
	size_t	size = 5;
	char	expected_dest[] = "1234512345";
	char	*returned_dest;

	//ACT
	returned_dest = ft_memcpy(dest, src, size);

	//ASSERT
	mu_assert_string_eq(expected_dest, returned_dest);
}

MU_TEST_SUITE(test_memcpy_passing_a_dest_plus_5_in_address_of_src_in_the_same_memory_location)
{
	//ARRANGE
	char	src[] = "watermelonjuice";
	char	*dest = src + 5;
	size_t	size = 10;
	char	expected_dest[] = "waterwater";
	char	*returned_dest;

	//ACT
	returned_dest = ft_memcpy(dest, src, size);

	//ASSERT
	mu_assert_string_eq(expected_dest, returned_dest);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_func_memcpy_copy_a_string_of_5_char_in_a_string_of_5_char_in_differents_memory_locations);
	MU_RUN_TEST(test_func_memcpy_copy_a_string_of_6_char_in_a_string_of_5_char_in_differents_memory_locations);
	MU_RUN_TEST(test_memcpy_passing_a_dest_plus_5_in_address_of_src_in_the_same_memory_location);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}