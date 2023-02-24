/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:20:43 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/23 12:58:53 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstmap(t_stack *lst, int (*f)(int), void (*del)(int))
{
	t_stack	*array;
	t_stack	*next_array;

	if (!lst || !f || !del)
		return (NULL);
	array = ft_lstnew(f(lst -> data));
	if (!array)
		return (NULL);
	lst = lst -> next;
	while (lst)
	{
		next_array = ft_lstnew(f(lst -> data));
		if (!next_array)
		{
			ft_lstclear(&array, (del));
			return (NULL);
		}
		ft_lstadd_back(&array, next_array);
		lst = lst -> next;
	}
	return (array);
}
