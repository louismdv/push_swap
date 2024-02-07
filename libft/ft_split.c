/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:24:11 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/07 00:53:46 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	wordcount(char const *s, int delimiter)
{
	int	i;
	int	count;
	int	slen;

	i = 0;
	count = 0;
	slen = ft_strlen(s);
	while (i < slen)
	{
		if (s[i] != delimiter && (s[i + 1] == delimiter || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strndup(char const *s, unsigned int n)
{
	char	*duplicate;

	duplicate = (char *)malloc((n + 1) * sizeof(char));
	if (!duplicate)
		return (0);
	ft_strlcpy(duplicate, s, n + 1);
	return (duplicate);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	unsigned int	strindex;
	unsigned int	i;
	unsigned int	sublen;

	i = 0;
	strindex = 0;
	if (!s)
		return (NULL);
	strings = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	while (strindex < wordcount(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		sublen = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			sublen++;
		}
		strings[strindex++] = ft_strndup((char *)s + i - sublen, sublen);
	}
	return (strings);
}

void	free_split_result(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}
