/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 07:19:24 by smun              #+#    #+#             */
/*   Updated: 2020/10/01 07:24:05 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		do_test(const char *s, int c)
{
	return (ft_strchr(s, c) == strchr(s, c));
}

int		main(void)
{
	if (!do_test("Hello world!!", 'o'))
		return (1);
	if (!do_test("", 'a'))
		return (2);
	if (!do_test("remote: Resolving deltas: 100% (3/3)", '?'))
		return (3);
	if (!do_test("ZeroBBBack?", 'B'))
		return (4);
}
