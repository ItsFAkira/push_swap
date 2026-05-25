/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:56:10 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/18 16:40:59 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(va_list args)
{
	int				result;
	unsigned long	ptr;

	result = 0;
	ptr = (unsigned long)va_arg(args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	result += 2;
	result += ft_print_base(ptr, "0123456789abcdef", 16);
	return (result);
}
