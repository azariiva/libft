#include "libft.h"
#include <stdio.h>
#include <getopt.h>

static int			defFlag;
static struct option defLongOpts[] = {
    {.name = "language", .has_arg = required_argument, .val = 'l', .flag = &defFlag},
    {.name = "help", .has_arg = no_argument, .val = 'h', .flag = &defFlag},
    {.name = "number", .has_arg = required_argument, .val = 'n', .flag = &defFlag},
	{.name = "option", .has_arg = optional_argument, .val = 'o', .flag = &defFlag},
    {.name = NULL, .has_arg = 0, .val = 0, .flag = NULL},
};

static int			ourFlags;
static t_option		ourLongOpts[] = {
	{.name = "language", .has_arg = required_argument, .val = 'l', .flag = &ourFlags},
    {.name = "help", .has_arg = no_argument, .val = 'h', .flag = &ourFlags},
    {.name = "number", .has_arg = required_argument, .val = 'n', .flag = &ourFlags},
	{.name = "option", .has_arg = optional_argument, .val = 'o', .flag = &ourFlags},
    {.name = NULL, .has_arg = 0, .val = 0, .flag = NULL},
};

static const char *shortopts = "hl:n:v";


static void		showReferenceStat(const char*const name, int index)
{
	printf("%s:\n", name);
	printf("name: %s\n", defLongOpts[index].name);
	printf("has_arg: %d\n", defLongOpts[index].has_arg);
	printf("flag: %d:\n", *defLongOpts[index].flag);
	printf("val: %c\n", defLongOpts[index].val);
	printf("optarg: %s\n", optarg);
	printf("optopt: %c\n", optopt);
	printf("optind: %d\n\n", optind);
}

static void		getOptReference(int ac, char **av)
{
	int	index;
	int	res;

	index = 0;
	while ((res = getopt_long(ac, av, shortopts, defLongOpts, &index)) != -1)
    {
		if (defFlag == 'l')
			showReferenceStat("language2", index);
		else if (defFlag == 'h')
			showReferenceStat("help2", index);
		else if (defFlag == 'n')
			showReferenceStat("number2", index);
		else if (defFlag == 'o')
			showReferenceStat("option2", index);
		else
			switch (res)
			{
			case 'l':
				showReferenceStat("language", index);
				break;
			case 'h':
				showReferenceStat("help", index);
				break;
			case 'n':
				showReferenceStat("number", index);
				break;
			case 'v':
				showReferenceStat("v", index);
				break;
			case '?':
				showReferenceStat("?", index);
				break;
			case ':':
				showReferenceStat(":", index);
				break;
			}
    }
}

static void		showTestStat(const char*const name, int index)
{
	printf("%s:\n", name);
	printf("name: %s\n", ourLongOpts[index].name);
	printf("has_arg: %d\n", ourLongOpts[index].has_arg);
	printf("flag: %d:\n", *ourLongOpts[index].flag);
	printf("val: %c\n", ourLongOpts[index].val);
	printf("optarg: %s\n", g_optarg);
	printf("optopt: %c\n", g_optopt);
	printf("optind: %d\n\n", g_optind);
}

static void		getOptTest(int ac, char **av)
{
	int res;
    int index;

    index = 0;
    while ((res = ft_getopt_long((t_acav){.ac=ac, .av=av}, shortopts, ourLongOpts, &index)) != -1)
    {
		if (ourFlags == 'l')
			showTestStat("language2", index);
		else if (ourFlags == 'h')
			showTestStat("help2", index);
		else if (ourFlags == 'n')
			showTestStat("number2", index);
		else if (ourFlags == 'o')
			showTestStat("option2", index);
		else
			switch (res)
			{
			case 'l':
				showTestStat("language", index);
				break;
			case 'h':
				showTestStat("help", index);
				break;
			case 'n':
				showTestStat("number", index);
				break;
			case 'v':
				showTestStat("v", index);
				break;
			case '?':
				showTestStat("?", index);
				break;
			case ':':
				showTestStat(":", index);
				break;
			}
    }
}

int main(int ac, char **av)
{
	getOptReference(ac, av);
	printf("------------------\n");
	getOptTest(ac, av);

    return 0;
}
