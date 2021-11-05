#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char** stringParser(const char* string, char delimiter)
{
    if (string == NULL)
        return NULL;

    int spaces = 0;
    int maxWordSize = 0;
    int currentWordSize = 0;

    for (int i = 0; true; i++)
    {
        if (string[i] == delimiter)
        {
            spaces++;

            if (currentWordSize >= maxWordSize)
            {
                maxWordSize = currentWordSize;
                currentWordSize = 0;
            }
            continue;
        }
        else if (string[i] == '\0')
        {
            if (currentWordSize >= maxWordSize)
            {
                maxWordSize = currentWordSize;
                currentWordSize = 0;
            }

            break;
        }
        currentWordSize++;
    }

    int arraySize = spaces + 2; //words = spaces + 1 (+ 1 for NULL)

    char** parsedStrings = calloc(arraySize, sizeof(char*));

    if (parsedStrings == NULL)
        return NULL;

    for (int i = 0; i < arraySize; i++)
    {
        parsedStrings[i] = calloc(maxWordSize, sizeof(char));

        if (parsedStrings[i] == NULL)
        {
            printf("Allocation Error!\n");

            for (int j = 0; j < i; j++)
                free(parsedStrings[j]);

            return NULL;
        }
    }

    if (arraySize == 2) //Only 1 word + NULL
    {
        for (int i = 0; string[i] != '\0'; i++)
        {
            parsedStrings[0][i] = string[i];
        }

        parsedStrings[1] = NULL;
    }
    else if (arraySize < 2) //something went HORRIBLY WRONG!
        return NULL;
    else
    {
        int i = 0;

        for (int y = 0; true; y++)
        {
            for (int x = 0; true; x++)
            {
                if (string[i] == delimiter || string[i] == '\0')
                {
                    parsedStrings[y][x] = '\0';
                    break;
                }
                else
                    parsedStrings[y][x] = string[i];

                i++;
            }

            if (string[i] == '\0')
                break;

            i++;
        }
    }

    parsedStrings[arraySize - 1] = NULL;

    return parsedStrings;
}