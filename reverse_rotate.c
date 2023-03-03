/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:05:44 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/03 14:51:12 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **lsta)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *lsta;
	if (!tmp || !tmp->next)
		return ;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	last = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(lsta, last);
}

void	reverse_rotating(t_stack **lst, char c)
{
	if (c == 'a')
	{
		reverse_rotate(lst);
		ft_printf("rra\n");
	}
	else if (c == 'b')
	{
		reverse_rotate(lst);
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack **lst, t_stack **lstb)
{
	reverse_rotate(lst);
	reverse_rotate(lstb);
	ft_printf("rrr\n");
}
