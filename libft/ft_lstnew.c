/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 06:08:45 by smun              #+#    #+#             */
/*   Updated: 2020/10/03 06:10:28 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_bool	do_test(void *content)
{
	t_list		*lst;

	lst = ft_lstnew(content);
	return (lst->content == content);
}

int				main(void)
{
	if (!do_test("Hello World!"))
		return (1);
	return (0);
}
