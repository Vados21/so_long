/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:45:12 by vshpilev          #+#    #+#             */
/*   Updated: 2024/05/08 13:45:15 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*ft_free(char **res, size_t pos)
{
	while (pos != 0)
	{
		free(res[pos]);
		pos--;
	}
	free(res[pos]);
	free(res);
	return (NULL);
}

static void	ft_word(char const *str, size_t *first, size_t *last, char c)
{
	*first = *last;
	while (str[*first] == c)
		*first = *first + 1;
	*last = *first;
	while (str[*last] != c && str[*last] != '\0')
		*last = *last + 1;
}

static size_t	ft_count(char const *str, char c)
{
	size_t	count;
	size_t	first;
	size_t	last;

	count = 0;
	first = 0;
	last = 0;
	while (str[last] != '\0')
	{
		ft_word(str, &first, &last, c);
		if (last == first)
			break ;
		else
			count++;
	}
	return (count);
}

static char	*ft_fill(char const *str, size_t first, size_t last)
{
	char	*word;
	size_t	pos;

	pos = 0;
	word = malloc(sizeof(char) * (last - first) + 1);
	if (!word)
		return (NULL);
	word[last - first] = 0;
	while (first < last)
	{
		word[pos] = str[first];
		pos++;
		first++;
	}
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	size_t	first;
	size_t	last;
	size_t	pos;

	res = malloc(sizeof(char *) * (ft_count(str, c) + 1));
	if (!res)
		return (NULL);
	res[ft_count(str, c)] = 0;
	last = 0;
	first = 0;
	pos = 0;
	while (pos < ft_count(str, c))
	{
		ft_word(str, &first, &last, c);
		if (last == first)
			break ;
		res[pos] = ft_fill(str, first, last);
		if (!res[pos])
			return (ft_free(res, pos));
		pos++;
	}
	return (res);
}
