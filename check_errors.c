/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:40:15 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/08 15:14:09 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_intlen(int	*array)
{
	int	runner;

	runner = 0;
	while (array[runner] != '\0')
		runner++;
	return (runner);
}

int parse_error(int *array)
{
	if (is_sorted(array) == 1)
	{
		//ft_printf("VALUES ARE ALREADY SORTED");
		return (1);
	}
	else if (no_repeat(array) == 1)
		return (1);
	return (0);
}

int is_sorted(char **array)
{
	int runner;
	int count;

	runner = 1;
	while ((array[runner] != '\0') && (array[runner + 1] != '\0'))
	{
		if (ft_atoll(array[runner + 1]) < ft_atoll(array[runner]))
			return (0);
		runner++;
	}
	return (1);
}

int no_repeat(char **array)
{
	int runner;
	int index;

	runner = 1;
	index = 1;
	while (array[runner + 1] != '\0')
	{
		index = runner + 1;
		while (array[index] != '\0')
		{
			if ((ft_atoll(array[index])) == (ft_atoll(array[runner])))
			{
				//ft_printf("A VALUE REPEATS TWICE\n");
				return (1);
			}
			index++;
		}
		runner++;
	}
	return (0);
}

int	*ft_intdup(const int *s1)
{
	int		size;
	int		runner;
	int		*dup;

	runner = 0;
	size = ft_intlen(s1);
	dup = malloc(sizeof(int) * size + 1);
	if (dup == 0)
		return (0);
	while (runner < size)
	{
		dup[runner] = s1[runner];
		runner++;
	}
	dup[runner] = '\0';
	return (dup);
}

int	where_pos(int value, int *copy)
{
	int	runner;

	runner = 0;
	while (copy[runner] != value)
		runner++;
	return (runner);
}
