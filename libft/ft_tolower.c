/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:32:09 by smun              #+#    #+#             */
/*   Updated: 2020/10/01 19:31:50 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <ctype.h>

t_bool	do_test(const char *s)
{
	int r1;
	int r2;

	while (*s)
	{
		r1 = ft_tolower(*s);
		r2 = tolower(*s);
		if (r1 != r2)
		{
			printf("[실패] char=[\\%o]\n", *s);
			printf("Your=\\%o\n", r1);
			printf("CStdLib=\\%o\n", r2);
			return (FALSE);
		}
		s++;
	}
	return (TRUE);
}

int		main(void)
{
	const char	*ss[] = {
		"",
		"123456",
		"_!$#@#%!@$%!)@#(",
		"   12345678901234",
		"1234abcEFGGFGASDFDSEf789",
		"1234abcdef789AASSDbP",
		"1234aBCDef789---",
		"1234ABCD!!ef789",
		"       2147483647",
		"  2147483648",
		"  \r\n \t\v\b  1355",
		"-2147\03\132\0848!!?3648",
		"\171\172\173\174\175\176\177\0",
		"-0",
		"---+----+-123\2324^#$\237%@#56",
		"- - ++-- + 123X.4567",
		"=+-43+123++\\55--123avb",
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
