/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omar.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:51:15 by oaletham          #+#    #+#             */
/*   Updated: 2025/01/22 22:12:09 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_strings(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && c == str[i])
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

int	ft_strlen_sep(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_word(char const *str, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(str, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	split_fill(char **strings, const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s == '\0')
			break ;
		strings[i] = ft_word(s, c);
		if (!strings[i])
		{
			while (i > 0)
				free(strings[--i]);
			return (-1);
		}
		i++;
		while (*s != '\0' && *s != c)
			s++;
	}
	strings[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		n;

	if (!s)
		return (NULL);
	n = count_strings(s, c);
	strings = (char **)malloc(sizeof(char *) * (n + 1));
	if (!strings)
		return (NULL);
	if (split_fill(strings, s, c) < 0)
	{
		free(strings);
		return (NULL);
	}
	return (strings);
}
