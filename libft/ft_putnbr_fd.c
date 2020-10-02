/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 03:19:27 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 04:09:18 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

char	path[1024];

t_bool	do_test(int n, char *s)
{
	int		fd;
	char	check[1024];
	size_t	len = strlen(s);
	size_t	readbytes;

	fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
	{
		write(STDERR_FILENO, "[Failed] Cannot open a temp file as write only mode.\n", 53);
		return (FALSE);
	}
	ft_putnbr_fd(n, fd);
	close(fd);

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(STDERR_FILENO, "[Failed] Cannot open a temp file as read only mode.\n", 52);
		return (FALSE);
	}
	if ((readbytes = read(fd, check, len)) <= 0)
	{
		write(STDERR_FILENO, "[Failed] Cannot read any data from a temp file.\n", 48);
		return (FALSE);
	}
	close(fd);

	t_bool	result = memcmp(check, s, len) == 0;
	if (!result)
	{
		write(STDERR_FILENO, "[Failed] Invalid printed number.\nYour Result:", 45);
		write(STDERR_FILENO, check, readbytes);
		write(STDERR_FILENO, "\nExpected: ", 11);
		write(STDERR_FILENO, s, len);
		write(STDERR_FILENO, "\n", 1);
	}
	return (result);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (strlen(argv[1]) > 1000)
		return (ENAMETOOLONG);
	strlcpy(path, argv[1], 1024);
	strlcat(path, "/test_output", 1024);
	if (!do_test(3, "3"))
		return (1);
	if (!do_test(-3, "-3"))
		return (1);
	if (!do_test(15642, "15642"))
		return (1);
	if (!do_test(-15642, "-15642"))
		return (1);
	if (!do_test(0, "0"))
		return (1);
	if (!do_test(-2147483648, "-2147483648"))
		return (1);
	if (!do_test(2147483647, "2147483647"))
		return (1);
	return (0);
}
