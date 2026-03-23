/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:25:02 by oaletham          #+#    #+#             */
/*   Updated: 2025/08/20 13:28:11 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;
	size_t	total;

	if (nelem == 0 || elsize == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		((unsigned char *)ptr)[0] = 0;
		return (ptr);
	}
	if (elsize && nelem > SIZE_MAX / elsize)
		return (NULL);
	total = nelem * elsize;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
