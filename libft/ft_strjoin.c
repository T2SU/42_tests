/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:18:20 by smun              #+#    #+#             */
/*   Updated: 2020/10/02 17:02:40 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

t_bool check_result(char *sub, const char *expected)
{
	if (expected == NULL)
		return (sub == NULL);
	return (strcmp(sub, expected) == 0);
}

t_bool	do_test(const char *s,
				const char *s2,
				const char *expected)
{
	char	*str;

	str = ft_strjoin(s, s2);
	return (check_result(str, expected));
}

int		main(void)
{
	if (!do_test("Hello World!!!", "", "Hello World!!!"))
		return (1);
	if (!do_test("42 SEOU\0L", "L", "42 SEOUL"))
		return (2);
	if (!do_test("abcde12345", "asd\021fd\0aa", "abcde12345asd\021fd"))
		return (3);
	if (!do_test("It's a D\0ange\0rou\0s Code", "I luv U", "It's a DI luv U"))
		return (4);
	if (!do_test("", "", ""))
		return (5);
	if (!do_test("", "zero", "zero"))
		return (6);
	return (0);
}
