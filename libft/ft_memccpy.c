/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:50:05 by smun              #+#    #+#             */
/*   Updated: 2020/09/30 15:17:55 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

const char	*g_str = "Libft is awesome! Happy coding from 42 SEOUL!!";
const char	*g_korea = "Korea!!!";
const char	*g_network = " Networks!!";
char		g_buf1[256];
char		g_buf2[256];
char		g_buf3[256];
char		g_buf4[256];

void	reset_buffers(void)
{
	bzero(g_buf1, 256);
	bzero(g_buf2, 256);
	bzero(g_buf3, 256);
	bzero(g_buf4, 256);
}

/*
** n에 문자열보다 적은 수를 넣고, 원본(src) 문자열에 없는 문자를 c에 넣어서,
** n만큼 버퍼 복사가 이루어진 후 정상적으로 NULL이 리턴되는지 표준 라이브러리의 memccpy와 비교 테스트.
*/

int		test1(void)
{
	char		*ret;
	char		*ret2;

	reset_buffers();
	ret = (char*)ft_memccpy(g_buf1, g_str, '?', 44);
	ret2 = (char*)memccpy(g_buf2, g_str, '?', 44);
	if (ret2 != ret)
		return (1);
	if (strncmp(g_buf1, g_buf2, 256) != 0)
		return (2);
	return (0);
}

/*
** c에 특정 문자열을 넣어서, 해당 문자열까지 정상적으로 복사가 되는지.
** 복사된 바로 다음 포인터가 반환되는지 표준 라이브러리의 memccpy와 비교 테스트.
** 그리고 복사된 포인터를 이용하여 다른 문자열을 바로 복사할 수 있는지.
*/

int		test2(void)
{
	char		*ret;
	char		*ret2;

	reset_buffers();
	ret = (char*)ft_memccpy(g_buf1, g_str, '2', 256);
	ret2 = (char*)memccpy(g_buf2, g_str, '2', 256);
	if ((ret2 - g_buf2) != (ret - g_buf1))
		return (3);
	if (strncmp(g_buf1, g_buf2, 256) != 0)
		return (4);
	ret = (char*)ft_memccpy(ret, g_korea, '.', 7);
	ret2 = (char*)ft_memccpy(ret2, g_korea, '.', 7);
	if (ret2 != ret)
		return (5);
	if (strncmp(g_buf1, g_buf2, 256) != 0)
		return (6);
	return (0);
}

/*
** test2와 동일. 그러나 두번째로 복사하는 문자열을 다른 문자열로 넣음.
*/

int		test3(void)
{
	char		*ret;
	char		*ret2;

	reset_buffers();
	ret = (char*)ft_memccpy(g_buf1, g_str, '2', 256);
	ret2 = (char*)memccpy(g_buf2, g_str, '2', 256);
	if ((ret2 - g_buf2) != (ret - g_buf1))
		return (7);
	if (strncmp(g_buf1, g_buf2, 256) != 0)
		return (8);
	ret = (char*)ft_memccpy(ret, g_network, '.', 7);
	ret2 = (char*)ft_memccpy(ret2, g_network, '.', 7);
	if (ret2 != ret)
		return (9);
	if (strncmp(g_buf1, g_buf2, 256) != 0)
		return (10);
	return (0);
}

int		main(void)
{
	int		result;

	if ((result = test1()) != 0)
		return (result);
	if ((result = test2()) != 0)
		return (result);
	if ((result = test3()) != 0)
		return (result);
	return (0);
}
