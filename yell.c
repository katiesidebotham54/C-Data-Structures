#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //checks if string is empty or no input
    if (argv[1] == "" | argc != 2)
    {
        return 0;
    }
    //traversing string of arguement
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isspace(argv[1][i]))
        {
            printf("%c", argv[1][i]);
            continue;
        }

        //if the char is lowercase, then change to uppercase
        if (islower(argv[1][i]))
        {
            argv[1][i] = toupper(argv[1][i]);
        }
        printf("%c", argv[1][i]);
    }

    printf("!!\n");

    return 0;
}
