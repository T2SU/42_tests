/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 06:14:53 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 06:30:31 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static void			putstr(const char *s)
{
	write(STDOUT_FILENO, s, strlen(s));
}

t_list				*newlst(void *content)
{
	t_list			*lst;

	if ((lst = malloc(sizeof(t_list))))
	{
		lst->content = content;
		lst->next = NULL;
	}
	return (lst);
}

int					main(void)
{
	char			*chr[4] = {"1", "2", "3", "4"};
	t_list			*lst[4];
	unsigned int	i;

	i = 0;
	while (i < 4)
	{
		if (!(lst[i] = newlst(chr[i])))
		{
			while (i > 0)
				free(lst[i--]);
			return (1);
		}
		i++;
	}
	i = 3;
	while (i > 0)
	{
		ft_lstadd_front(&lst[3], lst[i - 1]);
		if (lst[3] != lst[i - 1] || strcmp(chr[i - 1], lst[3]->content))
		{
			putstr("Expect: ");
			putstr(chr[i - 1]);
			putstr("\n");
			putstr("Your: ");
			putstr(lst[3]->content);
			putstr("\n");
			return (1);
		}
		i--;
	}
	return (0);
}
