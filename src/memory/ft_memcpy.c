/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:16:45 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/08 16:07:24 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"
#include <stddef.h>

/*
** TODO: rewrite ft_memcpy to make it faster.
** P.S. Use ft_memset as a reference
*/

static inline void		assign(long int dptr, long int sptr)
{
	((t_bl *)dptr)[0] = ((t_bl *)sptr)[0];
	((t_bl *)dptr)[1] = ((t_bl *)sptr)[1];
	((t_bl *)dptr)[2] = ((t_bl *)sptr)[2];
	((t_bl *)dptr)[3] = ((t_bl *)sptr)[3];
	((t_bl *)dptr)[4] = ((t_bl *)sptr)[4];
	((t_bl *)dptr)[5] = ((t_bl *)sptr)[5];
	((t_bl *)dptr)[6] = ((t_bl *)sptr)[6];
	((t_bl *)dptr)[7] = ((t_bl *)sptr)[7];
}

static inline void		incptrs(long int *sptr, long int *dptr, size_t val)
{
	(*sptr) += val;
	(*dptr) += val;
}

static inline void		middle(long int *sptr, size_t *n, long int *dptr)
{
	size_t register	xlen;

	xlen = (*n) / (OPSIZ * 8);
	while (xlen > 0)
	{
		assign(*dptr, *sptr);
		incptrs(sptr, dptr, 8 * OPSIZ);
		xlen--;
	}
	(*n) %= (OPSIZ * 8);
	xlen = (*n) / OPSIZ;
	while (xlen > 0)
	{
		((t_bl *)(*dptr))[0] = ((t_bl *)(*sptr))[0];
		incptrs(sptr, dptr, OPSIZ);
		xlen--;
	}
	(*n) %= OPSIZ;
}

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	long int	dptr;
	long int	sptr;

	if (!(sptr = (long int)src) ||
	!(dptr = (long int)dst))
		return (NULL);
	if (n >= 8)
	{
		while (dptr % OPSIZ != 0)
		{
			((unsigned char *)dptr)[0] = ((unsigned char *)sptr)[0];
			incptrs(&sptr, &dptr, 1);
			n--;
		}
		middle(&sptr, &n, &dptr);
	}
	while (n-- > 0)
	{
		((unsigned char *)dptr)[0] = ((unsigned char *)sptr)[0];
		dptr++;
		sptr++;
	}
	return (dst);
}
