/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:33:45 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/08 16:29:44 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *sort_int_array(char **array)
{
	int runner;
	int index;
	int tmp;
	char *copy;

	runner = 1;
	index = 0;
	while (copy[runner] != '\0')
	{
		index = runner + 1;
		while (copy[index] != '\0')
		{
			if (copy[runner] > copy[index])
			{
				tmp = copy[runner];
				copy[runner] = copy[index];
				copy[index] = tmp;
			}
			index++;
		}
		runner++;
	}
	return (copy);
}
