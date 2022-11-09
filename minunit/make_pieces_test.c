#include "minunit.h"
#include "../srcs/get_next_line.h"

MU_TEST_SUITE(passing_file_file_43_with_nl_should_be_2_content_with_size_42_and_1_1_content_with_size_1_and_NULL)
{
	//ARRANGE
    int			fd						= open("./files/43_with_nl", O_RDONLY);
    t_list		*lst	        	    = ft_lstnew(NULL, 0);
    size_t      string_size;
	static char	buffer[BUFFER_SIZE];
    char        *expected_buffer1       = "7";
    char        *expected_buffer2       = "\0";
    char        *expected_buffer3       = "\0";

    //ACT
    if (fd == -1)
		return ;

	//ASSERT
    /* 1 */
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("012345678901234567890123456789012345678901", lst-> content);
    lst = lst-> next;
    mu_assert_string_eq("\n", lst-> content);
    mu_assert_int_eq(43, string_size);
    mu_assert_string_eq(expected_buffer1, buffer);
    ft_lstclear(&lst, free);
    /* 2 */
    lst	        	    = ft_lstnew(NULL, 0);
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("7", lst-> content);
    mu_assert_int_eq(1, string_size);
    mu_assert_string_eq(expected_buffer2, buffer);
    ft_lstclear(&lst, free);
    /* 3 */
    lst	        	    = ft_lstnew(NULL, 0);
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("", lst-> content);
    mu_assert_int_eq(0, string_size);
    mu_assert_string_eq(expected_buffer3, buffer);
    ft_lstclear(&lst, free);
	close(fd);
}

MU_TEST_SUITE(passing_a_file_with_5_concurrent_nl_should_be_5_lines_and_final_null)
{
	//ARRANGE
    int			fd						= open("./files/multiple_nlx5", O_RDONLY);
    t_list		*lst	        	    = ft_lstnew(NULL, 0);
    size_t      string_size;
	static char	buffer[BUFFER_SIZE];
    char        *expected_buffer1       = "\n\n\n\n";
    char        *expected_buffer2       = "\n\n\n";
    char        *expected_buffer3       = "\n\n";
    char        *expected_buffer4       = "\n";
    char        *expected_buffer5       = "\0";
    char        *expected_buffer6       = "\0";

    //ACT
    if (fd == -1)
		return ;

	//ASSERT
    /* 1 */
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("\n", lst-> content);
    mu_assert_int_eq(1, string_size);
    mu_assert_string_eq(expected_buffer1, buffer);
    ft_lstclear(&lst, free);
    /* 2 */
    lst	        	    = ft_lstnew(NULL, 0);
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("\n", lst-> content);
    mu_assert_int_eq(1, string_size);
    mu_assert_string_eq(expected_buffer2, buffer);
    ft_lstclear(&lst, free);
    /* 3 */
    lst	        	    = ft_lstnew(NULL, 0);
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("\n", lst-> content);
    mu_assert_int_eq(1, string_size);
    mu_assert_string_eq(expected_buffer3, buffer);
    ft_lstclear(&lst, free);
    /* 4 */
    lst	        	    = ft_lstnew(NULL, 0);
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("\n", lst-> content);
    mu_assert_int_eq(1, string_size);
    mu_assert_string_eq(expected_buffer4, buffer);
    ft_lstclear(&lst, free);
    /* 5 */
    lst	        	    = ft_lstnew(NULL, 0);
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("\n", lst-> content);
    mu_assert_int_eq(1, string_size);
    mu_assert_string_eq(expected_buffer5, buffer);
    ft_lstclear(&lst, free);
    /* 4 */
    lst	        	    = ft_lstnew(NULL, 0);
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("", lst-> content);
    mu_assert_int_eq(0, string_size);
    mu_assert_string_eq(expected_buffer6, buffer);
    ft_lstclear(&lst, free);
	close(fd);
}

MU_TEST_SUITE(passing_a_file_with_a_string_with_71_bytes_and_no_new_line_should_be_2_contents_one_with_42_bytes_other_with_29)
{
	//ARRANGE
    int			fd						= open("./files/71_no_nl", O_RDONLY);
    t_list		*lst	        	    = ft_lstnew(NULL, 0);
    size_t      string_size;
	static char	buffer[BUFFER_SIZE];
    char        *expected_buffer1       = "";
    char        *expected_buffer2       = "\0";

    //ACT
    if (fd == -1)
		return ;

	//ASSERT
    /* 1 */
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("Para olhos tortos, a realidade pode ter um", lst-> content);
    lst = lst-> next;
    mu_assert_string_eq(" rosto desvirtuado - Gandalf.", lst-> content);
    mu_assert_int_eq(71, string_size);
    mu_assert_string_eq(expected_buffer1, buffer);
    ft_lstclear(&lst, free);
    /* 4 */
    lst	        	    = ft_lstnew(NULL, 0);
    check_static(fd, buffer, &lst);
    string_size = make_pieces(fd, buffer, &lst);
    mu_assert_string_eq("", lst-> content);
    mu_assert_int_eq(0, string_size);
    mu_assert_string_eq(expected_buffer2, buffer);
    ft_lstclear(&lst, free);
	close(fd);
}

MU_TEST_SUITE(test_suite)
{	
    MU_RUN_TEST(passing_a_file_with_a_string_with_71_bytes_and_no_new_line_should_be_2_contents_one_with_42_bytes_other_with_29);
    MU_RUN_TEST(passing_file_file_43_with_nl_should_be_2_content_with_size_42_and_1_1_content_with_size_1_and_NULL);
    MU_RUN_TEST(passing_a_file_with_5_concurrent_nl_should_be_5_lines_and_final_null);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}