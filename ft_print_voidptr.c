/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_voidptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:49:54 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/22 11:01:35 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_voidptr(unsigned long long ptr)
{
	char		*hex;
	static int	len = 0;

	hex = "0123456789abcdef";
	if (ptr >= 16)
	{
		ft_print_voidptr(ptr / 16);
	}
	ft_putchar_fd(hex[ptr % 16], 1);
	len += 1;
	return (len);
}
