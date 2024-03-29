/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:23:55 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/25 17:58:35 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **lst)
{
	t_stack	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = (*lst);
	(*lst) = tmp;
}

void	ss(t_stack **lsta, t_stack **lstb)
{
	swap(lsta);
	swap(lstb);
	ft_printf("ss\n");
}

int	s(t_stack **lst, char c)
{
	swap(lst);
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
	return (1);
}
