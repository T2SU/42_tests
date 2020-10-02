/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 03:19:27 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 04:02:08 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

char	path[1024];

t_bool	do_test(char *s)
{
	int		fd;
	char	check[1024];
	char	*s_dup;
	size_t	len = strlen(s);
	size_t	readbytes;

	fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
	{
		write(STDERR_FILENO, "[Failed] Cannot open a temp file as write only mode.\n", 53);
		return (FALSE);
	}
	ft_putendl_fd(s, fd);
	close(fd);

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(STDERR_FILENO, "[Failed] Cannot open a temp file as read only mode.\n", 52);
		return (FALSE);
	}
	if ((readbytes = read(fd, check, len + 1)) <= 0)
	{
		write(STDERR_FILENO, "[Failed] Cannot read any data from a temp file.\n", 48);
		return (FALSE);
	}
	close(fd);
	if (readbytes <= len)
	{
		write(STDERR_FILENO, "[Failed] Too short written data.\n", 33);
		return (FALSE);
	}

	s_dup = (char*)malloc(len + 2);
	if (s_dup == NULL)
		return (FALSE);
	memcpy(s_dup, s, len);
	s_dup[len] = '\n';
	s_dup[len + 1] = '\0';

	t_bool result = memcmp(check, s_dup, strlen(s_dup)) == 0;
	free(s_dup);
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
	if (!do_test("lorem ipsum dolor sit amet, consectetur adipiscing elit."))
		return (1);
	if (!do_test("Duis gravida vestibulum varius. Donec nec ex quis tortor semper accumsan."))
		return (1);
	if (!do_test("\01\02\03\04\05"))
		return (1);
	return (0);
}
