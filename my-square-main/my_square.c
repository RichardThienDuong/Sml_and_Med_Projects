#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int ac, char **av) 
{
if (ac == 3 ) 
{ 
int x = atoi(av[1]);
int y = atoi(av[2]);

    for (int j = 1; j < (y + 1); j++) 
    {
        if ((j == 1) || (j == y))
        {
            for(int i = 1; i < (x + 1); i++) 
            {
                if ((i == 1) || (i == x)) { printf("o"); }
                else { printf("-"); }
            } 
        }
        else
        {
            for(int k = 1; k < (x + 1); k++) 
            {
                if ((k == 1) || (k == x)) { printf("|"); }
                else { printf(" "); }
            } 
        }
        printf("\n");
    }
}
}

// to run type "./a.out 4 4" any set of numbers will do , give it a shot :) 
