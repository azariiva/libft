/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_get_next_line.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 23:50:29 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/02 00:35:38 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_GNL_H

# define LIBFT_GNL_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 256
# endif

# ifndef E_RCODE
#  define E_RCODE
enum
{
	ERR = -1,
	OK = 1,
	END = 0
};
# endif

#include <stddef.h>

void	gnl_strdel(void *content, size_t size);
void	gnl_fddel(void *content, size_t size);
int		get_next_line(const int fd, char **line);

#endif
