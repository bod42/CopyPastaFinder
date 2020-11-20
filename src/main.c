#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/CopyPasta.h"

void help()
{
    printf("\nCopyPastaFinder ver: 0.0.1\n\nuse: ./CopyPastaFinder <arg1>  <arg2>\n\narg1 and arg2 = files you want to compare\n");
}
void initStruct(CopyPast *copy, int ac, char **av)
{
    copy->ac = ac;
    copy->av = av;
    copy->files = NULL;
    copy->i = 4;
}

int main(int ac, char **av)
{
    CopyPast *copy;
    copy = (CopyPast *)malloc(sizeof(CopyPast));
    initStruct(copy, ac, av);
    if (ac == 2 && strcmp(av[1], "-h") == 0)
    {
        help();
        return (0);
    }
    else if (ac < 3 || ac > 3)
    {
        printf("Error: not enough argument, look at the help for condition of use (-h) \n");
        return (-1);
    }
    else
        copyPasta(copy);

    return (0);
}