/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:28:14 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/21 13:58:59 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **lsta)
{
	t_stack	tmp;
	t_stack	*first;

	first = *lsta;
	tmp.data = first->data;
	tmp.pos = first->pos;
	while (first->next)
	{
		first->data = first->next->data;
		first->pos = first->next->pos;
		first = first->next;
	}
	first->pos = tmp.pos;
	first->data = tmp.data;
}

int	r(t_stack **lst, char c)
{
	if (c == 'a')
	{
		rotate(lst);
		ft_printf("ra\n");
	}
	else if (c == 'b')
	{
		rotate(lst);
		ft_printf("rb\n");
	}
	return (1);
}

void	rr(t_stack **lsta, t_stack **lstb)
{
	rotate(lsta);
	rotate(lstb);
	ft_printf("rr\n");
}
