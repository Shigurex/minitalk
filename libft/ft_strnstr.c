/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:21:21 by yahokari          #+#    #+#             */
/*   Updated: 2022/06/18 11:45:55 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (haystack == NULL)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	while (haystack[i] && len >= needle_len && i < len + 1 - needle_len)
	{
		if (needle[0] == haystack[i])
		{
			if (ft_strncmp(&needle[0], &haystack[i], needle_len) == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
