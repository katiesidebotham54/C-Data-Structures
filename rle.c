#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void compressString(char *str, int size)
{
    int bufSize = 2 * size;
    char *buffer;
    buffer = malloc(bufSize + 1);
    char *p;
    int output;
    p = buffer;
    for (int i = 0; i < strlen(str); i++)
    {
        int counter = 1;
        while (str[i] == str[i + 1] && i + 1 < strlen(str))
        {
            counter++;
            i++;
        }
        output = snprintf(p, bufSize, "%c%d", str[i], counter);
        p += output;
        bufSize -= output;
    }

    if (strlen(buffer) > strlen(str))
    {
        printf("%s", str);
    }
    else
    {
        printf("%s", buffer);
    }
}

int main(int argc, char *argv[])
{
    char *str = argv[1];
    int size = strlen(str);
    compressString(str, size);
}