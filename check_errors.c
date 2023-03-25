/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:40:15 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/23 15:43:43 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_intlen(int	*array)
{
	int	runner;

	runner = 0;
	while (array[runner] != '\0')
		runner++;
	return (runner);
}

int	parse_error(char **array)
{
	if (is_sorted(array) == 1)
		return (1);
	else if (no_repeat(array) == 1)
		return (1);
	return (0);
}

int	is_sorted(char **array)
{
	int	runner;

	runner = 1;
	while ((array[runner] != NULL) && (array[runner + 1] != NULL))
	{
		if (ft_atoll(array[runner + 1]) < ft_atoll(array[runner]))
			return (0);
		runner++;
	}
	return (1);
}

int	no_repeat(char **array)
{
	int	runner;
	int	index;

	runner = 1;
	index = 1;
	while (array[runner + 1] != NULL)
	{
		index = runner + 1;
		while (array[index] != NULL)
		{
			if ((ft_atoll(array[index])) == (ft_atoll(array[runner])))
				return (1);
			index++;
		}
		runner++;
	}
	return (0);
}

int	*ft_intdup(int *s1)
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
