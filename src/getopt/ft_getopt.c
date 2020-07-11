/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:10:03 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/12 01:50:05 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_getopt.h"
#include "libft_string.h"
#include <stdio.h>

char		*g_optarg;
int			g_optopt;
int			g_optind = 1;

int			helper(int argc, char*const argv[], const char *opstring,
const char **ptr)
{
	char	*op;

	if (!(op = ft_strchr(opstring, *(*ptr)++)))
	{
		(**ptr ? 0 : (*ptr = argv[++g_optind]));
		return ('?');
	}
	if (op[1] != ':')
		(**ptr ? 0 : (*ptr = argv[++g_optind]));
	else if (**ptr && (g_optarg = (char *)*ptr))
		*ptr = argv[++g_optind];
	else
	{
		if (++g_optind == argc)
			return (*opstring == ':' ? ':' : '?');
		g_optarg = (char *)argv[g_optind];
		*ptr = argv[++g_optind];
	}
	return (*op);
}

int			ft_getopt(int argc, char*const argv[], const char *optstring)
{
	static const char	*ptr;
	static int			finished;

	g_optarg = NULL;
	(ptr ? 0 : (ptr = argv[g_optind]));
	if (g_optind >= argc || finished || (ptr == argv[g_optind] && *ptr++ != '-'
	&& (finished = 1)))
		return (-1);
	if (!ft_strcmp(ptr, "-"))
	{
		ptr = argv[++g_optind];
		return (-1);
	}
	g_optopt = *ptr;
	return (helper(argc, argv, optstring, &ptr));
}
