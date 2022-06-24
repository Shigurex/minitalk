/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:51:49 by yahokari          #+#    #+#             */
/*   Updated: 2022/06/24 17:48:29 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	ft_printchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	ft_print_conversions(const char *str, va_list *args, size_t i)
{
	int		print_len;

	print_len = 0;
	if (str[i] == 'c')
		print_len += ft_printchar(va_arg(*args, int));
	else if (str[i] == 's')
		print_len += ft_printstr(va_arg(*args, char *));
	else if (str[i] == 'p')
		print_len += ft_printaddress(va_arg(*args, uintptr_t));
	else if (str[i] == 'd' || str[i] == 'i')
		print_len += ft_printnbr(va_arg(*args, int));
	else if (str[i] == 'u')
		print_len += ft_printbase(va_arg(*args, unsigned), "0123456789");
	else if (str[i] == 'x')
		print_len += ft_printbase(va_arg(*args, unsigned), "0123456789abcdef");
	else if (str[i] == 'X')
		print_len += ft_printbase(va_arg(*args, unsigned), "0123456789ABCDEF");
	else if (str[i] == '%')
		print_len += ft_printchar('%');
	return (print_len);
}

static int	ft_print(const char *str, va_list *args)
{
	int		print_len;
	size_t	i;

	i = 0;
	print_len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_len += ft_print_conversions(str, args, i);
		}
		else
			print_len += ft_printchar(str[i]);
		i++;
	}
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;

	if (str == NULL)
		return (0);
	va_start(args, str);
	print_len = ft_print(str, &args);
	va_end(args);
	return (print_len);
}
