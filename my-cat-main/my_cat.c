#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#define BUFFER_SIZE 500

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        fprintf(stderr, "Usage: ./wcat <filepath>");
        exit(1);
    }
    FILE *fp;
    char *buffer;
    for (int i = 1; i < argc; i++) 
    {
        buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
        fp = fopen(argv[i], "r");
        if (fp == NULL) 
        {
            printf("wcat: cannot open file\n");
            exit(1);
        }
        while ((buffer = fgets(buffer, BUFFER_SIZE, fp)) != NULL) 
        {
            printf("%s", buffer);
        }
        fclose(fp);
    }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <unistd.h>

// void my_cat(FILE *fp, char *str)
// {
//     fscanf(fp, "%s", str);
// }

// int main(void)
// {
//     char *str;
//     FILE *fp;

//     fp = fopen("hello.txt", "a");
//     if (fp == NULL)
//     {
//         printf("Couldn't open file\n");
//         return 1;
//     }
//     my_cat(fp, str);

//     fclose(fp);

//     return 0;
// }
/*
FILE *fptr;
EX: fopen("E:\\cprogram\\newprogram.txt","r");
fprintf();
fclose(fptr);
*/
