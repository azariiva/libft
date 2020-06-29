/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:35:34 by blinnea           #+#    #+#             */
/*   Updated: 2020/06/28 21:12:39 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const	*start;
	char const	*end;
	size_t	len;

	if (!s)
		return (NULL);
	if (!*(start = ft_strchr_plus(s, ft_isspace)))
		len = 0;
	else
	{
		end = s + ft_strlen(s) - 1;
		while (ft_isspace(*end))
			--end;
		len = end - start + 1;
	}
	return (ft_strsub(s, start - s, len));
}
