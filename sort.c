/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:53:31 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/03 16:38:18 by cprojean         ###   ########.fr       */
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
		{
			sort_three_args(lsta);
		}
	else if (size <= 5 && size > 3)
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

void	sort_five_args(t_stack **lsta, t_stack **lstb)
{
	ft_printf("ashfliwfw");
}

void	find_smallest_values(t_stack **lsta, t_stack **lstb)
{
	int	tmp;
	// t_stack *lst;

	tmp = (*lsta)->data;
	while ((*lsta)->next != NULL)
	{
		(*lsta) = (*lsta)->next;
		if (tmp > (*lsta)->data)
			tmp = (*lsta)->data;
	}
}