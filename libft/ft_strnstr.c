/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:51:07 by smun              #+#    #+#             */
/*   Updated: 2020/10/01 18:14:51 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <string.h>

t_bool	do_test(const char *s, const char *find, size_t len)
{
	char *r1;
	char *r2;

	r1 = ft_strnstr(s, find, len);
	r2 = strnstr(s, find, len);
	if (r1 != r2 || (r1 != 0 && strcmp(r1, r2)))
	{
		printf("[실패] haystack=[%s] needle=[%s]\n", s, find);
		printf("Your=%s\n", r1);
		printf("CStdLib=%s\n", r2);
		return (FALSE);
	}
	return (TRUE);
}

int		main(void)
{
	if (!do_test("", "", 0))
		return (1);
	if (!do_test("Hello", "", 0))
		return (2);
	if (!do_test("", "Hello", 0))
		return (3);
	if (!do_test("", "", 3))
		return (4);
	if (!do_test("Hello", "", 4))
		return (5);
	if (!do_test("", "Hello", 5))
		return (6);
	if (!do_test("Hello World!", "Go", 30))
		return (7);
	if (!do_test("Hello World!", "Worlf", 30))
		return (8);
	if (!do_test("42 SEOUL Campus", "42 ", 30))
		return (9);
	if (!do_test("42 SEOUL Campus", "pus", 7))
		return (10);
	if (!do_test("42 SEOUL \0Campus", "pus", 30))
		return (11);
	if (!do_test("42 SEOUL Campus", "\0", 30))
		return (12);
	return (0);
}
