/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 06:14:53 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 07:43:21 by smun             ###   ########.fr       */
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

static void			print_compare(const char *s, const char *e)
{
	putstr("Expect: ");
	putstr(e);
	putstr("\n");
	putstr("Your: ");
	putstr(s);
	putstr("\n");
}

t_list				*newlst(void *content)
{
	t_list			*lst;

	if ((lst = malloc(sizeof(t_list) + 0xBBBB)))
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
	t_list			*lst_f;
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
	lst_f = NULL;
	ft_lstadd_front(&lst_f, lst[i]);
	while (i > 0)
	{
		ft_lstadd_front(&lst_f, lst[i - 1]);
		if (lst_f != lst[i - 1] || strcmp(chr[i - 1], lst_f->content) ||
			lst_f->next == NULL)
		{
			print_compare(lst_f->content, chr[i - 1]);
			return (1);
		}
		if (lst_f->next->content != chr[i])
		{
			print_compare(lst_f->next->content, chr[i]);
			return (1);
		}
		i--;
	}
	i = 0;
	while (i < 4)
		free(lst[i++]);
	return (0);
}
