/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:21:21 by yahokari          #+#    #+#             */
/*   Updated: 2022/04/18 15:37:49 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	ft_count_size(const char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	str_len;

	i = 0;
	str_len = 0;
	count = 0;
	while (1)
	{
		if ((s[i] == c || s[i] == '\0') && str_len > 0)
			count++;
		if (s[i] == '\0')
			break ;
		if (s[i] != c)
			str_len++;
		else
			str_len = 0;
		i++;
	}
	return (count);
}

static char	**ft_safe_free(size_t count, char **copy)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free (copy[i]);
		i++;
	}
	free(copy);
	return (NULL);
}

static char	**ft_store_str(const char *s, char c, char **copy, size_t str_len)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (1)
	{
		if ((s[i] == c || s[i] == '\0') && str_len > 0)
		{
			copy[count] = malloc(sizeof(char) * (str_len + 1));
			if (copy[count] == NULL)
				return (ft_safe_free(count, copy));
			ft_strlcpy(copy[count], &s[i - str_len], str_len + 1);
			count++;
		}
		if (s[i] == '\0')
			break ;
		if (s[i] != c)
			str_len++;
		else
			str_len = 0;
		i++;
	}
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**copy;
	size_t	copy_size;

	if (s == NULL)
		return (NULL);
	copy_size = ft_count_size(s, c);
	copy = ft_calloc(copy_size + 1, sizeof(char *));
	if (copy == NULL)
		return (NULL);
	copy = ft_store_str(s, c, copy, 0);
	if (copy == NULL)
		return (NULL);
	copy[copy_size] = NULL;
	return (copy);
}
