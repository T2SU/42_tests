/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 05:47:36 by smun              #+#    #+#             */
/*   Updated: 2020/09/30 07:57:24 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		main(void)
{
	unsigned char	buf[256];
	int				i;

	memset(buf, 0xAA, 256);
	ft_bzero(buf, 128);
	i = 0;
	while (i < 256)
	{
		if (i < 128)
		{
			if (buf[i] != 0x00)
				return (1);
		}
		else
		{
			if (buf[i] != 0xAA)
				return (2);
		}
		i++;
	}
	return (0);
}
