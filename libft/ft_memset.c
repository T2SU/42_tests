/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 05:47:36 by smun              #+#    #+#             */
/*   Updated: 2020/09/30 07:56:16 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		main(void)
{
	unsigned char	buf[32];
	int				i;

	ft_memset(buf, 0xAA, 32);
	ft_memset(buf, 0xBB, 16);
	ft_memset(&buf[16], 0xCC, 8);
	i = 0;
	while (i < 32)
	{
		if (i < 16)
		{
			if (buf[i] != 0xBB)
				return (1);
		}
		else if (i < 24)
		{
			if (buf[i] != 0xCC)
				return (2);
		}
		else
		{
			if (buf[i] != 0xAA)
				return (3);
		}
		i++;
	}
	return (0);
}
