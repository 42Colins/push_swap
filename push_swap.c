/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:44:00 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/06 18:42:39 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*two_args_arr(char *argv)
{
	int		runner;
	char	**array;
	int		*returned;

	runner = 0;
	while (argv[runner] != '\0')
	{
		if (ft_isalpha(argv[runner]) == 1)
		{
			ft_printf("ERROR ONE OF THE ARGS ISN'T A NUMBER\n");
			return (0);
		}	
		runner++;
	}
	array = ft_split(argv, ' ');
	returned = malloc(sizeof(int) * runner);
	runner = 0;
	while (array[runner] != '\0')
	{
		returned[runner] = ft_atoll(array[runner]);
		runner++;
	}
	return (returned);
}

void	arr_to_stack(int *array, int *copy, t_stack **lsta)
{
	t_stack	*new;
	int		runner;
	int		count;
	int		pos;

	count = 0;
	runner = 0;
	while (array[runner] != '\0')
	{
		pos = where_pos(array[runner], copy);
		new = ft_lstnew(array[runner], pos);
		// if (count == 0)
		// {
		// 	ft_lstadd_front(&lsta, new);
		// 	count++;
		// }
		// else
		ft_lstadd_back(lsta, new);
		runner++;
	}
	return (lsta);
}

void	stack_print(t_stack *lsta)
{
	t_stack	*value;

	value = lsta;
	while (value->next != NULL)
	{
		ft_printf("value : %d\n", value->data);
		//ft_printf("position : %d\n", value->pos);
		value = value->next;
	}
	ft_printf("value : %d\n", value->data);
	//ft_printf("position : %d\n", value->pos);
}

int	parse_error(int *array)
{
	if (is_sorted(array) == 1)
	{
		ft_printf("VALUES ARE ALREADY SORTED");
		return (1);
	}
	else if (no_repeat(array) == 1)
		return (1);
	return (0);
}

int	is_sorted(int	*array)
{
	int	runner;
	int	count;

	runner = 0;
	count = 0;
	while (array[count] != '\0')
		count++;
	while (array[runner + 1] != '\0' && (array[runner] < array[runner + 1]))
		runner++;
	if (count == runner + 1)
		return (1);
	return (0);
}

int	no_repeat(int *array)
{
	int	runner;
	int	index;

	runner = 0;
	index = 0;
	while (array[runner + 1] != '\0')
	{
		index = runner + 1;
		while (array[index] != '\0')
		{
			if (array[index] == array[runner])
			{
				ft_printf("A VALUE REPEATS TWICE\n");
				return (1);
			}
			index++;
		}
		runner++;
	}
	return (0);
}

int	*sort_int_array(int *array)
{
	int	runner;
	int	index;
	int	tmp;
	int	*copy;

	copy = ft_intdup(array);
	runner = 0;
	index = 0;
	while (copy[runner] != '\0')
	{
		index = runner + 1;
		while (copy[index] != '\0')
		{
			if (copy[runner] > copy[index])
			{
				tmp = copy[runner];
				copy[runner] = copy[index];
				copy[index] = tmp;
			}
			index++;
		}
		runner++;
	}
	return (copy);
}

int	main(int argc, char **argv)
{
	int		*array;
	int		*copy;
	t_stack	*lstb;
	t_stack	*lsta;

	lsta = NULL;
	lstb = NULL;
	if (argc == 2)
	{
		if (two_args_arr(argv[1]) == 0)
			return (0);
		else
			array = two_args_arr(argv[1]);
		if (parse_error(array) == 1)
			return (0);
	}
	copy = sort_int_array(array);
	arr_to_stack(array, copy, &lsta);
	//stack_print(lsta);
	//ft_printf("now sorted ?\n");
	sort_stack(&lsta, &lstb);
	//stack_print(lsta);
}
