/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:18:20 by smun              #+#    #+#             */
/*   Updated: 2020/10/02 22:49:07 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_bool check_result(char *a, const char *expected)
{
	if (a == NULL)
		return (TRUE);
	if (strcmp(a, expected) == 0)
	{
		free(a);
		return (TRUE);
	}
	free(a);
	return (FALSE);
}

t_bool	do_test(int n,
				const char *expected)
{
	char	*str;
	t_bool	result;

	str = ft_itoa(n);
	result = check_result(str, expected);
	if (!result)
	{
		printf("[실패] n=[%d] expected=[%s]\n", n, expected);
		printf("YourResult=[%s]\n", str);
	}
	return (result);
}

int		main(void)
{
	if (!do_test(1, "1"))
		return (1);
	if (!do_test(-7, "-7"))
		return (2);
	if (!do_test(1278450, "1278450"))
		return (3);
	if (!do_test(-970128301, "-970128301"))
		return (4);
	if (!do_test(0, "0"))
		return (5);
	if (!do_test(2147483647, "2147483647"))
		return (6);
	if (!do_test(-2147483648, "-2147483648"))
		return (7);
	return (0);
}
