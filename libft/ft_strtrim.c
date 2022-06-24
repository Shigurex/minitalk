/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:21:21 by yahokari          #+#    #+#             */
/*   Updated: 2022/04/17 15:37:21 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	ft_checkbeg(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] != set[j])
		{
			j++;
			continue ;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	return (i);
}

static size_t	ft_checkend(char const *s1, char const *set, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0)
		return (0);
	i = len - 1;
	j = 0;
	while (i > 0 && set[j])
	{
		if (s1[i] != set[j])
		{
			j++;
			continue ;
		}
		else
		{
			i--;
			j = 0;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_trimmed;
	size_t	s1_len;
	size_t	s1_start;
	size_t	s1_end;
	size_t	s1_trim_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s1_start = ft_checkbeg(s1, set);
	s1_end = ft_checkend(s1, set, s1_len);
	if (s1_start == s1_len)
		s1_trim_len = 0;
	else
		s1_trim_len = s1_end - s1_start + 1;
	s1_trimmed = ft_substr(s1, s1_start, s1_trim_len);
	return (s1_trimmed);
}
