/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:05:24 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/24 10:30:00 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*array;

	if (!lst || !new)
		return ;
	array = *lst;
	if (array == NULL)
		*lst = new;
	else
	{
		while (array->next != NULL)
			array = array->next;
		array->next = new;
	}
}
