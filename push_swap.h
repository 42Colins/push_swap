/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:40:14 by cprojean          #+#    #+#             */
/*   Updated: 2023/04/02 18:39:03 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "errno.h"

long long	ft_atoll(const char *str);
int			*ft_intdup(int *s1);
int			where_pos(int value, int *copy);
void		sort_stack(t_stack **lsta, t_stack **lstb);
void		two_args_sort(t_stack **lsta);
int			lst_is_sorted(t_stack **lsta);
int			is_sorted(char **array);
char		*sort_int_array(char **array);
int			ind_converter(char *array, int value);
char		*argv_to_array(char **argv);
void		radix_sort(t_stack **lsta, t_stack **lstb, int size);
void		radix(t_stack **lsta, t_stack **lstb, int size);
int			where_highest_value(t_stack **lsta);
int			parse_error(char **array);
int			no_repeat(t_stack **array);
int			sort_three_args(t_stack **lsta);
void		sort_four_args(t_stack **lsta, t_stack **lstb);
void		sort_five_args(t_stack **lsta, t_stack **lstb);
void		find_highest_value(t_stack **lsta, t_stack **lstb);
void		next_find_highest_value(t_stack **lsta, t_stack **lstb, int pos);
void		find_smallest_value(t_stack **lsta, t_stack **lstb);
int			where_smallest_value(t_stack **lsta);
t_stack		*parse_arrays(char **argv, t_stack **lsta);
void		stack_ind(t_stack **lsta);
void		ft_putstr_err(char *str);
int			ft_check_lst(t_stack **lst);
int			ft_isnbr(int c);
int			only_nbr(char *array);





//MOVES
int			reverse_rotating(t_stack **lst, char c);
void		push_a(t_stack **lsta, t_stack **lstb);
void		push_b(t_stack **lsta, t_stack **lstb);
void		swap(t_stack **lst);
void		ss(t_stack **lsta, t_stack **lstb);
void		sa(t_stack **lsta);
void		sb(t_stack **lstb);
int			s(t_stack **lst, char c);
void		reverse_rotate_a(t_stack **lsta);
void		reverse_rotate_b(t_stack **lstb);
void		rotate_a(t_stack **lsta);
void		rotate_b(t_stack **lstb);
int			r(t_stack **lst, char c);

#endif