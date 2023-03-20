/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:40:14 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/11 13:52:49 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/libft.h"
# include "./libft/get_next_line.h"


long long	ft_atoll(const char *str);
int			*ft_intdup(const int *s1);
int		where_pos(int value, int *copy);
void	sort_stack(t_stack **lsta, t_stack **lstb);
void	two_args_sort(t_stack **lsta);
int	lst_is_sorted(t_stack **lsta);
int is_sorted(char **array);
char *sort_int_array(char **array);
int	ind_converter(char *array, int value);
char	*argv_to_array(char **argv);
void	radix_sort(t_stack **lsta, t_stack **lstb, int size);
void	radix(t_stack **lsta, t_stack **lstb, int size);
int	where_highest_value(t_stack **lsta);


//MOVES
int			reverse_rotating(t_stack **lst, char c);
int			push_a(t_stack **lsta, t_stack **lstb);
int			push_b(t_stack **lsta, t_stack **lstb);
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