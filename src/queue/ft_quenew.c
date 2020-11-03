/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quenew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:01:35 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/03 17:18:27 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_queue.h"
#include "libft_list.h"
#include "libft_memory.h"

t_queue	*ft_quenew(void (*del)(void *, size_t))
{
	t_queue	*queue;

	if (!(queue = ft_memalloc(sizeof(t_queue))))
		return (NULL);
	queue->del = del;
	return (queue);
}
