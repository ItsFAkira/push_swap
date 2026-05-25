/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_dispatcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:48:14 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/18 17:05:29 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_dispatcher(va_list args, char c)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (c == 'u')
		return (ft_print_base(num, "0123456789", 10));
	else if (c == 'x')
		return (ft_print_base(num, "0123456789abcdef", 16));
	else if (c == 'X')
		return (ft_print_base(num, "0123456789ABCDEF", 16));
	return (0);
}
