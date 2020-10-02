/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:18:20 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 01:58:00 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

char		func(unsigned int i, char c)
{
	if (i % 2)
		return (toupper(c));
	else
		return (tolower(c));
}

static void	print_result(const char *y, const char *e)
{
	write(1, "Your result: ", 13);
	write(1, y, strlen(y));
	write(1, "\n", 1);
	write(1, "Expected: ", 10);
	write(1, e, strlen(e));
	write(1, "\n", 1);
}

t_bool		do_test(const char *s, const char *e)
{
	char	*res;

	if ((res = ft_strmapi(s, &func)))
	{
		if (strcmp(res, e))
		{
			print_result(res, e);
			return (FALSE);
		}
		free(res);
	}
	return (TRUE);
}

int			main(void)
{
	if (!do_test("Lorem ipsum dolor sit amet", "lOrEm iPsUm dOlOr sIt aMeT"))
		return (1);
	if (!do_test("consectetur adipiscing elit", "cOnSeCtEtUr aDiPiScInG ElIt"))
		return (2);
	if (!do_test("Ut vulputate ligula tortor", "uT VuLpUtAtE LiGuLa tOrToR"))
		return (3);
	if (!do_test("a dignissim nulla finibus eget", "a dIgNiSsIm nUlLa fInIbUs eGeT"))
		return (4);
	return (0);
}
