/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:50:26 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 18:15:29 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

t_bool				deleted[10];
char				*chr[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
char				*chr_r[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

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

static void			del(void *content)
{
	unsigned int	i;

	i = 0;
	while (i < 10)
	{
		if (!strcmp(content, chr[i]))
			deleted[i] = TRUE;
		i++;
	}
}

static void			*map(void *content)
{
	unsigned int	i;

	i = 0;
	while (i < 10)
	{
		if (!strcmp(content, chr[i]))
			return chr_r[i];
		i++;
	}
	return content;
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
	t_list			*lst_m;
	unsigned int	i;
	int				status;

	i = 0;
	while (i < 10)
	{
		if (!(lst[i] = newlst(chr[i])))
		{
			while (i > 0)
				free(lst[i--]);
			return (1);
		}
		deleted[i] = 0;
		i++;
	}
	status = -3;
	i = 0;
	lst_b = NULL;
	lst_push(&lst_b, lst[i]);
	while (i < 9)
		lst_push(&lst_b, lst[i++ + 1]);
	if ((lst_m = ft_lstmap(lst_b, &map, &del)))
	{
		i = 0;
		status = 0;
		while (i < 10)
		{
			if (strcmp(chr_r[i], lst_m->content))
			{
				status = -1;
				break ;
			}
			lst_b = lst_m;
			lst_m = lst_m->next;
			free(lst[i]);
			free(lst_b);
			i++;
		}
	}
	return (status);
}
