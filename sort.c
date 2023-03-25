/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:53:31 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/25 18:04:35 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **lsta, t_stack **lstb)
{
	int	size;

	size = ft_lstsize(*lsta);
	if (size == 2)
		reverse_rotating(lsta, 'a');
	else if (size == 3)
		sort_three_args(lsta);
	else if (size == 4)
		sort_four_args(lsta, lstb);
	else if (size == 5)
		sort_five_args(lsta, lstb);
	else
		radix_sort(lsta, lstb, size);
}

int	sort_three_args(t_stack **lsta)
{
	if (lst_is_sorted(lsta))
		return (0);
	if (s(lsta, 'c') && lst_is_sorted(lsta))
		return (ft_printf("sa\n"));
	else
		s(lsta, 'c');
	if (r(lsta, 'c') && lst_is_sorted(lsta))
		return (ft_printf("ra\n"));
	else
		reverse_rotating(lsta, 'c');
	if (reverse_rotating(lsta, 'c') && lst_is_sorted(lsta))
		return (ft_printf("rra\n"));
	else
		r(lsta, 'c');
	if (r(lsta, 'c') && s(lsta, 'c') && lst_is_sorted(lsta))
		return (ft_printf("ra\nsa\n"));
	else
	{
		r(lsta, 'c');
		s(lsta, 'c');
	}
	if (reverse_rotating(lsta, 'a') && s(lsta, 'a') && lst_is_sorted(lsta))
		return (0);
	return (1);
}

void	sort_four_args(t_stack **lsta, t_stack **lstb)
{
	find_smallest_value(lsta, lstb);
	sort_three_args(lsta);
	push_a(lsta, lstb);
}

void	sort_five_args(t_stack **lsta, t_stack **lstb)
{
	find_highest_value(lsta, lstb);
	sort_four_args(lsta, lstb);
	push_a(lsta, lstb);
	if (lst_is_sorted(lsta) == 0)
		r(lsta, 'a');
}

int	where_smallest_value(t_stack **lsta)
{
	int		value;
	int		pos;
	int		index;
	t_stack	*tmp;

	tmp = *lsta;
	value = tmp->data;
	index = 0;
	pos = 0;
	while (tmp->next != NULL)
	{
		if (tmp->data <= value)
		{
			pos = index;
			value = tmp->data;
		}
		tmp = tmp->next;
		index++;
	}
	if (tmp->data <= value)
		pos = index;
	return (pos);
}
