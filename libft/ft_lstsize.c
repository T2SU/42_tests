/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 06:14:53 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 07:07:05 by smun             ###   ########.fr       */
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
	size_t			sz = ft_lstsize(lst[0]);
	i = 0;
	while (i < 10)
		free(lst[i++]);
	if (sz != 10)
		return (1);
	return (0);
}
