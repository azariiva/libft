/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_algo.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:11:02 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/16 20:19:03 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ALGO_H

# define LIBFT_ALGO_H

# include <sys/types.h>
# include <stddef.h>

/*
** ft_swap swaps elements of any type
*/
void	ft_swap(void *a, void *b, size_t esz);

# define FT_SWAP(a, b) (ft_swap((void *)&a, (void *)&b, sizeof(a)))

/*
** > tab is array of any type
** > esz is size of element of array
** > sz is actual size of array in elements
** > cmp is comparator, that returns numbers greater than 0 if a > b or numbers
** less than 0 if a < b or 0 if a == b
*/
void	ft_quicksort(char*const tab, const size_t esz, const size_t sz,
int (*cmp)(void *, void *));

#endif
