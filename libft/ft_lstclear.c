/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:27:24 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/20 18:29:01 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*array;
	t_stack	*next_array;

	if (!lst)
		return ;
	array = *lst;
	while (array)
	{
		if (array->next)
			next_array = array->next;
		free(array);
		if (array->next)
			array = next_array;
	}
	*lst = NULL;
	return ;
}
