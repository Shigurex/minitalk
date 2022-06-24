/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:14:38 by yahokari          #+#    #+#             */
/*   Updated: 2022/04/19 23:43:56 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	ft_calloc_size(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len <= start)
		return (1);
	else if (s_len + 1 < start + len)
		return (s_len - start + 1);
	else
		return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

	if (s == NULL)
		return (NULL);
	substring = malloc(sizeof(char) * ft_calloc_size(s, start, len));
	if (substring == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		substring[0] = '\0';
		return (substring);
	}
	i = 0;
	while (i < len && s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
