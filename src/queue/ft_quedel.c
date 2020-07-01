/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quedel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:16:42 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 20:02:48 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_queue.h"
#include "libft_list.h"
#include <stddef.h>

void	ft_quedel(t_queue **queue, void (*del)(void *, size_t))
{
	if (!queue || !*queue)
		return ;
	(*queue)->tail = NULL;
	ft_lstdel(&((*queue)->head), del);
}
