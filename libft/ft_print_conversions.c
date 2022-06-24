/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:47:47 by yahokari          #+#    #+#             */
/*   Updated: 2022/06/24 17:48:34 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_printstr(char *s)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_printnbr(int nbr)
{
	char	*str;
	int		digit;

	str = ft_itoa(nbr);
	if (str == NULL)
		return (0);
	ft_putstr_fd(str, 1);
	digit = ft_strlen(str);
	free(str);
	return (digit);
}

static unsigned int	ft_count_digit(size_t nbr, size_t n)
{
	int	digit;

	digit = 1;
	while (nbr >= n)
	{
		nbr /= n;
		digit++;
	}
	return (digit);
}

int	ft_printbase(size_t nbr, char *base)
{
	int		digit;
	size_t	n;
	int		i;
	char	*str;

	n = ft_strlen(base);
	digit = ft_count_digit(nbr, n);
	str = malloc(sizeof(char) * (digit + 1));
	if (str == NULL)
		return (0);
	i = digit;
	while (i > 0)
	{
		i--;
		str[i] = base[nbr % n];
		nbr /= n;
	}
	str[digit] = '\0';
	ft_putstr_fd(str, 1);
	free (str);
	return (digit);
}

int	ft_printaddress(size_t nbr)
{
	int	return_len;

	return_len = 0;
	return_len += ft_printstr("0x");
	return_len += ft_printbase(nbr, "0123456789abcdef");
	return (return_len);
}
