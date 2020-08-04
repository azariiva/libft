/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_long_only.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:24:44 by fhilary           #+#    #+#             */
/*   Updated: 2020/08/03 18:25:57 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_getopt.h"
#include "libft_string.h"

int			ft_getopt_long_only(const t_acav acav, const char*const shortopts,
t_option*const longopts, int*const indexptr)
{
	char	*ptr;
	int		i;
	int		flag;

	if (!g_optind || g_optreset)
		getoptreset();
	if (g_optind >= acav.argc || acav.argv[g_optind][0] != '-')
		return (-1);
	g_optarg = 0;

	if (longopts ||
	((acav.argv[g_optind][1] == '-' && acav.argv[g_optind][2]) &&
	(acav.argv[g_optind][1] && acav.argv[g_optind][1] != '-')))
	{
		ptr = acav.argv[g_optind];
		if (*(++ptr) == '-')
			ptr++;
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
			return (longopts[*indexptr].val);
		}
		if (acav.argv[g_optind][1] == '-')
		{
			g_optind++;
			return ('?');
		}
	}
	return (ft_getopt(acav, shortopts));
}
