/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:34:30 by smun              #+#    #+#             */
/*   Updated: 2020/10/01 20:03:36 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

t_bool	do_test(const void *s1, const void *s2, unsigned int n)
{
	int r1;
	int r2;

	r1 = ft_memcmp(s1, s2, n);
	r2 = memcmp(s1, s2, n);
	return ((r1 > 0 && r2 > 0) ||
			(r1 == 0 && r2 == 0) ||
			(r1 < 0 || r2 < 0));
}

int		main(void)
{
	if (!do_test("abcde", "abcde", 5))
		return (1);
	if (!do_test("abcdf", "abcdf", 5))
		return (2);
	if (!do_test("abc", "abcde", 3))
		return (3);
	if (!do_test("abcd", "abcde", 0))
		return (4);
	if (!do_test("", "", 0))
		return (5);
	if (!do_test("1234567", "1234567", 6))
		return (6);
	if (!do_test("", "abcde", 5))
		return (7);
	if (!do_test("abcde", "", 5))
		return (8);
	return (0);
}
