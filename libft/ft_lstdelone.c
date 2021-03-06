/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 06:14:53 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 17:48:41 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

t_bool				deleted[4];
char				*chr[4] = {"1", "2", "3", "4"};

static void			putstr(const char *s)
{
	write(STDOUT_FILENO, s, strlen(s));
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

static void			signal_handler(int sig)
{
	if (sig == SIGABRT)
	{
		putstr("[Success] t_list was freed properly! Don't Panic!\n");
		exit(0);
	}
}

static void			del(void *content)
{
	if (!strcmp(content, chr[0]))
		deleted[0] = TRUE;
	if (!strcmp(content, chr[1]))
		deleted[1] = TRUE;
	if (!strcmp(content, chr[2]))
		deleted[2] = TRUE;
	if (!strcmp(content, chr[3]))
		deleted[3] = TRUE;
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
		deleted[i] = 0;
		i++;
	}
	i = 0;
	lst_b = NULL;
	lst_push(&lst_b, lst[i]);
	while (i < 3)
		lst_push(&lst_b, lst[i++ + 1]);
	i = 0;
	while (i < 4)
	{
		//ft_lstdelone(lst[i], (i & 1) ? (&del) : NULL);
		ft_lstdelone(lst[i], &del);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		//if ((i & 1) != deleted[i])
		if (!deleted[i])
			return (-1);
		i++;
	}
	signal(SIGABRT, signal_handler);
	free(lst[3]);
	putstr("[Failed] t_list was not freed properly!\n");
	return (-1);
}

