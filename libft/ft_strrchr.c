/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 07:19:24 by smun              #+#    #+#             */
/*   Updated: 2020/10/01 20:10:10 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		do_test(const char *s, int c)
{
	return (ft_strrchr(s, c) == strrchr(s, c));
}

int		main(void)
{
	char s[] = "";

	if (!do_test("Hello world!!", 'o'))
		return (1);
	if (!do_test("", 'a'))
		return (2);
	if (!do_test("remote: Resolving deltas: 100% (3/3)", '?'))
		return (3);
	if (!do_test("ZeroBBBack?", 'B'))
		return (4);
	if (!do_test("asdf", '\0'))
		return (5);
	if (!do_test("", '\0'))
		return (6);
	if (!do_test(s, '\0'))
		return (7);
}
