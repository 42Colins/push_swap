/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:46:25 by cprojean          #+#    #+#             */
/*   Updated: 2023/04/02 18:46:30 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	filler(long long answer, const char *str, int sign, long long index)
{
	int	max;
	int	min;

	min = -2147483648;
	max = 2147483647;
	while ('0' <= str[index] && str[index] <= '9')
	{
		if (answer != ((answer * 10) + (str[index] - '0')) / 10 && sign == -1)
			return (0);
		if (answer != ((answer * 10) + (str[index] - '0')) / 10 && sign == 1)
			return (-1);
		answer = answer * 10 + str[index] - 48;
		index++;
	}
	if ((min <= sign * answer) && (sign * answer <= max))
		return (sign * answer);
	else
	{
		errno = EINVAL;
		return (1);
	}
}

// int x = filler();
// if (errno == EINVAL)
// 	error();

// char *str = strerror(errno);
// ft_putstr_fd("Error message:");
// ft_putstr_fd(str, 2);
// ft_putstr_fd("\n");
// free(str);

// perror("Error message");

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
	return (filler(answer, str, sign, index));
}
