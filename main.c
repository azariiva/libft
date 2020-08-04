#include "libft.h"
#include <stdio.h>
#include <getopt.h>

static int			defFlags[4];
static struct option defLongOpts[] = {
    {.name = "language", .has_arg = required_argument, .val = 'l', .flag = defFlags},
    {.name = "help", .has_arg = no_argument, .val = 'h', .flag = defFlags + 1},
    {.name = "number", .has_arg = required_argument, .val = 'n', .flag = defFlags + 2},
	{.name = "option", .has_arg = optional_argument, .val = 'o', .flag = defFlags + 3},
    {.name = NULL, .has_arg = 0, .val = 0, .flag = NULL},
};

static int			ourFlags[4];
static t_option		ourLongOpts[] = {
	{.name = "language", .has_arg = required_argument, .val = 'l', .flag = ourFlags},
    {.name = "help", .has_arg = no_argument, .val = 'h', .flag = ourFlags + 1},
    {.name = "number", .has_arg = required_argument, .val = 'n', .flag = ourFlags + 2},
	{.name = "option", .has_arg = optional_argument, .val = 'o', .flag = ourFlags + 3},
    {.name = NULL, .has_arg = 0, .val = 0, .flag = NULL},
};

static const char *shortopts = "hl:n:v?";

static void		getOptReference(int ac, char *av)
{
	int	index;
	int	res;

	index = 0;
	while ((res = getopt_long(ac, av, shortopts, defLongOpts, &index)) != -1)
    {
        switch (res)
        {
        case 'l':
            printf("language:\n");
            printf("name: %s\n", defLongOpts[index].name);
            printf("has_arg: %d\n", defLongOpts[index].has_arg);
            printf("val: %c\n", defLongOpts[index].val);
            printf("optarg: %s\n", optarg);
            printf("optopt: %d\n", optopt);
            printf("optind: %d\n\n", optind);
            break;
        case 'h':
            printf("help:\n");
            printf("name: %s\n", defLongOpts[index].name);
            printf("has_arg: %d\n", defLongOpts[index].has_arg);
            printf("val: %c\n\n", defLongOpts[index].val);
			printf("optarg: %s\n", optarg);
            break;
        case 'n':
            printf("number:\n");
            printf("name: %s\n", defLongOpts[index].name);
            printf("has_arg: %d\n", defLongOpts[index].has_arg);
            printf("val: %c\n", defLongOpts[index].val);
            printf("optarg: %s\n", optarg);
            printf("optopt: %d\n", optopt);
            printf("optind: %d\n\n", optind);
            break;
        case 'v':
            printf("vvvvvvvvvvv\n");
            break;
		case '?':
			printf("Error: %s\n", av[optind]);
			break;
        }
    }
}

static void		showTestStat(const char*const *name, int index)
{
	printf("%s:\n", name);
	print("{index} {name}".format(name=name, index=index))
}

static void		getOptTest(int ac, char **av)
{
	int res;
    int index;

    index = 0;
    while ((res = ft_getopt_long((t_acav){.argc=ac, .argv=av}, shortopts, ourLongOpts, &index)) != -1)
    {
        switch (res)
        {
        case 'l':
            printf("language:\n");
            printf("name: %s\n", ourLongOpts[index].name);
            printf("has_arg: %d\n", ourLongOpts[index].has_arg);
            printf("val: %c\n", ourLongOpts[index].val);
            printf("optarg: %s\n", g_optarg);
            printf("optopt: %d\n", g_optopt);
            printf("optind: %d\n\n", g_optind);
            break;
        case 'h':
            printf("help:\n");
            printf("name: %s\n", ourLongOpts[index].name);
            printf("has_arg: %d\n", ourLongOpts[index].has_arg);
            printf("val: %c\n\n", ourLongOpts[index].val);
			printf("optarg: %s\n", g_optarg);
            break;
        case 'n':
            printf("number:\n");
            printf("name: %s\n", ourLongOpts[index].name);
            printf("has_arg: %d\n", ourLongOpts[index].has_arg);
            printf("val: %c\n", ourLongOpts[index].val);
            printf("optarg: %s\n", g_optarg);
            printf("optopt: %d\n", g_optopt);
            printf("optind: %d\n\n", g_optind);
            break;
        case 'v':
            printf("vvvvvvvvvvv\n");
            break;
		case '?':
			printf("Error: %s\n", av[g_optind]);
        };
    }
}

int main(int ac, char **av)
{
    int rez;
    int index;

    index = 0;
    while ((rez = getopt_long(ac, av, shortopts, ourLongOpts, &index)) != -1)
    {
        switch (rez)
        {
        case 'l':
            printf("language:\n");
            printf("name: %s\n", ourLongOpts[index].name);
            printf("has_arg: %d\n", ourLongOpts[index].has_arg);
            printf("val: %c\n", ourLongOpts[index].val);
            printf("optarg: %s\n", optarg);
            printf("optopt: %d\n", optopt);
            printf("optind: %d\n\n", optind);
            break;
        case 'h':
            printf("help:\n");
            printf("name: %s\n", ourLongOpts[index].name);
            printf("has_arg: %d\n", ourLongOpts[index].has_arg);
            printf("val: %c\n\n", ourLongOpts[index].val);
			printf("optarg: %s\n", optarg);
            break;
        case 'n':
            printf("number:\n");
            printf("name: %s\n", ourLongOpts[index].name);
            printf("has_arg: %d\n", ourLongOpts[index].has_arg);
            printf("val: %c\n", ourLongOpts[index].val);
            printf("optarg: %s\n", optarg);
            printf("optopt: %d\n", optopt);
            printf("optind: %d\n\n", optind);
            break;
        case 'v':
            printf("vvvvvvvvvvv\n");
            break;
		case '?':
			printf("Error: %s\n", av[optind]);
        };
    }

    return 0;
}
