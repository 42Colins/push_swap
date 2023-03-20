/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:20:08 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/20 12:55:20 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **lsta, t_stack **lstb, int size)
{
	int	runner;
	int	i;

	runner = 0;
	i = 0;
}

// int		find_median(t_stack **lsta)
// {
// 	int	gamma_func;
// 	int	runner;
// 	t_stack	*index;

// 	runner = 0;
// 	index = *lsta;
// 	while (*lsta)
// 	{
// 		gamma_func += index->data;
// 		index = index->next;
// 		runner++;
// 	}
// 	return (gamma_func / runner);
// }


// void	radix(t_stack **lsta, t_stack **lstb)
// {
// 	int	median;
// 	int	pos;
// 	int	size;

// 	size = ft_lstsize(*lsta);
// 	median = find_median(lsta);
// 	while (lst_is_sorted(lsta) == 1)
// 	{
// 		radix(lsta, lstb, size);
// 	}
// }

// void	what_to_do(int pos, t_stack **lsta)
// {
// 	int	size;

// 	size = ft_lstsize(lsta);
	
// }

// int	where_am_i(t_stack **lst, int value)
// {
// 	int		runner;
// 	int		size;
// 	t_stack	*tmp;

// 	tmp = *lst;
// 	runner = 0;
// 	while (tmp != NULL)
// 	{
// 		if (value == tmp->data)
// 		{
// 			size = ft_lstsize(lst);
// 			if ((size - runner) < size / 2)
// 				return (-1);
// 			else
// 				return (1);
// 		}
// 		runner++;
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }



void	radix(t_stack **lsta, t_stack **lstb, int size)
{
	int	count;
	t_stack	*tmp;

	count = 0;
	tmp = *lsta;
	// ft_printf("%d\n", size);
	// sleep(1);
	while (count < size)
	{
		//sleep(1);
		// ft_printf("%d\n", tmp->pos);
		// ft_printf("%d\n", tmp->data);
		if ((tmp->pos) % 2 == 1)
		{
			tmp->pos = tmp->pos / 2;
			push_b(lsta, lstb);
			tmp = *lsta;
		}
		else
		{
			tmp->pos = tmp->pos / 2;
			r(lsta, 'a');
			tmp = *lsta;
		}
		count++;
	}
	while (*lstb)
		push_a(lsta, lstb);
	//radix_sort(lsta, lstb, ft_lstsize(*lsta));
}