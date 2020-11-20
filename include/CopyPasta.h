#ifndef COPYPASTA
#define COPYPASTA

typedef struct CopyPast
{
    int i;
    int ac;
    char **av;
    char **files;
} CopyPast;


int copyPasta(CopyPast *);
char **openFiles(char *, char *);

#endif