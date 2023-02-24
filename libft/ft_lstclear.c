/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:27:24 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/23 12:50:11 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst, void (*del)(int))
{
	t_stack	*array;
	t_stack	*next_array;

	if (!lst || !del)
		return ;
	array = *lst;
	while (array)
	{
		next_array = array->next;
		del(array->data);
		free(array);
		array = next_array;
	}
	*lst = NULL;
	return ;
}
