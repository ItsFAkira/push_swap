/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:39:00 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/18 16:33:02 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base(unsigned long n, char *base, int baselen)
{
	int	result;

	result = 0;
	if (n >= (unsigned long)baselen)
		result += ft_print_base(n / baselen, base, baselen);
	write(1, &base[n % baselen], 1);
	result++;
	return (result);
}
