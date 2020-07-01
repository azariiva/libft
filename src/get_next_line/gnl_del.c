/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 00:31:14 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/02 00:35:57 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"
#include "libft_list.h"

void	gnl_strdel(void *content, size_t size)
{
	if (size)
		ft_memdel(&content);
}

void	gnl_fddel(void *content, size_t size)
{
	if ((int)size >= 0)
		ft_lstdel((t_list **)&content, gnl_strdel);
}
