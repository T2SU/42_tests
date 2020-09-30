/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:18:20 by smun              #+#    #+#             */
/*   Updated: 2020/10/01 01:10:40 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <string.h>

int		do_test(const char *p, const char *s, unsigned int len)
{
	char	b[300];
	char	b2[300];
	int		r1;
	int		r2;

	memset(b, 0xCC, 300);
	memset(b2, 0xCC, 300);
	strcpy(b, p);
	strcpy(b2, p);
	r1 = ft_strlcat(b, s, len);
	r2 = strlcat(b2, s, len);
	if (r1 != r2)
	{
		printf("[실패] ft_strlcat 리턴값 오류. [You=%d, Expected=%d] [p='%s'] [s='%s']\n", r1, r2, p, s);
		return (0);
	}
	if (strncmp(b, b2, 300))
	{
		printf("[실패] ft_strlcat 실행 결과 오류. [dst='%s'] [src='%s']\n", p, s);
		printf("Your=[%s]\nExpected(CStdLib)=[%s]\n", b, b2);
		return (0);
	}
	return (1);
}

int		main(void)
{
	if (!do_test("Concatnate here: ", "Hello World!!!", 100))
		return (1);
	if (!do_test("Concatnate here: ", "42 SEOU\0L", 20))
		return (2);
	if (!do_test("Concatnate here: ", "I'am PPak PPak Meo ri!!", 5))
		return (3);
	if (!do_test("Concatnate here: ", "It's a D\0ange\0rou\0s Code", 7))
		return (4);
	if (!do_test("Concatnate here: ", "", 10))
		return (5);
	if (!do_test("Concatnate here: ", "It's a D\0ange\0rou\0s Code", 0))
		return (6);
	if (!do_test("Concatnate here: ", "", 0))
		return (7);
	if (!do_test("Hello 42 ", "SEOUL!!", 23))
		return (8);
	if (!do_test("Hello 42 ", "SEOUL!!!", 60))
		return (9);
	if (!do_test("HeLLoooooo 422222222 ", "SEOUL!!!!", 22))
		return (10);
	if (!do_test("HIHIHIHIHI Fourty-two ", "SEOUL!!!!!", 44))
		return (11);
	if (!do_test("", "SEOUL!!!!!", 44))
		return (12);
	if (!do_test("", "", 0))
		return (13);
	return (0);
}
