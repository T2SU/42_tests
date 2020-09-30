/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:18:20 by smun              #+#    #+#             */
/*   Updated: 2020/09/30 23:59:35 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		do_test(const char *s, unsigned int len)
{
	char	b[300];
	char	b2[300];
	int		result;

	bzero(b, 300);
	bzero(b2, 300);
	result = ft_strlcpy(b, s, len) == strlcpy(b2, s, len);
	if (!result)
		return (0);
	if (strncmp(b, b2, 300))
		return (0);
	return (1);
}

int		main(void)
{
	if (!do_test("Hello World!!!", 100))
		return (1);
	if (!do_test("42 SEOU\0L", 20))
		return (2);
	if (!do_test("나는 빡빡이다!", 5))
		return (3);
	if (!do_test("It's a D\0ange\0rou\0s Code", 7))
		return (4);
	if (!do_test("", 10))
		return (5);
	if (!do_test("It's a D\0ange\0rou\0s Code", 0))
		return (6);
	if (!do_test("", 0))
		return (7);
	return (0);
}
