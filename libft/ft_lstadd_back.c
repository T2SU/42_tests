/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 06:14:53 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 07:43:16 by smun             ###   ########.fr       */
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

t_list				*ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}


int					main(void)
{
	char			*chr[4] = {"1", "2", "3", "4"};
	t_list			*lst[4];
	t_list			*lst_b;
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
	i = 0;
	lst_b = NULL;
	ft_lstadd_back(&lst_b, lst[i]);
	while (i < 3)
	{
		ft_lstadd_back(&lst_b, lst[i + 1]);
		if (strcmp(ft_lstlast(lst_b)->content, chr[i + 1]))
		{
			print_compare(ft_lstlast(lst_b)->content, chr[i + 1]);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < 4)
		free(lst[i++]);
	return (0);
}
