/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:32:09 by smun              #+#    #+#             */
/*   Updated: 2020/10/01 18:56:47 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

t_bool	do_test(const char *s)
{
	int r1;
	int r2;

	r1 = ft_atoi(s);
	r2 = atoi(s);
	if (r1 != r2)
	{
		printf("[실패] s=[%s]\n", s);
		printf("Your=%d\n", r1);
		printf("CStdLib=%d\n", r2);
		return (FALSE);
	}
	return (TRUE);
}

int		main(void)
{
	const char	*ss[] = {
		"",
		"123456",
		"   12345678901234",
		"1234abcdef789",
		"       2147483647",
		"  2147483648",
		"  \r\n \t\v\b  1355",
		"-2147483648",
		"-0",
		"---+----+-123456",
		"- - ++-- + 1234567",
		"=+-43+123++55--123avb",
		NULL
	};
	int			i;

	i = 0;
	while (ss[i])
	{
		if (!do_test(ss[i]))
			return (1 + i);
		i++;
	}
	return (0);
}
