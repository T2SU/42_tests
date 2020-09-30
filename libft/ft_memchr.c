/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:16:00 by smun              #+#    #+#             */
/*   Updated: 2020/09/30 21:25:06 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		main(void)
{
	const char	*str1 = "Hello World!";
	const char	*str2 = "42 SEOUL Innovation Academy";
	const char	*str3 = "See what you are seeing.";
	const char	*str4 = "Now you see me.";

	if (ft_memchr(str1, 'o', strlen(str1)) !=
		memchr(str1, 'o', strlen(str1)))
		return (1);
	if (ft_memchr(str2, 'A', strlen(str2)) !=
		memchr(str2, 'A', strlen(str2)))
		return (2);
	if (ft_memchr(str3, '.', strlen(str3)) !=
		memchr(str3, '.', strlen(str3)))
		return (3);
	if (ft_memchr(str4, ' ', strlen(str4)) !=
		memchr(str4, ' ', strlen(str4)))
		return (4);
	if (ft_memchr(str4, '?', strlen(str4)) !=
		memchr(str4, '?', strlen(str4)))
		return (5);
	return (0);
}
