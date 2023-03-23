/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:18:57 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/22 16:36:33 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_ind(t_stack **lsta);

t_stack	*many_args(int argc, char **argv, t_stack **lst)
{
	t_stack	*new;
	int		runner;

	(void) argc;
	runner = 1;
	while (argv[runner] != NULL)
	{
		new = ft_lstnew(ft_atoll(argv[runner]));
		ft_lstadd_back(lst, new);
		runner++;
	}
	stack_ind(lst);
	return (*lst);
}

void	stack_print(t_stack *lsta)
{
	t_stack	*value;

	value = lsta;
	while (value->next != NULL)
	{
		ft_printf("value : %d\n", value->data);
		ft_printf("position : %d\n", value->pos);
		value = value->next;
	}
	ft_printf("value : %d\n", value->data);
	ft_printf("position : %d\n", value->pos);
}

void	stack_ind(t_stack **lsta)
{
	t_stack	*tmp;
	t_stack	*runner;
	int		index;

	tmp = *lsta;
	index = 0;
	while (tmp != NULL)
	{
		index = 0;
		runner = *lsta;
		while (runner != NULL)
		{
			if (tmp->data > runner->data)
			{
				index++;
			}
			runner = runner->next;
		}
		tmp->pos = index;
		tmp = tmp->next;
	}
}

void	free_all(t_stack **lsta, t_stack **lstb)
{
	ft_lstclear(lsta);
	ft_lstclear(lstb);
}

int	main(int argc, char **argv)
{
	t_stack	*lsta;
	t_stack	*lstb;

	lsta = NULL;
	lstb = NULL;
	if (argc <= 2)
	{
		return (1);
		ft_printf("WRONG ARGS");
	}
	else if (argc == 2)
		return (1);
	else
	{
		if (parse_error(argv) == 1)
			many_args(argc, argv[1], &lsta);
		else
			many_args(argc, argv, &lsta);
		sort_stack(&lsta, &lstb);
		ft_lstintclear(&lsta);
	}
}
