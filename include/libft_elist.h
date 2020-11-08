/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_elist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:46:05 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/08 16:54:44 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ELIST

# include "libft_dlist.h"
# include <stddef.h>

# define LIBFT_ELIST

/*
** t_elist combines all functionality of t_queue and t_list with improved
** user experience
*/

# ifndef ERR
#  define ERR (-1)
# endif

# ifndef OK
#  define OK (0)
# endif

# ifndef END
#  define END (1)
# endif

typedef struct	s_elist
{
	t_dlist		*head;
	t_dlist		*tail;
	size_t		content_size;
	void		(*del)(void *, size_t);
	t_dlist		*garbage;
}				t_elist;

t_elist			*ft_elistnew(size_t content_size, void (*del)(void *, size_t));
void			ft_elistdel(t_elist **elist);
int				ft_elistpushtop(t_elist *elist, void *content);
int				ft_elistpushbot(t_elist *elist, void *content);
void			*ft_elistpoptop(t_elist *elist);
void			*ft_elistpopbot(t_elist *elist);

#endif
