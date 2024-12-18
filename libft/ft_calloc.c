/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:13:48 by vshpilev          #+#    #+#             */
/*   Updated: 2024/05/07 12:13:50 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	total = count * size;
	if (count != 0)
	{
		if (size > SIZE_MAX / count)
			return (NULL);
	}
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
