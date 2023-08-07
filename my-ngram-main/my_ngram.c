#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) 
{
    char letters[100];
    int count[100];
    for(int h = 0; h < 100; h++) 
    {
        letters[h] = 0;
        count[h] = 1;
    }
    for (int i = 1; i < argc; i++) 
    {
        for (int j = 0; j < strlen(argv[i]); j++)
        {
            int matches = 0;

            for (int k = 0; k < strlen(letters); k++)
            {   
                if (letters[k] == argv[i][j])
                {
                    count[k]++;
                    matches++;
                }
            }
            if (matches == 0 && argv[i][j] != '\"') 
            {
            letters[strlen(letters)] = argv[i][j];
            } 
        }
    }
    
    char temp;
	int i, j, temp2;
	int n = strlen(letters);
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if (letters[i] > letters[j]) {
					temp = letters[i];
					letters[i] = letters[j];
					letters[j] = temp;

                    temp2 = count[i];
                    count[i] = count[j];
                    count[j] = temp2;
			}
		}
	}
    for (int f = 0; f < (strlen(letters)); f++)
    {
        printf("%c:%d\n", letters[f], count[f]);
    }
    return 0;
}
