/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:11:12 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/08 09:50:41 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_stack **lsta, t_stack **lstb)
{
	t_stack	*tmp;

	if (!lstb || !*lstb)
		return ;
	tmp = (*lstb)->next;
	(*lstb)->next = *lsta;
	*lsta = *lstb;
	*lstb = tmp;
	ft_printf("pa\n");
}

int	push_b(t_stack **lsta, t_stack **lstb)
{
	t_stack	*tmp;

	if (!lsta || !*lsta)
		return ;
	tmp = (*lsta)->next;
	(*lsta)->next = *lstb;
	*lstb = *lsta;
	*lsta = tmp;
	ft_printf("pb\n");
}
