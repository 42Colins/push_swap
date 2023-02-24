/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:35:48 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/24 17:57:29 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*array;

	if (!lst || !new)
		return ;
	array = *lst;
	if (array == NULL)
		*lst = new;
	else
	{
		while (array->next)
			array = array->next;
		array->next = new;
	}
}

size_t	tab_len(char *array)
{
	size_t	runner;

	runner = 0;
	while (array[runner] != '\0')
		runner++;
	return (runner);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

size_t	count_char(char **argv)
{
	int	runner;
	int	index;
	int	count;
	char	*array;

	count = 0;
	runner = 1;
	index = 0;
	while (argv[runner])
	{
		while(argv[runner][index] != '\0')
		{
			index++;
		}
		count = count + index;
		index = 0;
		runner++;
	}
	return (count);
}

// t_stack* arrayToLinkedList(int* arr, int size) {
// 	t_stack *head = NULL;
// 	t_stack *tail = NULL;
// 	t_stack *newNode;
// 	int		i;
	
// 	i = 0;
// 	while (i < size)
// 	{
// 		newNode = ft_lstnew(arr[i]);
// 		if (head == NULL)
// 		{
// 			head = newNode;
// 			tail = newNode;
// 		} else
// 		{	
// 			tail->next = newNode;
// 			tail = newNode;
// 		}
// 		i++;
// 	}
// 	return (head);
// }

void	arr_to_stack(int *array, t_stack **lsta)
{
	int	runner;
	t_stack	*new;
	t_stack	*start;
	// int	size;

	// size = tab_len(array);
	runner = 0;
	//ft_printf("here: %d\n", array[0]);
	//start = ft_lstnew(array[runner]);
	//ft_lstadd_front(lsta, start);
	//runner++;
	while (array[runner] != '\0')
	{
		new = ft_lstnew(array[runner]);
		ft_printf("test : %d\n", runner);
		ft_lstadd_front(lsta, new);
		ft_printf("test : %d\n", runner);
		runner++;
	}
}

char	*argv_to_arr(char **argv)
{
	int	runner; 
	int	count;
	int	**array;
	int	*stp;

	count = 0;
	runner = 0;
	while (argv[1][runner] != '\0')
	{
		if (argv[1][runner] == ' ' && argv[1][runner + 1] != '\0')
			count++;
		runner++;
	}
	runner = 0;
	stp = malloc(sizeof(int) * (count + 1));
	array = ft_split(argv[1], ' ');
	while (array[runner] != '\0')
	{
		stp[runner] = ft_atoll(array[runner]);
		runner++;
	}
	return (free_all(array, count + 1), stp);
}

void	ft_print_lst(t_stack *lsta)
{
	//t_stack	*lst;

	//lst = lsta;
	while (lsta->next)
	{
		//ft_printf("%p\n",NULL);
		ft_printf("%d %p\n", lsta->data, lsta->next);
		lsta = lsta->next;
	}
}

int main(int argc, char **argv)
{
	t_stack	*lsta;
	size_t	words;
	int		*array;
	int		runner;
	int		size;

	runner = 0;
	if (argc == 2)
	{
		array = argv_to_arr(argv);
		while(array[runner] != '\0')
		{
			ft_printf("%d\n", array[runner]);
			runner++;
		}
	}
	//size = tab_len(array);
	arr_to_stack(array, &lsta);
	ft_printf("you're here\n");
	ft_print_lst(lsta);
	// ft_printf("%i", words);
}
