/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 06:14:53 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 18:01:21 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

t_bool				iterated[10];
char				*chr[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

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

static void			iter(void *content)
{
	unsigned int	i;

	i = 0;
	while (i < 10)
	{
		if (!strcmp(content, chr[i]))
			iterated[i] = TRUE;
		i++;
	}
}

void				lst_push(t_list **lst, t_list *new)
{
	t_list		*back;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			back = *lst;
			while (back->next != NULL)
				back = back->next;
			back->next = new;
		}
	}
}

int					main(void)
{
	t_list			*lst[10];
	t_list			*lst_b;
	unsigned int	i;

	i = 0;
	while (i < 10)
	{
		if (!(lst[i] = newlst(chr[i])))
		{
			while (i > 0)
				free(lst[i--]);
			return (1);
		}
		iterated[i] = 0;
		i++;
	}
	i = 0;
	lst_b = NULL;
	lst_push(&lst_b, lst[i]);
	while (i < 9)
		lst_push(&lst_b, lst[i++ + 1]);
	ft_lstiter(lst_b, &iter);
	i = 0;
	while (i < 10)
	{
		if (!iterated[i])
			return (-1);
		free(lst[i++]);
	}
	return (0);
}
