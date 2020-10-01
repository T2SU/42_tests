/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:09:35 by smun              #+#    #+#             */
/*   Updated: 2020/10/01 18:19:46 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <string.h>

t_bool	do_test(const char *s1, const char *s2, size_t len)
{
	int r1;
	int r2;

	r1 = ft_strncmp(s1, s2, len);
	r2 = strncmp(s1, s2, len);
	if (!((r1 > 0 && r2 > 0) ||
			(r1 == 0 && r2 == 0) ||
			(r1 < 0 && r2 < 0)))
	{
		printf("[실패] s1=[%s] s2=[%s]\n", s1, s2);
		printf("Your=%d\n", r1);
		printf("CStdLib=%d\n", r2);
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
	if (!do_test("Hello World!", "Hello World!", 30))
		return (7);
	if (!do_test("Hello World!!", "Hello WorId!!", 10))
		return (8);
	if (!do_test("42 SEOUL Campus", "42 ", 4))
		return (9);
	if (!do_test("42 SEOUL Campus", "42 SEOUL Campus", 50))
		return (10);
	if (!do_test("42 SEOUL \0Campus", "42 SEOUL ", 30))
		return (11);
	return (0);
}

