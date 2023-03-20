/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:53:31 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/10 15:49:39 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **lsta, t_stack **lstb)
{
	int	size;

	size = ft_lstsize(*lsta);
	if (size == 2)
		reverse_rotating(lsta, 'a');
	else if (size == 3)
		sort_three_args(lsta);
	else if (size == 4)
		sort_four_args(lsta, lstb);
	else if (size == 5)
		sort_five_args(lsta, lstb);
	else
		radix_sort(lsta, lstb, size);
}

void	sort_three_args(t_stack **lsta)
{
	if (lst_is_sorted(lsta) == 0)
		return ;
	if (s(lsta, 'a') && lst_is_sorted(lsta) == 0)
		return ;
	if (r(lsta, 'a') && lst_is_sorted(lsta) == 0)
		return ;
	if (reverse_rotating(lsta, 'a') && lst_is_sorted(lsta) == 0)
		return ;
	if (r(lsta, 'a') && s(lsta, 'a') && lst_is_sorted(lsta) == 0)
		return ;
	if (reverse_rotating(lsta, 'a') && s(lsta, 'a') && lst_is_sorted(lsta) == 0)
		return ;
}

void	sort_four_args(t_stack **lsta, t_stack **lstb)
{
	find_smallest_value(lsta, lstb);
	sort_three_args(lsta);
	push_a(lsta, lstb);
}

void	sort_five_args(t_stack **lsta, t_stack **lstb)
{
	find_highest_value(lsta, lstb);
	sort_four_args(lsta, lstb);
	//stack_print(*lsta);
	push_a(lsta, lstb);
	if (lst_is_sorted(lsta) == 1)
		r(lsta, 'a');
}

int	where_smallest_value(t_stack **lsta)
{
	int	value;
	int	pos;
	int	index;
	t_stack	*tmp;

	tmp = *lsta;
	value = tmp->data;
	index = 0;
	pos = 0;
	while (tmp->next != NULL)
	{
		// ft_printf("data : %d\n", tmp->data);
		// ft_printf("value : %d\n", value);
		// ft_printf("pos : %d\n", pos);
		if (tmp->data <= value)
		{
			pos = index;
			value = tmp->data;
		}
		tmp = tmp->next;
		index++;
	}
	if (tmp->data <= value)
		pos = index;
	return (pos);
}

int	where_highest_value(t_stack **lsta)
{
	int	value;
	int	pos;
	int	index;
	t_stack	*tmp;

	tmp = *lsta;
	value = tmp->data;
	index = 0;
	pos = 0;
	while (tmp->next != NULL)
	{
		if (tmp->data >= value)
		{
			pos = index;
			value = tmp->data;
		}
		tmp = tmp->next;
		index++;
	}
	if (tmp->data >= value)
		pos = index;
	return (pos);
}

void	find_smallest_value(t_stack **lsta, t_stack **lstb)
{
	int	pos;

	pos = where_smallest_value(lsta);
	//stack_print(lstb);
	//ft_printf("pos %d\n", pos);
	if (pos == 3)
	{
		reverse_rotating(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 2)
	{
		reverse_rotating(lsta, 'a');
		reverse_rotating(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 1)
	{
		s(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 0)
		push_b(lsta, lstb);
}

void	find_highest_value(t_stack **lsta, t_stack **lstb)
{
	int	pos;

	//pos = where_highest_value(lsta);
	//stack_print(lstb);
	//ft_printf("pos %d\n", pos);
	if (pos == 4)
	{
		reverse_rotating(lsta, 'a');
		push_b(lsta, lstb);
	}
	if (pos == 3)
	{
		reverse_rotating(lsta, 'a');
		reverse_rotating(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 2)
	{
		r(lsta, 'a');
		r(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 1)
	{
		s(lsta, 'a');
		push_b(lsta, lstb);
	}
	else if (pos == 0)
		push_b(lsta, lstb);
}

int	lst_is_sorted(t_stack **lsta)
{
	t_stack	*head;

	head = *lsta;
	while (head->next != NULL)
	{
		if (head->data > head->next->data)
			return (1);
		head = head->next;
	}
	return (0);
}


// void	sort_big_stack(t_data *data)
// {
// 	int	count;
// 	int	gap;
// 	int	number;
// 	int	temp;

// 	gap = 1;
// 	while (!is_sorted(data))
// 	{
// 		count = 0;
// 		temp = data->len_stack_a;
// 		while (count < temp)
// 		{
// 			number = data->stack_a[data->len_stack_a - 1];
// 			if ((number & gap) == 0)
// 				sort_operations(data, PB);
// 			else
// 				sort_operations(data, RA);
// 			count++;
// 		}
// 		while (data->len_stack_b)
// 			sort_operations(data, PA);
// 		gap *= 2;
// 	}
// }