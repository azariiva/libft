/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quedel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:16:42 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/03 17:53:07 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_queue.h"
#include "libft_list.h"
#include "libft_memory.h"
#include <stddef.h>

void	ft_quedel(t_queue **queue)
{
	if (!queue || !*queue)
		return ;
	if (!ft_queisempty(*queue))
	{
		(*queue)->tail = NULL;
		((*queue)->del ? ft_lstdel(&((*queue)->head), (*queue)->del) :
		ft_lstdel_ic(&((*queue)->head)));
	}
	ft_memdel((void **)queue);
}

void	ft_quedel_old(t_queue **queue, void (*del)(void *, size_t))
{
	if (!queue || !*queue)
		return ;
	if (!ft_queisempty(*queue))
	{
		(*queue)->tail = NULL;
		(del ? ft_lstdel(&((*queue)->head), del) :
		ft_lstdel_ic(&((*queue)->head)));
	}
	ft_memdel((void **)queue);
}
