/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 06:14:53 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 07:13:24 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

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
	char			*chr[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
	t_list			*lst[10];
	unsigned int	i;
	t_list			*last;

	i = 0;
	while (i < 10)
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
	while (i < 9)
	{
		lst[i]->next = lst[i + 1];
		i++;
	}
	last = ft_lstlast(lst[0]);
	if (last != lst[9])
		return (1);
	lst[5]->next = NULL;
	last = ft_lstlast(lst[0]);
	if (last != lst[5])
		return (1);
	lst[2]->next = NULL;
	last = ft_lstlast(lst[0]);
	if (last != lst[2])
		return (1);
	i = 0;
	while (i < 10)
		free(lst[i++]);
	return (0);
}
