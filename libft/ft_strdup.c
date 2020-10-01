/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:18:20 by smun              #+#    #+#             */
/*   Updated: 2020/10/01 23:32:47 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		do_test(const char *s)
{
	char	*dup1;
	char	*dup2;

	dup1 = ft_strdup(s);
	dup2 = strdup(s);
	return (strcmp(dup1, dup2) == 0);
}

int		main(void)
{
	if (!do_test("Hello World!!!"))
		return (1);
	if (!do_test("42 SEOU\0L"))
		return (2);
	if (!do_test("나는 빡빡이다!"))
		return (3);
	if (!do_test("It's a D\0ange\0rou\0s Code"))
		return (4);
	if (!do_test(""))
		return (5);
	return (0);
}
