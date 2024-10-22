/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_voidptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:49:54 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/22 12:47:10 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_voidptr(unsigned long long ptr, int initlen)
{
	char		*hex;
	static int	len = 0;

	len = initlen;
	hex = "0123456789abcdef";
	if (len == 0)
	{
		ft_putstr_fd("0x", 1);
		len += 2;
	}
	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		return (len + 1);
	}
	if (ptr >= 16)
	{
		ft_print_voidptr(ptr / 16, len);
	}
	ft_putchar_fd(hex[ptr % 16], 1);
	len += 1;
	return (len);
}
