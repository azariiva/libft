/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 21:04:47 by blinnea           #+#    #+#             */
/*   Updated: 2020/06/28 21:09:16 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strchr_plus() function returns a pointer to the first occurrence of the
** character which satisfies function cmp.
*/

#include "libft.h"

char		*ft_strchr_plus(const char *s, int (*cmp)(int))
{
	while (*s)
	{
		if (cmp(*s))
			return ((char *)s);
		++s;
	}
	if (cmp(*s))
		return ((char *)s);
	return (NULL);
}
