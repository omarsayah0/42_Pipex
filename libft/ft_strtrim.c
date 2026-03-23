/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:24:02 by oaletham          #+#    #+#             */
/*   Updated: 2025/08/14 18:42:10 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	inset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trims;
	size_t	i;
	size_t	j;
	size_t	n;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && inset(s1[i], set))
		i++;
	j = 0;
	while (s1[j])
		j++;
	while (j > i && inset(s1[j - 1], set))
		j--;
	trims = (char *)malloc(j - i + 1);
	if (!trims)
		return (NULL);
	n = 0;
	while (i < j)
	{
		trims[n++] = s1[i++];
	}
	trims[n] = '\0';
	return (trims);
}
