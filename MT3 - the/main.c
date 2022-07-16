#include <stdio.h>

int main()
{
    char string[] = "The most interesting words that include the are therapeutically, openmouthed, theory, etherealization, mathematical.";
    int i = 0, j = 1, k = 2;
    int count = 0;
    while (string[k] != '\0')
    {
        if ((string[i] == 't' || string[i] == 'T') &&
            (string[j] == 'h' || string[j] == 'H') &&
            (string[k] == 'e' || string[k] == 'E'))
            count++;
        i++;
        j++;
        k++;
    }
    printf("%d\n", count);
    return 0;
}
