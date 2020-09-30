/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:32:40 by smun              #+#    #+#             */
/*   Updated: 2020/09/30 14:39:19 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		main(void)
{
	char	buf1[256];
	char	buf2[256];
	char	buf3[256];
	int		i;

	i = 0;
	while (i < 256)
	{
		buf1[i] = i;
		i++;
	}
	memcpy(buf2, buf1, 256);
	ft_memcpy(buf3, buf1, 256);
	return (strncmp(buf2, buf3, 256));
}
