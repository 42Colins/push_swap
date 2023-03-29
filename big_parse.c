/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:21:17 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/29 18:36:19 by cprojean         ###   ########.fr       */
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

void	ft_putstr_err(char *str)
{
	int		index;
	char	*null;

	null = "(null)";
	index = 0;
	if (!str)
	{
		str = null;
	}
	while (str[index])
	{
		ft_putchar_fd(str[index], 2);
		index++;
	}
}

int	ft_isnbr(int c)
{
	if (0 <= c && c <= 9)
		return (1);
	else
		return (0);
}


int	ft_check_lst(t_stack **lst)
{
	t_stack	*liste;

	liste = *lst;
	if (ft_lstsize(*lst) > 1)
	{
		while (liste != NULL)
		{
			if (ft_isnbr(liste->data) == 0)
				return (ft_putstr_err("Error\n"), 1);
			liste = liste->next;
		}
	}
	if (lst_is_sorted(lst) == 1)
		return (1);
	if (no_repeat(lst) == 0)
		return (ft_putstr_err("Error\n"), 1);
	else if (no_repeat(lst) == 2)
		return (1);
	return (0);
}
