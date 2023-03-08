/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:18:57 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/08 17:52:05 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*many_args(int argc, char **argv, t_stack **lst)
{
	t_stack *new;
	int runner;
	int count;
	int pos;

	count = 0;
	runner = 1;
	while (argv[runner] != '\0')
	{
		new = ft_lstnew(ft_atoll(argv[runner]));
		ft_lstadd_back(lst, new);
		runner++;
	}
	stack_ind(lst);
	return (lst);
}

void stack_print(t_stack *lsta)
{
	t_stack *value;

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

	index = 0;
	tmp = *lsta;
	while (tmp->next != NULL)
	{
		runner = tmp->next;
		index = 0;
		while (runner->next != NULL)
		{
			if (tmp->data < runner->data)
			{
				index++;
				ft_printf("data : %d  ", tmp->data);
				ft_printf("index : %d\n", index);
			}
			runner = runner->next;
		}
		tmp->pos = index;
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack *lsta;
	t_stack *lstb;

	lsta = NULL;
	lstb = NULL;
	if (argc <= 2)
	{
		return ;
		ft_printf("WRONG ARGS"); 
	}
	else if (argc == 2)
		return ;
	else
	{
		//ft_printf("%d\n", ft_atoll("0"));
		if (parse_error(argv) == 1)
			return ;
		// if (is_sorted(argv) == 1)
		// 	return (ft_printf("VALUES ALREADY SORTED"));
		many_args(argc, argv, &lsta);
		sort_stack(&lsta, &lstb);
		stack_print(lsta);
	}
}