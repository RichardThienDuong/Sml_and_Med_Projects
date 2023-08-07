#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include "includes.h"

char *randstring() {

    static char charset[] = "01234567";        
    random_string = NULL;
    random_string = malloc(sizeof(char) * (4 + 1));
        if (random_string) {            
            for (int n = 0; n < 4 ; n++) {            
                int key = rand() % (int)(sizeof(charset) - 1);
                random_string[n] = charset[key];
                int k = strlen(random_string);
                for (int i = 0; i < (k - 1); i++)
                {
                    if (random_string[n] == random_string[i])
                    {
                        while(random_string[n] == random_string[i])
                        {
                            key = rand() % (int)(sizeof(charset) - 1);
                            random_string[n] = charset[key];
                        }
                    }
                }
            }
            random_string[4] = '\0';
        }
    return random_string;
}

int secret_code_and_attempts(int argc, char *argv[])
{
    attempts = 10;
    secret_code = (char*) malloc(5 * sizeof(int));
    for(int i = 0; i < argc; i++)
    {
        if(argc == 1)
        {  
            srand(time(0));
            randstring();
            secret_code = random_string;
        }
        if (strcmp(argv[i], "-c") == 0)
        {
            secret_code = argv[i+1];
        }
        if (strcmp(argv[i], "-t") == 0)
        {
            attempts = atoi(argv[i+1]);
        }
    }
   return 0;
};

int games_begin()
{
    printf("Will you find my secret code?\n");
    printf("Please enter a valid guess\n");
   //printf("---\n");
    return 0;
};

char check_input()
{        
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
    return *entered_code;
}

int misplaced()
{
    misplaced_count = 0;

    for(int i = 0; i < 4; i++)
    {
        if (entered_code[i] != secret_code[i])
        {
            for(int j = 0; j < 4; j++)
            {
                if(entered_code[i] == secret_code[j])
                {
                    misplaced_count++;
                }
            }
        }
    }
    printf("Misplaced pieces: %d\n", misplaced_count);
    //printf("---\n");
    return misplaced_count;
}

    // 1. takes in -c & -t or else random or default
    // 2. once have secret code & attempts print "Will you find my secret code?"
    // 3. If round > -t then end game and print lose game
    // 4. print round then ask for user input
    // 5. If wrong input then print "wrong input" then ask for input again
    // 6. run input through secret code and count # of well placed pieces there are, If count = 4 then 
    //      end game and print "Congratz You Did It!" else print count and continue
    // 7. run input through secret code and count # of misplaced peices then print count and continue
    //      back to step 3
