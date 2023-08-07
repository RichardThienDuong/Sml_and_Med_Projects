#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "includes.h"

int main (int argc, char *argv[])
{
    // 1. takes in -c & -t or else random or default
    secret_code_and_attempts(argc, argv);
    //printf("secret code : %s\n", secret_code);

    // 2. once have secret code & attempts print "Will you find my secret code?"
    games_begin();

    // 3. If round > -t then end game and print lose game
    // 4. print round then ask for user input
    // 5. If wrong input then print "wrong input" then ask for input again
    // 6. run input through secret code and count # of well placed pieces there are, If count = 4 then 
    //      end game and print "Congratz You Did It!" else print count and continue
    // 7. run input through secret code and count # of misplaced peices then print count and continue
    //      back to step 3
    current_round = 1;
    entered_code = (char *) calloc(4, sizeof(char));

    for(int i = 0; i < (attempts + 1); i++) // to cycle through for game
    {
        if (current_round == (attempts + 1))
        {
            printf("Sorry no more attempts , Game Over.\n");
            return(0);
        }
        printf("Round %d\n", current_round);

        temp = read(0, entered_code, 10);

        if (temp == 0) // for ctrl d 
        {
            return 0;
        }
 
    int j = 0;

    while (temp != 5 || j != 4)
    {   
        j = 0;


        if(temp != 5)
        {
            printf("Wrong Input! Please Try again\n");
            temp = read(0, entered_code, 10);
            if (temp == 0) // for ctrl d 
            {
                return 0;
            }
        }
        for(int i = 0; i < 4; i++)
        {
            if (entered_code[i] >= 48 && entered_code[i] <= 57)
            {
                j++;
            }
        }
        if(j < 4)
        {
            printf("Wrong Input! Please Try again\n");
            temp = read(0, entered_code, 10);
            if (temp == 0) // for ctrl d 
            {
                return 0;
            }
        }
    }  

        
        wellplaced_count = 0;

        for(int i = 0; i < 4; i++)
        {
            if (entered_code[i] == secret_code[i])
            {
                wellplaced_count++;
            }
        }
        if(wellplaced_count == 4)
        {
            printf("Congratz! You did it!\n");
            return(0);
        }
        printf("Well placed pieces: %d\n", wellplaced_count);
        
        misplaced();
        
        current_round++;
    }

    return 0;
}
