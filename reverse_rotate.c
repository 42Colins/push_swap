/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:05:44 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/25 17:59:29 by cprojean         ###   ########.fr       */
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

int	reverse_rotating(t_stack **lst, char c)
{
	reverse_rotate(lst);
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
	return (1);
}

void	rrr(t_stack **lst, t_stack **lstb)
{
	reverse_rotate(lst);
	reverse_rotate(lstb);
	ft_printf("rrr\n");
}
