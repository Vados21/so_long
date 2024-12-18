/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:38:00 by vshpilev          #+#    #+#             */
/*   Updated: 2024/05/06 15:38:02 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;
	unsigned char		uc;

	us = s;
	uc = c;
	while (n-- > 0)
	{
		if (*us == uc)
			return ((void *)us);
		us++;
	}
	return (NULL);
}
