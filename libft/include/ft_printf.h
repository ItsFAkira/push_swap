/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:50:38 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/25 15:12:06 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //Adds va_list, va_start, va_arg, va_end
# include <stdio.h>  //Adds printf provisional
# include <unistd.h> //Adds Write

//Main prototype
int	ft_printf(char const *format, ...) __attribute__((format(printf, 1, 2)));

//Base functions
int	ft_print_char(va_list args);
int	ft_print_str(va_list args);
int	ft_print_ptr(va_list args);
int	ft_print_num(va_list args);
int	ft_print_base(unsigned long n, char *base, int baselen);
int	ft_unsigned_dispatcher(va_list args, char c);

#endif
