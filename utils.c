/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:26:54 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/21 14:01:20 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_is_sorted(t_stack **lsta)
{
	t_stack	*head;

	head = *lsta;
	while (head->next != NULL)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

void	find_highest_value(t_stack **lsta, t_stack **lstb)
{
	int	pos;

	pos = where_highest_value(lsta);
	if (pos == 4)
	{
		reverse_rotating(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 3)
	{
		reverse_rotating(lsta, 'a');
		reverse_rotating(lsta, 'a');
		push_b(lsta, lstb);
	}
	else
		next_find_highest_value(lsta, lstb, pos);
}

void	next_find_highest_value(t_stack **lsta, t_stack **lstb, int pos)
{
	if (pos == 2)
	{
		r(lsta, 'a');
		r(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 1)
	{
		s(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 0)
		push_b(lsta, lstb);
}

int	where_highest_value(t_stack **lsta)
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
		if (tmp->data >= value)
		{
			pos = index;
			value = tmp->data;
		}
		tmp = tmp->next;
		index++;
	}
	if (tmp->data >= value)
		pos = index;
	return (pos);
}

void	find_smallest_value(t_stack **lsta, t_stack **lstb)
{
	int	pos;

	pos = where_smallest_value(lsta);
	if (pos == 3)
	{
		reverse_rotating(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 2)
	{
		reverse_rotating(lsta, 'a');
		reverse_rotating(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 1)
	{
		s(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 0)
		push_b(lsta, lstb);
}
