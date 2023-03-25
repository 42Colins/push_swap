/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:28:14 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/25 17:59:08 by cprojean         ###   ########.fr       */
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
	rotate(lst);
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
	return (1);
}

void	rr(t_stack **lsta, t_stack **lstb)
{
	rotate(lsta);
	rotate(lstb);
	ft_printf("rr\n");
}
