/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:21:53 by vshpilev          #+#    #+#             */
/*   Updated: 2024/05/06 16:21:56 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (0);
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
