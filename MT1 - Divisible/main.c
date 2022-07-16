#include <stdio.h>

int checkPrime(int number);

int main()
{
    int input;
    printf("Input: ");
    scanf("%d", &input);

    printf("Output: ");
    for (int i = 2; i <= input; i++)
    {
        if (input % i == 0 && checkPrime(i) == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}

int checkPrime(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number == 2)
        {
            return 1;
            // True
        }
        else if (number % i == 0)
        {
            return 0;
            // False
        }
        else
        {
            continue;
        }
    }
    return 1;
    // True
}
