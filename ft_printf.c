/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:43:55 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/21 15:25:05 by ghambrec         ###   ########.fr       */
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
				len += ft_print_c(va_arg(args, int));
			else if (inputstring[i] == 's')
				ft_putstr_fd(va_arg(args, char*), 1);
			else if (inputstring[i] == 'p')
				ft_putstr_fd("void pointer", 1);
			else if (inputstring[i] == 'd')
				ft_putstr_fd("decimal", 1);
			else if (inputstring[i] == 'i')
				len += ft_print_i(va_arg(args, int));
			else if (inputstring[i] == 'u')
				ft_putstr_fd("unsigned decimal", 1);
			else if (inputstring[i] == 'x')
				ft_putstr_fd("hexadezimal lower", 1);
			else if (inputstring[i] == 'X')
				ft_putstr_fd("hexadezimal upper", 1);
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
	int len = ft_printf("xxx%cxxx",'X');
	
	
	
	ft_printf("\n\nLEN: [%i]\n\n", len);
	return (0);
}