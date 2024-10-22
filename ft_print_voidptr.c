/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_voidptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:49:54 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/22 17:20:40 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_voidptr(unsigned long long ptr, int len)
{
	char	*hex;
	int		res;

	res = 0;
	hex = "0123456789abcdef";
	if (ptr >= 16)
	{
		len = ft_put_voidptr(ptr / 16, len);
		if (len == -1)
			return (-1);
	}
	res = ft_putchar_fd(hex[ptr % 16], 1);
	if (res == -1)
		return (-1);
	len += res;
	return (len);
}

int	ft_print_voidptr(unsigned long long ptr)
{
	int	len;
	int	res;

	len = ft_putstr_fd("0x", 1);
	if (len == -1)
		return (-1);
	if (ptr == 0)
	{
		res = ft_putchar_fd('0', 1);
		if (res == -1)
			return (-1);
		return (len + res);
	}
	res = ft_put_voidptr(ptr, 0);
	if (res == -1)
		return (-1);
	len += res;
	return (len);
}
