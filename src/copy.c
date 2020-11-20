#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/CopyPasta.h"

char **malloc_tab(char **tab, int size, int size2)
{
    int i = 0;
    int y = 0;

    while (i <= 2)
    {
        y = 0;
        while (y <= 2)
        {
            tab = malloc(sizeof(char *) * size + size2);
            y += 1;
        }
        tab[i] = malloc(sizeof(char) * size + size2);
        i += 1;
    }
    return (tab);
}

char **openFiles(char *fileOne, char *fileTwo)
{
    int *fd = NULL;
    int i = 0;
    int y = 0;
    char c = 0;
    char *str = malloc(sizeof(char) * (sizeof(fileOne) + sizeof(fileTwo)) + 1);
    char **files = malloc_tab(files, strlen(fileOne), strlen(fileTwo));
    int size = 1;

    fd = malloc(sizeof(fileOne) + sizeof(fileTwo) + 1);
    str = malloc(sizeof(fileOne) + sizeof(fileTwo) + 1);
    fd[1] = open(fileOne, O_RDONLY);
    fd[2] = open(fileTwo, O_RDONLY);
    if (fd[1] == -1 || fd[2] == -1)
    {
        printf("ERROR: files cannot be opened\n");
        exit(-1);
    }

    while (i <= 2)
    {
        y = 0;
        int flags = fcntl(fd[i], F_GETFL, 0);
        fcntl(fd[i], F_SETFL, flags | O_NONBLOCK);
        while (read(fd[i], &c, 1) > 0)
        {
            str[y] = c;
            y += 1;
        }
        files[i] = str;
        i += 1;
    }
    str = NULL;
    close(fd[1]);
    close(fd[2]);
    return (files);
}

int copyPasta(CopyPast *copy)
{
    copy->files = openFiles(copy->av[1], copy->av[2]);
    printf("files[1] = %s\nfiles[2] = %s\n", copy->files[1], copy->files[2]);
    return (0);
}