/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:43:55 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/22 13:02:14 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_printf(const char *inputstring, ...)
{
	int	i;
	int	len;
	va_list args;

	va_start(args, inputstring);
	i = 0;
	len = 0;

	while (inputstring[i])
	{
		if (inputstring[i] == '%' && ft_strchr("cspdiuxX%",inputstring[i + 1]))
		{
			i++;
			if (inputstring[i] == '%')
			{
				ft_putchar_fd('%', 1);
				len++;
			}
			else if (inputstring[i] == 'c')
				len += ft_print_char(va_arg(args, int));
			else if (inputstring[i] == 's')
				len += ft_print_str(va_arg(args, char*));
			else if (inputstring[i] == 'p')
				len += ft_print_voidptr(va_arg(args, unsigned long long), 0);
			else if (inputstring[i] == 'd' || inputstring[i] == 'i')
				len += ft_print_nbr(va_arg(args, int));
			else if (inputstring[i] == 'u')
				len += ft_print_unsigned_nbr(va_arg(args, unsigned int));
			else if (inputstring[i] == 'x')
				len += ft_print_hex_nbr(va_arg(args, unsigned long long), 0);
			else if (inputstring[i] == 'X')
				len += ft_print_hex_nbr(va_arg(args, unsigned long long), 1);
		}
		else
		{
			ft_putchar_fd(inputstring[i], 1);
			len++;
		}
		i++;
	}
	va_end(args); //muss auch geschlossen werden bei -1 returns!!!!
	return (len);
}

// 30:     TEST(6, 
// 31:     TEST(7, print(" %p %p ", INT_MIN, INT_MAX));
// 32:     TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
// 33:     TEST(9, print(" %p %p ", 0, 0));

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int len = ft_printf(" %u ", 1);
// 	ft_printf("\n\nLEN: [%i]\n\n", len);
// 	return (0);
// }