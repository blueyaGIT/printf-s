/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:09:14 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/22 16:28:00 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_putnbr_unsigned_fd(unsigned long n, int fd)
{
	if (n >= 10)
	{
		if (ft_putnbr_unsigned_fd(n / 10, fd) == -1)
			return (-1);
	}
	if (ft_putchar_fd(n % 10 + '0', fd) == -1)
		return (-1);
	return (0);
}

int	ft_print_unsigned_nbr(unsigned long n)
{
	if (ft_putnbr_unsigned_fd(n, 1) == -1)
		return (-1);
	return (get_len(n));
}
