/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:18:20 by smun              #+#    #+#             */
/*   Updated: 2020/10/02 18:10:11 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <string.h>

t_bool check_result(char *trimmed, const char *expected)
{
	if (expected == NULL)
		return (trimmed == NULL);
	return (strcmp(trimmed, expected) == 0);
}

t_bool	do_test(const char *s,
				const char *set,
				const char *expected)
{
	char	*str;
	t_bool	result;

	str = ft_strtrim(s, set);
	result = check_result(str, expected);
	if (!result)
	{
		printf("[실패] s=[%s] set=[%s] expected=[%s]\n", s, set, expected);
		printf("YourResult=[%s]\n", str);
	}
	return (result);
}

int		main(void)
{
	if (!do_test("    Hello World!!!  !  ", " ", "Hello World!!!  !"))
		return (1);
	if (!do_test("\003\003\00342 SELbLOUa!L  bLbbbL\003", "Lb\003", "42 SELbLOUa!L  "))
		return (2);
	if (!do_test("              ", "   ", ""))
		return (3);
	if (!do_test("asdfasdf", "", "asdfasdf"))
		return (4);
	return (0);
}
