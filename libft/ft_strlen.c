/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:18:20 by smun              #+#    #+#             */
/*   Updated: 2020/09/30 22:23:04 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		do_test(const char *s)
{
	return (ft_strlen(s) == strlen(s));
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
