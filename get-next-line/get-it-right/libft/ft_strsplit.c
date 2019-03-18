/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:41:15 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/04 20:23:32 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_begin_word(const char *s, int i, char c)
{
	if ((s[i] != c && i == 0) || (i != 0 && s[i - 1] == c && s[i] != c))
		return (1);
	else
		return (0);
}

static int	is_end_word(const char *s, int i, char c)
{
	if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
		return (1);
	else
		return (0);
}

static int	arr_size(const char *s, char c)
{
	int		array_size;
	int		i;

	array_size = 0;
	i = 0;
	while (s[i])
	{
		if (is_end_word(s, i, c))
			array_size++;
		i++;
	}
	return (array_size);
}

static int	words_alloc(const char *s, char c, char **array)
{
	int		word_length;
	int		i;
	int		j;

	word_length = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		if (is_end_word(s, i, c))
		{
			word_length++;
			array[j] = ft_strnew(word_length);
			if (array[j] == NULL)
				return (-1);
			j++;
			word_length = 0;
		}
		else if (s[i] != c)
			word_length++;
		i++;
	}
	array[j] = NULL;
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;
	int		k;

	array = (char **)malloc(sizeof(char *) * (arr_size(s, c) + 1));
	if (array == NULL)
		return (NULL);
	if (words_alloc(s, c, array) == -1)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		if (is_begin_word(s, i, c))
		{
			k = 0;
			while (s[i] && s[i] != c)
				array[j][k++] = s[i++];
			j++;
		}
		else
			i++;
	}
	return (array);
}
