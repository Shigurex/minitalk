/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:17:17 by yahokari          #+#    #+#             */
/*   Updated: 2022/04/18 00:40:24 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	if (dst > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		}
	}
	return (dst);
}
