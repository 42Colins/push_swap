/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:40:14 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/28 15:32:07 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/libft.h"
# include "./libft/get_next_line.h"


long long	ft_atoll(const char *str);

void	push_a(t_stack **lsta, t_stack **lstb);
void	push_b(t_stack **lsta, t_stack **lstb);
void	swap(t_stack **lst);
void	ss(t_stack **lsta, t_stack **lstb);
void	sa(t_stack **lsta);
void	sb(t_stack **lstb);
void	reverse_rotate_a(t_stack **lsta);
void	reverse_rotate_b(t_stack **lstb);
void	rotate_a(t_stack **lsta);
void	rotate_b(t_stack **lstb);




#endif