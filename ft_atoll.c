/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:46:25 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/24 11:48:44 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_filler(long long answer, const char *str, int sign, long long index)
{
	while ('0' <= str[index] && str[index] <= '9')
	{
		if (answer != ((answer * 10) + (str[index] - '0')) / 10 && sign == -1)
			return (0);
		if (answer != ((answer * 10) + (str[index] - '0')) / 10 && sign == 1)
			return (-1);
		answer = answer * 10 + str[index] - 48;
		index++;
	}
	return (sign * answer);
}

long long	ft_atoll(const char *str)
{
	long long	index;
	long long	answer;
	int			sign;

	answer = 0;
	sign = 1;
	index = 0;
	while ((9 <= str[index] && str[index] <= 13) || (str[index] == ' '))
		index++;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	return (ft_filler(answer, str, sign, index));
}
