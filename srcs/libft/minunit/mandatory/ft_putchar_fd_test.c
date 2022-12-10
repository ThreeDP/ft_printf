/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:51:53 by dapaulin          #+#    #+#             */
/*   Updated: 2022/12/07 18:51:53 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

static int  setup(char *file, int *fd)
{
    *fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!*fd)
        return (0);
    return (1);
}

static char *unset(char *file, int fd)
{
	char    buf[2];

	close(fd);
	fd = open(file, O_RDONLY);
	read(fd, buf, 2);
    buf[1] = '\0';
	remove(file);
	return (ft_strdup(buf));
}

MU_TEST_SUITE(passing_a_char_D_should_be_1)
{
	//ARRANGE
	int         fd;
	int         size;
	char        *str;
	char        *file               = "./files/D";
	char        input               = 'D';
	char        *exp_str            = "D";
	int         exp_size            = 1;

	//ACT
	setup(file, &fd);
	size = ft_putchar_fd(input, fd);

	//ASSERT
	str = unset(file, fd);
	mu_assert_int_eq(exp_size, size);
	mu_assert_string_eq(exp_str, str);
}

MU_TEST_SUITE(passing_a_char_backslash_0_should_be_empty)
{
	//ARRANGE
	int         fd;
	int         size;
	char        *str;
	char        *file               = "./files/empty";
	char        input               = '\0';
	char        *exp_str            = "";
	int         exp_size            = 1;

	//ACT
	setup(file, &fd);
	size = ft_putchar_fd(input, fd);

	//ASSERT
	str = unset(file, fd);
	mu_assert_int_eq(exp_size, size);
	mu_assert_string_eq(exp_str, str);
}

MU_TEST_SUITE(passing_a_invalid_fd_should_be_minus_1)
{
	//ARRANGE
	int         size;
	int         fd                  = 1001;
	char        input               = 'D';
	int         exp_size            = -1;

	//ACT
	size = ft_putchar_fd(input, fd);

	//ASSERT
	mu_assert_int_eq(exp_size, size);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(passing_a_char_D_should_be_1);
    MU_RUN_TEST(passing_a_char_backslash_0_should_be_empty);
    MU_RUN_TEST(passing_a_invalid_fd_should_be_minus_1);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
