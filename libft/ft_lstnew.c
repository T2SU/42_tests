/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 06:08:45 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 07:05:48 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static t_bool	do_test(void *content)
{
	t_list		*lst;
	t_bool		ret;

	ret = FALSE;
	if ((lst = ft_lstnew(content)))
	{
		ret = lst->content == content;
		free(lst);
	}
	return (ret);
}

int				main(void)
{
	if (!do_test("Hello World!"))
		return (1);
	return (0);
}
