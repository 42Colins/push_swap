/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:40:15 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/29 18:14:59 by cprojean         ###   ########.fr       */
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

// int	parse_error(char **array)
// {
// 	if (is_sorted(array) == 1)
// 		return (1);
// 	else if (no_repeat(array) == 1)
// 		return (ft_putstr_err("Error\n"), 1);
// 	return (0);
// }

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

int	no_repeat(t_stack **lst)
{
	t_stack	*runner;
	t_stack	*tmp;

	tmp = *lst;
	if (tmp->next == NULL)
		return (2);
	while (tmp != NULL)
	{
		runner = *lst;
		while (runner != NULL)
		{
			if ((tmp->data) == (runner->data))
				return (1);
			runner = runner->next;
		}
		tmp = tmp->next;
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
