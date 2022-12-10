#include "../test.h"

MU_TEST_SUITE(test_strlcpy_entering_ai_oi_2_set_dst_as_o_and_returns_2)
{
	//ARRANGE
	char	dst[] = "ai";
	char	src[] = "oi";
	int		size = 2;
	int		expected_result = 2;
	char	expected_dst[] = "o";
	int		actual_result;

	//ACT
	actual_result = ft_strlcpy(dst, src, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq(expected_dst, dst);
}

MU_TEST_SUITE(test_strlcpy_entering_ah_oi_3_set_dst_as_oi_and_returns_2)
{
	//ARRANGE
	char	dst[] = "ah";
	char	src[] = "oi";
	int		size = 3;
	int		expected_result = 2;
	char	expected_dst[] = "oi";
	int		actual_result;

	//ACT
	actual_result = ft_strlcpy(dst, src, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq(expected_dst, dst);
}

MU_TEST_SUITE(test_strlcpy_entering_ah_boi_3_set_dst_as_bo_and_returns_3)
{
	//ARRANGE
	char	dst[] = "ah";
	char	src[] = "boi";
	int		size = 3;
	int		expected_result = 3;
	char	expected_dst[] = "bo";
	int		actual_result;

	//ACT
	actual_result = ft_strlcpy(dst, src, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq(expected_dst, dst);
}

MU_TEST_SUITE(test_strlcpy_entering_papelada_boiada_9_keep_dst7_as_a)
{
	//ARRANGE
	char	dst[] = "papelada";
	char	src[] = "boiada";
	int		size = 9;

	//ACT
	ft_strlcpy(dst, src, size);

	//ASSERT
	mu_assert_int_eq('a', dst[7]);
}

MU_TEST_SUITE(test_strlcpy_entering_lu_la_minus_1_set_dst_as_la_and_returns_2)
{
	//ARRANGE
	char	dst[] = "lu";
	char	src[] = "la";
	int		size = -1;
	int		expected_result = 2;
	char	expected_dst[] = "la";
	int		actual_result;

	//ACT
	actual_result = ft_strlcpy(dst, src, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq(expected_dst, dst);
}

MU_TEST_SUITE(test_strlcpy_entering_mochida_rapdos_0_do_not_modify_dst_and_returns_6)
{
	//ARRANGE
	char	dst[] = "mochida";
	char	src[] = "rapdos";
	int		size = 0;
	int		expected_result = 6;
	char	expected_dst[] = "mochida";
	int		actual_result;

	//ACT
	actual_result = ft_strlcpy(dst, src, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq(expected_dst, dst);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_strlcpy_entering_mochida_rapdos_0_do_not_modify_dst_and_returns_6);
	MU_RUN_TEST(test_strlcpy_entering_lu_la_minus_1_set_dst_as_la_and_returns_2);
	MU_RUN_TEST(test_strlcpy_entering_papelada_boiada_9_keep_dst7_as_a);
	MU_RUN_TEST(test_strlcpy_entering_ai_oi_2_set_dst_as_o_and_returns_2);
	MU_RUN_TEST(test_strlcpy_entering_ah_boi_3_set_dst_as_bo_and_returns_3);
	MU_RUN_TEST(test_strlcpy_entering_ah_oi_3_set_dst_as_oi_and_returns_2);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}