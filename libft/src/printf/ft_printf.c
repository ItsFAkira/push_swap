/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:13:00 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/18 16:50:22 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_printer(va_list args, char c)
{
	if (c == 'c')
		return (ft_print_char(args));
	else if (c == 's')
		return (ft_print_str(args));
	else if (c == 'p')
		return (ft_print_ptr(args));
	else if (c == 'd' || c == 'i')
		return (ft_print_num(args));
	else if (c == 'u' || c == 'x' || c == 'X')
		return (ft_unsigned_dispatcher(args, c));
	else if (c == '%')
		return (write(1, &c, 1));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	total_ch;

	i = 0;
	total_ch = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			total_ch += format_printer(args, format[i]);
		}
		else
		{
			write(1, &format[i], 1);
			total_ch++;
		}
		i++;
	}
	va_end(args);
	return (total_ch);
}
