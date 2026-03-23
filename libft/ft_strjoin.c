/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:31:54 by oaletham          #+#    #+#             */
/*   Updated: 2025/08/20 13:37:33 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

static char	*fill(char const *s1, char const *s2, char *newstring)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (i < len1)
	{
		newstring[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		newstring[i + j] = s2[j];
		j++;
	}
	newstring[i + j] = '\0';
	return (newstring);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > SIZE_MAX - len2 - 1)
		return (NULL);
	newstring = (char *)malloc(len1 + len2 + 1);
	if (!newstring)
		return (NULL);
	return (fill(s1, s2, newstring));
}
