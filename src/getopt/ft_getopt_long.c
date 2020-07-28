/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:47:55 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/27 21:12:23 by fhilary          ###   ########.fr       */
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

int	ft_getopt_long(const t_acav acav, const char *shortopts,
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
	flag = 0;
	i = -1;
	while (longopts[++i].name != NULL && !flag)
	{
		if (ft_strstr(ptr, longopts[i].name))
		{
			if (longopts[i].flag)
				*(longopts[i].flag) = longopts[i].val;
			*indexptr = i;
			flag = 1;
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
		}
	}
	if (!flag)
		return (ft_getopt(acav, shortopts));
	else
	{
		g_optind++;
		return (longopts[*indexptr].val);
	}
}