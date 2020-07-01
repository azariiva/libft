/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quepop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:11:52 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 20:02:23 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_queue.h"
#include <stddef.h>

t_list	*ft_quepop(t_queue *queue)
{
	t_list	*elem;

	if (queue->head == queue->tail)
	{
		elem = queue->head;
		queue->head = NULL;
		queue->tail = NULL;
	}
	else
	{
		elem = queue->head;
		queue->head = queue->head->next;
		elem->next = NULL;
	}
	return (elem);
}
