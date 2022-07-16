#include <stdio.h>
#include <stdlib.h>

int find_min(long long int number)
{
    int min = number % 10;

    for (int i = 0; number != 0; i++)
    {
        if (number % 10 < min)
        {
            min = number % 10;
        }

        number = number / 10;
    }

    return min;
}

float find_average(long long int number)
{
    float sum = 0;
    int number_of_decimals = 0;

    for (int i = 0; number != 0; i++)
    {
        sum += number % 10;
        number_of_decimals++;
        number /= 10;
    }

    float average = sum / number_of_decimals;

    return average;
}

int main()
{
    FILE *input_data = fopen("Data.txt", "r");
    if (input_data == NULL)
    {
        printf("ERROR");
        exit(1);
    }

    char str[20];
    int number_of_elements = 0;

    while (!feof(input_data))
    {
        fscanf(input_data, " %s", str);
        if (48 <= str[0] && str[0] <= 57) //if it is a number
        {
            number_of_elements++;
            str[0] = ' ';
        }
    }

    rewind(input_data);

    long long int *numbers = calloc(number_of_elements, sizeof(long long int));

    for (int i = 0; i < number_of_elements; i++)
    {
        fscanf(input_data, "%lld", &numbers[i]);
    }

    fclose(input_data);

    FILE *output_data = fopen("result_192010010023.txt", "w");
    if (output_data == NULL)
    {
        printf("ERROR");
        exit(1);
    }

    for (int i = 0; i < number_of_elements; i++)
    {
        fprintf(output_data, "%lld\t-> min: %d, average: %.1f\n", numbers[i], find_min(numbers[i]), find_average(numbers[i]));
    }

    fclose(output_data);

    return 0;
}
