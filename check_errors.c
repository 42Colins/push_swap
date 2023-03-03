/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:40:15 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/03 14:50:09 by cprojean         ###   ########.fr       */
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
