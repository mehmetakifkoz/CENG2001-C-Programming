#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// checks if a character is a vowel
int is_vowel(char c)
{
    //A, E, I, O, and U

    if (c == 'A' || c == 'a' ||
        c == 'E' || c == 'e' ||
        c == 'I' || c == 'i' ||
        c == 'O' || c == 'o' ||
        c == 'U' || c == 'u')
    {
        return 1;
    }

    return 0;
}
// } => Unnecessary curly bracked

//Removes vowels from a string
int main()
{
    int MAX_CHARS = 200;
    // char str[MAX_CHARS]; => CAN'T PUT A VARIABLE IN BRACKEDS.
    char *str = calloc(MAX_CHARS, sizeof(char));
    // WE CAN USE DYNAMIC MEMORY ALLOCATION INSTEAD.

    printf("Enter a string: ");

    // fgets(MAX_CHARS, stdin);     //read string to str from user input
    // 1. fgets() is used for file processing, we need to use gets() instead.
    // 2. The char array is "str" not "stdin"
    gets(str);

    // str[strlen(str) - 1] = '\0'; //removes the last '\n' from str
    // no need to remove '\n' because gets() does not take the '\n' in the string.

    // char result_str[MAX_CHARS];
    char *result_str = calloc(MAX_CHARS, sizeof(char));

    int idx = 0;
    int result_idx = 0;
    while (str[idx] != '\0')
    {
        if (str[idx] == 32)
        {
            result_str[result_idx] = '_'; // == -> =
            result_idx++;
            // break;
        }
        else if (is_vowel(str[idx]) == 0) // if(is_vowel(str[idx]) != 0) => else if(is_vowel(str[idx]) == 0)
        {
            *(result_str + result_idx) = str[idx]; //resultstr => result_str
            result_idx++;
        }
        idx++;
    }
    result_str[result_idx - 1] = '\0';
    printf("Result:\n%s\n", result_str);
    return 0;
}
