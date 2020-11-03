/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quepop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:11:52 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/03 17:45:04 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_queue.h"
#include <stddef.h>
#include "libft_memory.h"

t_list	*ft_quepop(t_queue *queue)
{
	t_list			*elem;
	static t_list	ret;

	elem = ft_lstpoptop(&(queue->head));
	ft_memcpy(&ret, elem, sizeof(ret));
	ft_lstdelone(&elem, queue->del);
	if (!queue->head && queue->tail)
		queue->tail = NULL;
	return (&ret);
}
