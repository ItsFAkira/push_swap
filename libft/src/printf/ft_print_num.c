/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:10:41 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/18 17:00:54 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(va_list args)
{
	long	num;
	int		count;

	count = 0;
	num = (long)va_arg(args, int);
	if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
		count++;
	}
	count += ft_print_base(num, "0123456789", 10);
	return (count);
}
