/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:23:55 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/21 13:59:04 by cprojean         ###   ########.fr       */
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
	if (c == 'a')
	{
		swap(lst);
		ft_printf("sa\n");
	}
	else if (c == 'b')
	{
		swap(lst);
		ft_printf("sb\n");
	}
	return (1);
}
