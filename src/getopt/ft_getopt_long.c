/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:47:55 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/03 15:12:06 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_getopt.h"
#include "libft_string.h"

static void	getoptreset(void)
{
	g_optarg = NULL;
	g_optopt = 0;
	g_optind = 1;
	g_optreset = 0;
}

static int	getoptint(char *ptr, t_option *longopts)
{
	int i;

	i = -1;
	while (longopts[++i].name != NULL)
	{
		if (!ft_strccmp(ptr, longopts[i].name, '='))
			return (i);
	}
	return (-1);
}


int			ft_getopt_long(const t_acav acav, const char *shortopts,
t_option *longopts, int *indexptr)
{
	char 		*ptr;
	int 		i;
	int 		flag;

	if (g_optreset)
		getoptreset();
	if (g_optind >= acav.argc || acav.argv[g_optind][0] != '-')
		return (-1);
	ptr = acav.argv[g_optind];
	g_optopt = *(++ptr);
	i = getoptint(ptr, longopts);
	if (i == -1)
		return (ft_getopt(acav, shortopts));
	if (longopts[i].flag)
		*(longopts[i].flag) = longopts[i].val;
	*indexptr = i;
	if (longopts[i].has_arg)
	{
		while (*ptr && *ptr != '=')
			ptr++;
		if (*ptr && *(++ptr) == '=')
			return (-1);
		if (*ptr)
			g_optarg = ptr;
		else if (acav.argv[++g_optind])
			g_optarg = acav.argv[g_optind];
		else
			return (*shortopts == ':' ? ':' : '?');
	}
	g_optind++;
	return (longopts[*indexptr].val);
}