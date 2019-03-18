/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:17:30 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/25 18:17:54 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#define EOF 0

typedef struct	s_buf
{
	char	str[BUFF_SIZE + 1];
	int		i;
	int		called;
}		t_buf;

int		ft_strchri(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoini(char *s1, char *s2, int index)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	if (index == -1)
		index = BUFF_SIZE;
	j = 0;
	while (j < index)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdupi(char *str, int index)
{
	char	*copy;
	int		i;

	copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (copy == NULL)
		return (NULL);
	if (index == -1)
		index = BUFF_SIZE;
	i = 0;
	while (str[i] && i < index)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

//int		read_recursive()

void	cp_clr_buf(char *str, int index)
{
	int		i;
	
	i = 0;
	while (index < BUFF_SIZE)
	{
		str[i] = str[index];
		i++;
		index++;
	}
	while (i < BUFF_SIZE + 1)
	{
		str[i] = '\0';
		i++;
	}
}
int		get_next_line(const int fd, char **line)
{
	static t_buf	buf[FD_AMOUNT];
	int				ret;

	*line = NULL;
	buf[fd].str[BUFF_SIZE] = '\0';
	if (buf[fd].called)
	{
		*line = ft_strdupi(buf[fd].str, buf[fd].i);
		buf[fd].i = ft_strchri(buf[fd].str, '\n');
	}
	buf[fd].called = 1;
	while (buf[fd].i == -1 || *line == NULL)
	{
		ret = read(fd, buf[fd].str, BUFF_SIZE);
		buf[fd].str[ret] = '\0';
		if (ret < 0)
			return (-1);
		else if (ret == EOF)
			return (0);
		buf[fd].i = ft_strchri(buf[fd].str, '\n');
		if (*line == NULL)
			*line = ft_strdupi(buf[fd].str, buf[fd].i);
		else
			*line = ft_strjoini(*line, buf[fd].str, buf[fd].i);
	}
	buf[fd].i++;
	ret = cp_clr_buf(buf[fd].str, buf[fd].i);
	return (1);
}
