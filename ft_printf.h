/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:46:18 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/22 11:33:49 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int ft_printf(const char *inputstring, ...);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int	ft_print_unsigned_nbr(unsigned long n);
int	ft_print_voidptr(unsigned long long ptr);
int	ft_print_hex_nbr(unsigned long long n, int upper);


// unsigned decimal
// hex

// wieder raus!
#include <stdio.h>


#endif