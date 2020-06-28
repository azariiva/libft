/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:51:37 by blinnea           #+#    #+#             */
/*   Updated: 2020/06/28 19:55:46 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Skips all symbols which are satisfy function cmp or doesn't satisfy
** depends of negation value (0 or any other).
*/

void	ft_strskip(char **str, int (*cmp)(int), int negation)
{
	while (cmp(**str) ^ negation)
		(*str)++;
}
