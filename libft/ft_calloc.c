/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:28:45 by smun              #+#    #+#             */
/*   Updated: 2020/10/01 23:33:58 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(void)
{
	void	*mem1;
	void	*mem2;

	mem1 = ft_calloc(2, 25);
	mem2 = calloc(2, 25);
	return (memcmp(mem1, mem2, 2 * 25));
}
