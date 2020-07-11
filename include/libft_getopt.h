/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_getopt.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:47:27 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/12 00:20:37 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_GETOPT_H

# define LIBFT_GETOPT_H

extern char		*g_optarg;
extern int		g_optopt;
extern int		g_optind;

/*
** The getopt() function incrementally parses a command line argument list argv
** and returns the next known option character.  An option character is known if
** it has been specified in the string of accepted option characters, optstring.
**
** The option string optstring may contain the following elements: individual
** characters, and characters followed by a colon to indicate an option argument
** is to follow.  For example, an option string "x" recognizes an option ``-x'',
** and an option string "x:" recognizes an option and argument ``-x argument''.
** It does not matter to getopt() if a following argument has leading white
** space.
**
** On return from getopt(), g_optarg points to an option argument, if it is
** anticipated, and the variable optind contains the index to the next argv
** argument for a subsequent call to getopt().  The variable g_optopt saves the
** last known option character returned by getopt().
**
** The variable g_optind are both initialized to 1.  The optind
** variable may be set to another value before a set of calls to getopt() in
** order to skip over more or less argv entries.
**
** In order to use getopt() to evaluate multiple sets of arguments, or to
** evaluate a single set of arguments multiple times, the variable optreset must
** be set to 1 before the second and each additional set of calls to getopt(),
** and the variable optind must be reinitialized.
**
** The getopt() function returns -1 when the argument list is exhausted.  The
** interpretation of options in the argument list may be cancelled by the option
** `--' (double dash) which causes getopt() to signal the end of argument
** processing and return -1.  When all options have been processed (i.e., up to
** the first non-option argument), getopt() returns -1.
**
** The getopt() function returns the next known option character in optstring.
** If getopt() encounters a character not found in optstring or if it detects a
** missing option argument, it returns `?' (question mark).  If optstring has a
** leading `:' then a missing option argument causes `:' to be returned instead
** of `?'.  In either case, the variable g_optopt is set to the character that
** caused the error.  The getopt() function returns -1 when the argument list is
** exhausted.
*/
int	ft_getopt(int argc, char*const argv[], const char *optstring);

#endif
