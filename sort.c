/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:53:31 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/06 18:42:50 by cprojean         ###   ########.fr       */
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
		ft_printf("ya plein d'args jcp trier ca\n");
}

void	sort_three_args(t_stack **lsta)
{
	if (((*lsta)->data < (*lsta)->next->data) && ((*lsta)->data < (*lsta)->next->next->data))
	{
		reverse_rotating(lsta, 'a');
		s(lsta, 'a');
	}
	if (((*lsta)->data > (*lsta)->next->data) && ((*lsta)->data > (*lsta)->next->next->data))
	{
		s(lsta, 'a');
		reverse_rotating(lsta, 'a');
	}
	if (((*lsta)->data > (*lsta)->next->data) && ((*lsta)->data < (*lsta)->next->next->data))
		s(lsta, 'a');
	if (((*lsta)->data < (*lsta)->next->data) && ((*lsta)->data > (*lsta)->next->next->data))
		reverse_rotating(lsta, 'a');
}

void	sort_four_args(t_stack **lsta, t_stack **lstb)
{
	find_smallest_value(lsta, lstb);
	sort_three_args(lsta);
	push_a(lsta, lstb);
}

void	sort_five_args(t_stack **lsta, t_stack **lstb)
{
	find_smallest_value(lsta, lstb);
	sort_four_args(lsta, lstb);
	push_a(lsta, lstb);
}

int	where_smallest_value(t_stack **lsta)
{
	int	pos;
	t_stack	*tmp;

	tmp = *lsta;
	pos = 0;
	while (tmp->next != NULL)
	{
		if (tmp->pos == 0)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
}

void	find_smallest_value(t_stack **lsta, t_stack **lstb)
{
	int	pos;

	pos = where_smallest_value(lsta);
	stack_print(lstb);
	//ft_printf("%d", pos);
	if (pos == 3)
		push_b(lsta, lstb);
	else if (pos == 2)
	{
		reverse_rotating(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 1)
	{
		r(lsta, 'a');
		r(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 0)
	{
		reverse_rotating(lsta, 'a');
		push_b(lsta, lstb);
		stack_print(lstb);
	}
}

