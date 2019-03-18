/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:17:30 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/07 08:28:39 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	insert_line(char **line, char *buf)
{
	char	*tmp;

	if (*line == NULL)
		*line = ft_strnew(0);
	if (*line == NULL)
		return (ERROR);
	tmp = *line;
	*line = ft_strjoin(*line, buf);
	if (*line == NULL)
		return (ERROR);
	free(tmp);
	return (OK);
}

static int	read_buf(const int fd, char *buf[], char **line)
{
	int		ret;

	if (buf[fd] == NULL)
		buf[fd] = ft_strnew(BUFF_SIZE);
	if (buf[fd] == NULL)
		return (ERROR);
	ret = read(fd, buf[fd], BUFF_SIZE);
	buf[fd][ret] = '\0';
	if (ret < 0)
		return (ERROR);
	else if (ret == END_OF_FILE)
	{
		if (*line)
		{
			if (insert_line(line, buf[fd]) == ERROR)
				return (ERROR);
			buf[fd] = NULL;
			return (LAST_LINE);
		}
		*line = ft_strnew(0);
		return (END_OF_FILE);
	}
	return (OK);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf[FD_AMOUNT];
	char		*nl_ptr;
	int			ret;

	if (fd < 0 || fd > FD_AMOUNT || line == NULL)
		return (ERROR);
	*line = NULL;
	nl_ptr = NULL;
	while (nl_ptr == NULL)
	{
		if (buf[fd] == NULL || buf[fd][0] == '\0' || *line)
		{
			ret = read_buf(fd, buf, line);
			if (ret == END_OF_FILE || ret == ERROR)
				return (ret);
			else if (ret == LAST_LINE)
				return (OK);
		}
		if ((nl_ptr = ft_strchr(buf[fd], '\n')) != NULL)
			*nl_ptr = '\0';
		if (insert_line(line, buf[fd]) == ERROR)
			return (ERROR);
	}
	ft_strcpy(buf[fd], nl_ptr + 1);
	return (OK);
}
