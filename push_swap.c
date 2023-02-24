/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:35:48 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/23 17:24:26 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tab_printf(int	*tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s", tab[i]);
		i++;
	}
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

void	arr_to_stack(int *array, t_stack **lsta)
{
	int	runner;
	int	data;
	t_stack	*new;

	runner = 0;
	//ft_printf("here: %d\n", array[0]);
	while (array[runner] != '\0')
	{
		data = malloc(sizeof(int));
		data = array[runner];
		new = ft_lstnew(data);
		ft_lstadd_back(lsta, new);
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
		stp[runner] = ft_atoi(array[runner]);
		runner++;
	}
	return (free(array), stp);
}

void	ft_print_lst(t_stack **lsta)
{
	t_stack	*lst;

	ft_printf("sahifugeyaifg\n");
	lst = *lsta;
	ft_printf("IM HERE\n");
	if (!lsta)
		return (ft_printf("TU ES NULL"), NULL);
	while (lst->next != NULL)
	{
		ft_printf("%d\n", lst->data);
		lst = lst->next;
	}
}

int main(int argc, char **argv)
{
	t_stack	*lsta;
	size_t	words;
	int		*array;
	int		runner;

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
	arr_to_stack(array, &lsta);
	ft_printf("you're here");
	ft_print_lst(&lsta);
	// ft_printf("%i", words);
}
