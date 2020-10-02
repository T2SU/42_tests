/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 03:19:27 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 03:44:23 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

char	path[1024];

t_bool	do_test(char c)
{
	int		fd;
	char	check;

	fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
	{
		write(STDERR_FILENO, "[Failed] Cannot open a temp file as write only mode.\n", 53);
		return (FALSE);
	}
	ft_putchar_fd(c, fd);
	close(fd);

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(STDERR_FILENO, "[Failed] Cannot open a temp file as read only mode.\n", 52);
		return (FALSE);
	}
	if (read(fd, &check, 1) <= 0)
	{
		write(STDERR_FILENO, "[Failed] Cannot read any data from a temp file.\n", 48);
		return (FALSE);
	}
	close(fd);
	return (memcmp(&check, &c, 1) == 0);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (strlen(argv[1]) > 1000)
		return (ENAMETOOLONG);
	strlcpy(path, argv[1], 1024);
	strlcat(path, "/test_output", 1024);
	if (!do_test('c'))
		return (1);
	if (!do_test('k'))
		return (1);
	if (!do_test(' '))
		return (1);
	if (!do_test('a'))
		return (1);
	if (!do_test('\01'))
		return (1);
	return (0);
}
