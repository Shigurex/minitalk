/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:17:30 by yahokari          #+#    #+#             */
/*   Updated: 2022/04/19 22:03:15 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static long long	ft_of(long long value, int sign, size_t i, const char *str)
{
	if (sign > 0 && value >= (LLONG_MAX / 10))
	{
		if (value == LLONG_MAX / 10
			&& value % 10 + (str[i] - '0') < LLONG_MAX % 10)
			return (value);
		return (LLONG_MAX);
	}
	else if (sign < 0 && value >= -(LLONG_MIN / 10))
	{
		if (value == -(LLONG_MIN / 10)
			&& value % 10 + (str[i] - '0') < -(LLONG_MIN % 10))
			return (value);
		return (LLONG_MIN);
	}
	return (value);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long long	value;

	i = 0;
	value = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = ft_of(value, sign, i, str);
		if (value == LLONG_MAX || value == LLONG_MIN)
			return ((int)value);
		value = 10 * value + (str[i] - '0');
		i++;
	}
	return ((int)(sign * value));
}
