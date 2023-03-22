/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:20:08 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/21 13:15:19 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **lsta, t_stack **lstb, int size)
{
	int	index;
	int	runner;

	runner = 1;
	index = 1;
	while (index < size)
	{
		index *= 2;
		runner++;
	}
	radix (lsta, lstb, runner);
}

void	radix(t_stack **lsta, t_stack **lstb, int runner)
{
	int		index;
	int		i;
	int		size;
	t_stack	*elem;

	size = ft_lstsize(*lsta);
	i = 0;
	index = 0;
	while (index < runner)
	{
		i = 0;
		while (i < size)
		{
			elem = *lsta;
			if (((elem->pos >> index) & 1) == 1)
				r(lsta, 'a');
			else
				push_b(lsta, lstb);
			i++;
		}
		while (*lstb)
			push_a(lsta, lstb);
		index++;
	}
}
