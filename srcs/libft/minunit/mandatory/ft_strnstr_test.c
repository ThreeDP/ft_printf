#include "../test.h"

MU_TEST_SUITE(test_strnstr_passing_a_little_Bar_to_big_Foo_Bar_Baz_with_range_8_should_be_address_index_4)
{
	//ARRANGE
	char	big[] = "Foo Bar Baz";
	char	little[] = "Bar";
	size_t	size = 8;
	char	*expected_result = &big[4];
	char	*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected-result should be the same address");
}

MU_TEST_SUITE(test_strnstr_passing_a_little_Bar_to_big_Foo_Bal_Bar_Baz_with_range_16_should_be_address_index_8)
{
	//ARRANGE
	char	big[] = "Foo Bal Bar Baz";
	char	little[] = "Bar";
	size_t	size = 16;
	char	*expected_result = &big[8];
	char	*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected-result should be the same address");
}

MU_TEST_SUITE(test_strnstr_passing_a_little_Bar_to_big_Foo_Baz_with_range_8_should_be_NULL)
{
	//ARRANGE
	char	big[] = "Foo Baz";
	char	little[] = "Bar";
	size_t	size = 8;
	char	*expected_result = 0;
	char	*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected-result should be the same address");
}

MU_TEST_SUITE(test_strnstr_passing_a_little_empty_string_to_big_Foo_Bar_Baz_with_range_12_should_be_big)
{
	//ARRANGE
	char	big[] = "Foo Bar Baz";
	char	little[] = "";
	size_t	size = 12;
	char	*expected_result = big;
	char	*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected-result should be the same address");
}

MU_TEST_SUITE(test_strnstr_passing_a_little_string_Bar_bigger_then_string_big_Fo_with_range_7_should_be_NULL)
{
	//ARRANGE
	char	big[] = "Fo";
	char	little[] = "Bar";
	size_t	size = 7;
	char	*expected_result = NULL;
	char	*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected-result should be the same address");
}





MU_TEST_SUITE(test_strnstr_passing_a_lorem_ipsum_text_and_search_for_ipsumm_with_size_30)
{
	//ARRANGE
	char	big[] = "lorem ipsum dolor sit amet";
	char	little[] = "ipsumm";
	size_t	size = 30;
	char	*expected_result = NULL;
	char	*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected-result should be NULL");
}

MU_TEST_SUITE(test_strnstr_passing_a_lorem_ipsum_dolor_sit_amet_text_and_search_for_dolor_with_size_15)
{
	//ARRANGE
	char	big[] = "lorem ipsum dolor sit amet";
	char	little[] = "dolor";
	size_t	size = 15;
	char	*expected_result = NULL;
	char	*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected-result should be NULL");
}

MU_TEST_SUITE(test_strnstr_to_find_ora_em_amora_should_return_a_pointer_to_ora_in_amora)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "ora";
	size_t		len = 3;
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should point to address of the char o of amora");
}

MU_TEST_SUITE(test_strnstr_to_find_aro_em_amora_should_return_NULL)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "aro";
	size_t		len = 3;
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_strnstr_if_little_is_empty_string_return_big)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "";
	size_t		len = 3;
	char		*expected_result = big;
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be point to amora first position");
}

MU_TEST_SUITE(test_strnstr_finding_orabolas_in_amora_but_len_3_should_return_pointer_to_ora_in_amora)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "orabolas";
	size_t		len = 3;
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);
	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should point to ora position in amora");
}

MU_TEST_SUITE(test_strnstr_finding_ora_in_amora_but_len_0_should_return_NULL)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "ora";
	size_t		len = 0;
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_strnstr_finding_ora_in_amora_but_len_50_should_return_pointer_to_ora_in_amora)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "ora";
	size_t		len = 50;
	char		*expected_result = &big[2];
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should point to ora position in amora");
}

MU_TEST_SUITE(test_strnstr_finding_ora_in_amorao_but_len_50_should_return_pointer_to_ora_in_amora)
{
	//ARRANGE
	char		big[] = "amorao";
	char		little[] = "ora";
	size_t		len = 50;
	char		*expected_result = &big[2];
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should point to ora position in amora");
}

MU_TEST_SUITE(test_strnstr_finding_orabolas_in_amora_but_len_50_should_return_NULL)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "orabolas";
	size_t		len = 50;
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_strnstr_passing_a_lorem_ipsum_dolor_sit_amet_text_and_search_for_dolor_with_size_15);
	MU_RUN_TEST(test_strnstr_passing_a_lorem_ipsum_text_and_search_for_ipsumm_with_size_30);
	MU_RUN_TEST(test_strnstr_passing_a_little_string_Bar_bigger_then_string_big_Fo_with_range_7_should_be_NULL);
	MU_RUN_TEST(test_strnstr_passing_a_little_empty_string_to_big_Foo_Bar_Baz_with_range_12_should_be_big);
	MU_RUN_TEST(test_strnstr_passing_a_little_Bar_to_big_Foo_Bal_Bar_Baz_with_range_16_should_be_address_index_8);
	MU_RUN_TEST(test_strnstr_passing_a_little_Bar_to_big_Foo_Baz_with_range_8_should_be_NULL);
	MU_RUN_TEST(test_strnstr_passing_a_little_Bar_to_big_Foo_Bar_Baz_with_range_8_should_be_address_index_4);
	MU_RUN_TEST(test_strnstr_to_find_ora_em_amora_should_return_a_pointer_to_ora_in_amora);
	MU_RUN_TEST(test_strnstr_to_find_aro_em_amora_should_return_NULL);
	MU_RUN_TEST(test_strnstr_if_little_is_empty_string_return_big);
	MU_RUN_TEST(test_strnstr_finding_orabolas_in_amora_but_len_3_should_return_pointer_to_ora_in_amora);
	MU_RUN_TEST(test_strnstr_finding_ora_in_amora_but_len_0_should_return_NULL);
	MU_RUN_TEST(test_strnstr_finding_ora_in_amora_but_len_50_should_return_pointer_to_ora_in_amora);
	MU_RUN_TEST(test_strnstr_finding_orabolas_in_amora_but_len_50_should_return_NULL);
	MU_RUN_TEST(test_strnstr_finding_ora_in_amorao_but_len_50_should_return_pointer_to_ora_in_amora);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}