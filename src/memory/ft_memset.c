/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:16:41 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 19:21:20 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	d;
	size_t			i;

	if (b)
	{
		d = (unsigned char)c;
		p = b;
		i = 0;
		while (i < len)
			p[i++] = d;
	}
	return (b);
}
