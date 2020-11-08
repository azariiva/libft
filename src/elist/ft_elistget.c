/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elistget.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:31:30 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/08 17:42:58 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_elist.h"

void			*ft_elistbot(t_elist *elist)
{
	t_dlist	*bot;

	if (!(elist && (bot = elist->tail)))
		return (NULL);
	return (bot->content);
}

void			*ft_elisttop(t_elist *elist)
{
	t_dlist	*top;

	if (!(elist && (top = elist->head)))
		return (NULL);
	return (top->content);
}
