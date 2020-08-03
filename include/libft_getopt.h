/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_getopt.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:47:27 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/03 18:30:02 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_GETOPT_H

# define LIBFT_GETOPT_H

# define NO_ARGUMENT        0
# define REQUIRED_ARGUMENT  1
# define OPTIONAL_ARGUMENT  2

extern char		*g_optarg;
extern int		g_optopt;
extern int		g_optind;
extern int		g_optreset;

typedef struct	s_option
{
	const char	*name;
	int			has_arg;
	int			*flag;
	int			val;
}				t_option;

typedef struct	s_acav
{
	int			argc;
	char*const	*argv;
}				t_acav;

int				ft_getopt(const t_acav acav, const char *optstring);
int				ft_getopt_long(const t_acav acav, const char *shortopts,
t_option *longopts, int *indexptr);
int				ft_getopt_long_only(const t_acav acav, const char *shortopts,
t_option *longopts, int *indexptr);
void			getoptreset(void);
int				getoptint(char *ptr, t_option *longopts);

#endif
