/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:34:46 by oaletham          #+#    #+#             */
/*   Updated: 2025/01/08 19:43:02 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i ;
	size_t	j ;
	size_t	t;
	size_t	desl;
	size_t	sorl;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0')
		j++;
	desl = i;
	sorl = j;
	if (size == 0 || size <= desl)
		return (size + sorl);
	t = 0;
	while (src[t] != '\0' && t < size - desl - 1)
	{
		dest[i] = src[t];
		t++;
		i++;
	}
	dest[i] = '\0';
	return (desl + sorl);
}
