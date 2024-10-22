/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:06:06 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/22 11:33:41 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_nbr(unsigned long long n, int upper)
{
	char		*hex;
	static int	len = 0;

	if (upper == 1)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_print_hex_nbr(n / 16, upper);
	}
	ft_putchar_fd(hex[n % 16], 1);
	len += 1;
	return (len);
}
