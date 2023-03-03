/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:40:14 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/03 15:32:19 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/libft.h"
# include "./libft/get_next_line.h"


long long	ft_atoll(const char *str);
int			*ft_intdup(const int *s1);
int	where_pos(int value, int *copy);
void	sort_stack(t_stack **lsta, t_stack **lstb);
void	two_args_sort(t_stack **lsta);
void	reverse_rotating(t_stack **lst, char c);

//MOVES
void		push_a(t_stack **lsta, t_stack **lstb);
void		push_b(t_stack **lsta, t_stack **lstb);
void		swap(t_stack **lst);
void		ss(t_stack **lsta, t_stack **lstb);
void		sa(t_stack **lsta);
void		sb(t_stack **lstb);
void		reverse_rotate_a(t_stack **lsta);
void		reverse_rotate_b(t_stack **lstb);
void		rotate_a(t_stack **lsta);
void		rotate_b(t_stack **lstb);




#endif