/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:02:07 by oaletham          #+#    #+#             */
/*   Updated: 2025/08/20 13:51:08 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*alloc_empty(void)
{
	char	*substring;

	substring = (char *)malloc(1);
	if (!substring)
		return (NULL);
	substring[0] = '\0';
	return (substring);
}

static size_t	length(char const *s)
{
	size_t	slen;

	slen = 0;
	while (s[slen])
		slen++;
	return (slen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	slen;
	size_t	rlen;

	if (!s)
		return (NULL);
	slen = length(s);
	i = 0;
	if (start >= slen)
		return (alloc_empty());
	rlen = slen - start;
	if (len > rlen)
		len = rlen;
	substring = (char *)malloc(len + 1);
	if (!substring)
		return (NULL);
	while (s[start + i] && i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
