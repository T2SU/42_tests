/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:44:49 by smun              #+#    #+#             */
/*   Updated: 2020/09/30 19:17:50 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <libft.h>

const char	*g_str = "Why memmove is so safe? it's so very safely!!!";

int		main(void)
{
	char		b1[300];
	char		b2[300];
	char		*ret1;
	char		*ret2;
	int			i;

	bzero(b1, 300);
	bzero(b2, 300);
	memcpy(b1, g_str, strlen(g_str));
	memcpy(b2, g_str, strlen(g_str));
	i = 0;
	while (i < 10)
	{
		ret1 = (char*)ft_memmove(&b1[37 + i * 5], &b1[32 + i * 5], 14);
		ret2 = (char*)memmove(&b2[37 + i * 5], &b2[32 + i * 5], 14);
		if ((ret1 - b1) != (ret2 - b2))
			return (i * 2 + 1);
		if ((strncmp(b1, b2, 300)))
			return (i * 2 + 2);
		i++;
	}
	printf("Your result    : %s\n", b1);
	printf("CStdLib result : %s\n", b2);
	ret1 = (char*)ft_memmove(&b1[50], &b1[20], 14);
	ret2 = (char*)memmove(&b2[50], &b2[20], 14);
	if ((ret1 - b1) != (ret2 - b2))
		return (100);
	if ((strncmp(b1, b2, 300)))
		return (101);
	printf("Your result    : %s\n", b1);
	printf("CStdLib result : %s\n", b2);
	return (0);
}
