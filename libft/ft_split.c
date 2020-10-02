/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:50:40 by smun              #+#    #+#             */
/*   Updated: 2020/10/02 21:49:30 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <stdlib.h>

static t_bool	do_test(const char *s, char d, const char **aex)
{
	char			**as;
	unsigned int	i;

	i = 0;
	if ((as = ft_split(s, d)))
	{
		while (as[i])
		{
			if (strcmp(as[i], aex[i]))
				return (FALSE);
			free(as[i]);
			i++;
		}
		free(as);
	}
	return (TRUE);
}

static t_bool	do_test1()
{
	const char	*s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	const char	*aex[] = {
		"Lorem", "ipsum", "dolor", "sit", "amet,", "consectetur", "adipiscing", "elit."
	};

	return (do_test(s, ' ', aex));
}

static t_bool	do_test2()
{
	const char	*s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	const char	*aex[] = {
		"Lorem ", "psum dolor s", "t amet, consectetur ad", "p", "sc", "ng el", "t."
	};

	return (do_test(s, 'i', aex));
}

static t_bool	do_test3()
{
	const char	*s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	const char	*aex[] = {
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit"
	};

	return (do_test(s, '.', aex));
}

static t_bool	do_test4()
{
	const char	*s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	const char	*aex[] = {
		"L", "rem ipsum d", "l", "r sit amet, c", "nsectetur adipiscing elit."
	};

	return (do_test(s, 'o', aex));
}

static t_bool	do_test5()
{
	const char	*s = "             ";
	const char	*aex[] = {
		""
	};

	return (do_test(s, ' ', aex));
}

static t_bool	do_test6()
{
	const char	*s = "";
	const char	*aex[] = {
		""
	};

	return (do_test(s, ' ', aex));
}

int				main(void)
{
	if (!do_test1())
		return (1);
	if (!do_test2())
		return (2);
	if (!do_test3())
		return (3);
	if (!do_test4())
		return (4);
	if (!do_test5())
		return (5);
	if (!do_test6())
		return (6);
	return (0);
}
