/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:18:57 by cprojean          #+#    #+#             */
/*   Updated: 2023/04/03 13:19:54 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_ind(t_stack **lsta);

int	only_nbr(char *array)
{
	int	runner;

	runner = 0;
	while (array[runner] != '\0')
	{
		if ((runner != 0 && !ft_isdigit(array[runner])) \
		|| (runner == 0 && ft_issign(array[runner]) == 1 && array[1] == '\0') \
		|| (!ft_isdigit(array[runner]) && !ft_issign(array[runner])))
			return (ft_putstr_fd("Error\n", 2), 1);
		runner++;
	}
	return (0);
}

t_stack	*many_args(int argc, char **argv, t_stack **lst)
{
	t_stack	*new;
	int		runner;

	(void) argc;
	runner = 1;
	while (argv[runner] != NULL)
	{
		if (only_nbr(argv[runner]) == 1)
			return (ft_lstintclear(lst), NULL);
		new = ft_lstnew(ft_atoll(argv[runner]));
		ft_lstadd_back(lst, new);
		runner++;
	}
	if (errno == EINVAL)
		return (ft_putstr_fd("Error\n", 2), ft_lstintclear(lst), NULL);
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

int	main(int argc, char **argv)
{
	t_stack	*lsta;
	t_stack	*lstb;

	lsta = NULL;
	lstb = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		if (!parse_arrays(argv, &lsta))
			return (1);
	}
	else
	{
		if (!many_args(argc, argv, &lsta))
			return (1);
	}
	if (ft_check_lst(&lsta) == 1)
		return (ft_lstintclear(&lsta), 1);
	sort_stack(&lsta, &lstb);
	ft_lstintclear(&lsta);
}
