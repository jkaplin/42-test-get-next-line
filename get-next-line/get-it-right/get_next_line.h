/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:17:57 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/08 18:08:07 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define ERROR -1
# define END_OF_FILE 0
# define OK 1
# define LAST_LINE 2

# define FD_AMOUNT 4864

# define BUFF_SIZE 32

int		get_next_line(const int fd, char **line);

#endif
