/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:17:37 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/26 20:44:15 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*arr;

	arr = argv_to_int(argc, argv);
	if (!arr)
		return (0);
	if (is_duplicated(arr) != 0)
	{
		free(arr);
		return (0);
	}
}
