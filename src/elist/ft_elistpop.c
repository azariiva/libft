/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elistpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:37:12 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/08 17:42:54 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_elist.h"

void			ft_elistpoptop(t_elist *elist)
{
	t_dlist	*popped;

	if (!(elist && (popped = elist->head)))
		return ;
	if (!(elist->head = elist->head->next))
		elist->tail = NULL;
	else
		elist->head->prev = NULL;
	ft_dlstdelone(&popped, elist->del);
}

void			ft_elistpopbot(t_elist *elist)
{
	t_dlist	*popped;

	if (!(elist && (popped = elist->tail)))
		return ;
	if (!(elist->tail = elist->tail->prev))
		elist->head = NULL;
	else
		elist->tail->next = NULL;
	ft_dlstdelone(&popped, elist->del);
}
