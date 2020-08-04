/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:47:55 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/03 18:39:20 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_getopt.h"
#include "libft_string.h"

int			getoptint(char *ptr, t_option *longopts)
{
	int	i;

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
	char	*ptr;
	int		i;
	int		flag;

	if (!g_optind || g_optreset)
		getoptreset();
	if (g_optind >= acav.argc || !acav.argv[g_optind])
		return (-1);
	g_optarg = 0;
	if (longopts && acav.argv[g_optind][0] == '-' &&
	acav.argv[g_optind][1] == '-' && acav.argv[g_optind][2])
	{
		ptr = acav.argv[g_optind] + 2;
		if ((i = getoptint(ptr, longopts)) != -1)
		{
			g_optind++;
			g_optopt = longopts[i].val;
			while (*ptr && *ptr != '=')
				ptr++;
			if (*ptr == '=')
			{
				if (!longopts[i].has_arg)
					return ('?');
				g_optarg = ptr + 1;
			}
			else if (longopts[i].has_arg == REQUIRED_ARGUMENT)
			{
				if (!(g_optarg = acav.argv[g_optind]))
					return (*shortopts == ':' ? ':' : '?');
				g_optind++;
			}
			if (indexptr)
				*indexptr = i;
			if (longopts[i].flag)
			{
				*(longopts[i].flag) = longopts[i].val;
				return (0);
			}
			return (longopts[i].val);
		}
		if (acav.argv[g_optind][1] == '-')
		{
			g_optind++;
			return ('?');
		}
	}
	return (ft_getopt(acav, shortopts));
}
