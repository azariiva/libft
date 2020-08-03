#include "libft.h"
#include <stdio.h>

static t_option longOpts[] = {
    {.name = "language", .has_arg = REQUIRED_ARGUMENT, .val = 'l', .flag = NULL},
    {.name = "help", .has_arg = NO_ARGUMENT, .val = 'h', .flag = NULL},
    {.name = "number", .has_arg = REQUIRED_ARGUMENT, .val = 'n', .flag = NULL},
    {.name = NULL, .has_arg = 0, .val = 0, .flag = NULL},
};

static const char *shortopts = "hl:n:v?";

int main(int ac, char **av)
{
    int rez;
    int i;
    t_acav acav;
    int index;

    acav.argc = ac;
    acav.argv = av;
    index = 0;
    i = 1;
    while ((rez = ft_getopt_long(acav, shortopts, longOpts, &index)) != -1)
    {
        switch (rez)
        {
        case 'l':
            printf("language:\n");
            printf("name: %s\n", longOpts[index].name);
            printf("has_arg: %d\n", longOpts[index].has_arg);
            printf("val: %c\n", longOpts[index].val);
            printf("g_optarg: %s\n", g_optarg);
            printf("g_optopt: %d\n", g_optopt);
            printf("g_optind: %d\n\n", g_optind);
            break;
        case 'h':
            printf("help:\n");
            printf("name: %s\n", longOpts[index].name);
            printf("has_arg: %d\n", longOpts[index].has_arg);
            printf("val: %c\n\n", longOpts[index].val);
            break;
        case 'n':
            printf("number:\n");
            printf("name: %s\n", longOpts[index].name);
            printf("has_arg: %d\n", longOpts[index].has_arg);
            printf("val: %c\n", longOpts[index].val);
            printf("g_optarg: %s\n", g_optarg);
            printf("g_optopt: %d\n", g_optopt);
            printf("g_optind: %d\n\n", g_optind);
            break;
        case 'v':
            printf("vvvvvvvvvvv\n");
            break;
		case '?':
			printf("Error: %s\n", av[g_optind]);
        };
    }

    return 0;
}
