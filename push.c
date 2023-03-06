/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:11:12 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/06 16:58:20 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_b(t_stack **lsta, t_stack **lstb)
// {
// 	t_stack	*tmp;
// 	t_stack	*head;

// 	if (!lsta || !*lsta)
// 		return ;
// 	head = (*lstb);
// 	tmp = head->next;
// 	head->next = *lsta;
// 	*lsta = head;
// 	*lstb = tmp;
// 	ft_printf("pb\n");
// }

// void	push_a(t_stack **lsta, t_stack **lstb)
// {
// 	t_stack	*tmp;
// 	t_stack	*head;

// 	if (!lstb || !*lstb)
// 		return ;
// 	head = (*lsta);
// 	tmp = head->next;
// 	head->next = lstb;
// 	*lstb = head;
// 	*lsta = tmp;
// 	ft_printf("pa\n");
// }

void	push_a(t_stack **lsta, t_stack **lstb)
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

void	push_b(t_stack **lsta, t_stack **lstb)
{
	t_stack	*tmp;

	if (!lsta || !*lsta)
		return ;
	tmp = (*lsta)->next;
	(*lsta)->next = &lstb;
	*lstb = *lsta;
	*lsta = tmp;
	ft_printf("pb\n");
}