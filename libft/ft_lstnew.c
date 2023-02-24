/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:59:18 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/24 17:56:32 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int	data)
{
	t_stack	*new;

	ft_printf("bonjour\n");
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = 0;
	return (new);
}

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*node;

// 	node = malloc(sizeof(t_list));
// 	if (node == NULL)
// 		return (NULL);
// 	node->content = content;
// 	node->next = NULL;
// 	return (node);
// }