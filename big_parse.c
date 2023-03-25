/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:21:17 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/24 10:47:47 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse_arrays(char **argv, t_stack **lsta)
{
	char	**tmp;
	int		runner;
	t_stack	*new;

	runner = 0;
	tmp = ft_split(argv[1], ' ');
	while (tmp[runner])
	{
		new = ft_lstnew(ft_atoll(tmp[runner]) + '0');
		ft_lstadd_back(lsta, new);
		runner++;
	}
	stack_ind(lsta);
	runner = 0;
	while (tmp[runner])
	{
		free(tmp[runner]);
		runner++;
	}
	free(tmp);
	return (*lsta);
}
