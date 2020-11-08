/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elistdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:27:04 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/08 17:36:12 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_elist.h"
#include "libft_memory.h"

void			ft_elistdel(t_elist **elist)
{
	if (!elist || !*elist)
		return ;
	if ((*elist)->head)
		ft_dlstdel(&((*elist)->head), (*elist)->del);
	ft_memdel((void **)elist);
}
