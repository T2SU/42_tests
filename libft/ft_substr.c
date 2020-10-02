/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:18:20 by smun              #+#    #+#             */
/*   Updated: 2020/10/02 16:56:57 by smun             ###   ########.fr       */
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
				unsigned int start,
				size_t len,
				const char *expected)
{
	char	*sub;

	sub = ft_substr(s, start, len);
	return (check_result(sub, expected));
}

int		main(void)
{
	if (!do_test("Hello World!!!", 0, 0, ""))
		return (1);
	if (!do_test("42 SEOU\0L", 1, 4, "2 SE"))
		return (2);
	if (!do_test("abcde12345", 8, 5, "45"))
		return (3);
	if (!do_test("It's a D\0ange\0rou\0s Code", 8, 10, ""))
		return (4);
	if (!do_test("", 3, 10, NULL))
		return (5);
	return (0);
}
