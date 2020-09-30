/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:34:30 by smun              #+#    #+#             */
/*   Updated: 2020/09/30 21:38:39 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		do_test(const void *s1, const void *s2, unsigned int n)
{
	return (ft_memcmp(s1, s2, n) == memcmp(s1, s2, n));
}

int		main(void)
{
	int		r;

	if ((r = do_test("abcde", "abcde", 5)) != 0)
		return (1);
	if ((r = do_test("abcdf", "abcdf", 5)) != 0)
		return (2);
	if ((r = do_test("abc", "abcde", 5)) != 0)
		return (3);
	if ((r = do_test("abcd", "abcde", 0)) != 0)
		return (4);
	if ((r = do_test("", "", 0)) != 0)
		return (5);
	if ((r = do_test("1234567", "1234567", 6)) != 0)
		return (6);
	return (0);
}
