#include "../test.h"

MU_TEST_SUITE(test_memmove_passing_a_dest_plus_5_in_address_of_src_in_the_same_memory_location)
{
	//ARRANGE
	char	src[] = "watermelonjuice";
	char	*dest = src + 5;
	size_t	size = 10;
	char	expected_dest[] = "watermelon";
	char	*returned_dest;

	//ACT
	returned_dest = ft_memmove(dest, src, size);

	//ASSERT
	mu_assert_string_eq(expected_dest, returned_dest);
}

MU_TEST_SUITE(test_memmove_passing_a_dest_lorem_ipsum_and_src_consectetur_should_be_consectetu_dolor_sit_amet)
{
	//ARRANGE
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest = src + 1;
	size_t	size = 10;
	char	expected_dest[] = "consectetu dolor sit amet";
	char	*returned_dest;

	//ACT
	returned_dest = ft_memmove(dest, "consectetur", size);

	//ASSERT
	mu_assert_string_eq(expected_dest, returned_dest);
}

MU_TEST_SUITE(test_memmove_passing_dest_in_the_src_and_the_src_in_the_dest_with_dest_pointer_for_src_plus_1_should_be_orem_ips)
{
	//ARRANGE
							 	
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest = src + 1;
	size_t	size = 8;
	char	expected_dest[] = "orem ipssum dolor sit amet";
	char	*returned_dest;

	//ACT
	returned_dest = ft_memmove(src, dest, size);

	//ASSERT
	mu_assert_string_eq(expected_dest, returned_dest);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_memmove_passing_dest_in_the_src_and_the_src_in_the_dest_with_dest_pointer_for_src_plus_1_should_be_orem_ips);
	MU_RUN_TEST(test_memmove_passing_a_dest_lorem_ipsum_and_src_consectetur_should_be_consectetu_dolor_sit_amet);
	MU_RUN_TEST(test_memmove_passing_a_dest_plus_5_in_address_of_src_in_the_same_memory_location);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}