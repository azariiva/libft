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

# ifndef FT_ERR
#  define FT_ERR (-1)
# endif

# ifndef FT_OK
#  define FT_OK (1)
# endif

# ifndef FT_END
#  define FT_END (0)
# endif

void	gnl_strdel(void *content, size_t size);
void	gnl_fddel(void *content, size_t size);
int		get_next_line(const int fd, char **line);

#endif
