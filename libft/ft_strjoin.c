/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:14:38 by yahokari          #+#    #+#             */
/*   Updated: 2022/04/18 00:35:00 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*full_script;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	full_script = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (full_script == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		full_script[i] = ((char *)s1)[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		full_script[i] = ((char *)s2)[i - len_s1];
		i++;
	}
	full_script[i] = '\0';
	return (full_script);
}
