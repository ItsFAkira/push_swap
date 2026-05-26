/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:48:22 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/26 20:48:51 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char **argv, int i, int j)
{
	int	isneg;

	isneg = 0;
	while (argv[i][j])
	{
		if (argv[i][j] == '-')
		{
			j++;
			isneg++;
		}
		if (argv[i][j] < '0' || argv[i][j] > '9' || isneg > 1)
		{
			write(2, "Error no es num\n", 16);
			return (-1);
		}
		j++;
	}
	return (0);
}

int	*argv_to_int(int argc, char **argv)
{
	int	i;
	int	j;
	int	*arr;

	arr = malloc(argc * sizeof(int));
	if (!arr)
	{
		write(2, "Error malloc\n", 13);
		return (NULL);
	}
	j = 0;
	i = 0;
	while (i + 1 < argc)
	{
		if(check_int(argv, i + 1, j) != 0)
		{
			free(arr);
			return(NULL);
		}
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
		j = 0;
	}
	//BORRAR
	i = 0;
	while(arr[i])
	{
		ft_printf("%d\n", arr[i]);
		i++;
	}
	//HASTA AQUI Y SE QUEDA EN 25 LINEAS
	return (arr);
}

int	is_duplicated(int *arr)
{
	int	checker;
	int	i;
	int	j;

	checker = arr[0];
	i = 0;
	j = 1;
	while (arr[i])
	{
		while(arr[j])
		{
			if (arr[j] == checker)
			{
				write(2, "Error duplicado\n", 16);
				return (-1);
			}
			j++;
		}
		j = ++i + 1;
	}
	return (0);
}
