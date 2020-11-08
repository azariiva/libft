/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_get_next_line.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 23:50:29 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/08 16:54:27 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_GET_NEXT_LINE_H
# define LIBFT_GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 256
# endif

# ifndef ERR
#  define ERR (-1)
# endif

# ifndef OK
#  define OK (0)
# endif

# ifndef END
#  define END (1)
# endif

void	gnl_strdel(void *content, size_t size);
void	gnl_fddel(void *content, size_t size);
int		get_next_line(const int fd, char **line);

#endif
