/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:43:55 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/21 16:49:21 by ghambrec         ###   ########.fr       */
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
				ft_putstr_fd("void pointer", 1); // TODO
			else if (inputstring[i] == 'd' || inputstring[i] == 'i')
				len += ft_print_nbr(va_arg(args, int));
			else if (inputstring[i] == 'u')
				len += ft_print_unsigned_nbr(va_arg(args, unsigned int));
			else if (inputstring[i] == 'x')
				ft_putstr_fd("hexadezimal lower", 1); // TODO
			else if (inputstring[i] == 'X')
				ft_putstr_fd("hexadezimal upper", 1); // TODO
		}
		else
		{
			ft_putchar_fd(inputstring[i], 1);
			len++;
		}
		i++;
	}

	va_end(args);
	

	return (len);
}

int	main(void)
{
	int len = ft_printf("xxx%uxxx", 4294967295);
	
	ft_printf("\n\nLEN: [%i]\n\n", len);
	return (0);
}