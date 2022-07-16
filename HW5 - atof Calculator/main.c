#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int check_error(char *input)
{ //This function checks for errors.

    for (int i = 0; input[i] != '\0'; i++) // All characters of input will be scanded till the null termination character
    {
        if (('0' <= input[i] && input[i] <= '9') || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == ' ')
        { // if the character is valid:

            continue;
        }
        else
        {
            return 1;
            // Invalid String
        }
    }
    return 0;
    // Valid String
}

float string_to_float(char *input) //atof function
{                                  // This funciton takes a string as an input and returns its value output in float type.

    char char_float[250];
    //The stripped float from string is defined as char_float.

    int null_index = 0;
    //The null termination character's index is defined as null index.

    for (int index = 0; input[index] != '\0'; index++) //strips numbers from string.
    {
        if ('0' <= input[index] && input[index] <= '9')
        { // If the character is a number:

            char_float[index] = input[index];
            // it is appended to char_float string.

            null_index++;
            // Every successful append increases the size of string. Therefore null_index is increased.
        }
        else if (input[index] == '.')
        { // else if the character is dot(.):

            char_float[index] = '.';
            // it is appended to char_float string.

            null_index++;
            // null_index is increased.
        }
        else
        { // If the character is the operation character:
            break;
            // The for loop ended.
        }
    }

    char_float[null_index] = '\0';
    // char_float is limitted.
    // This is done because if the input number is an integar it gives error.

    int index = 0;
    // the index number of char_float

    float output = 0;
    // the function's output

    int count = 0;
    // the count of numbers before dot(.)

    int decimal = 1;

    for (int i = 0; char_float[i] != '\0'; i++)
    {
        if (char_float[i] == '.')
        {
            break;
        }
        count++;
        // The count of numbers before dot(.)
    }

    decimal = pow(10, --count);

    while (char_float[index] != '.')
    { // Till the character dot(.):

        output += (char_float[index] - 48) * decimal;
        // the number is converted from char to int and the output is assembled.

        index++;
        decimal /= 10;
        // next decimal
    }

    int temp_index = ++index;
    // temporary index

    int float_count = 0;
    // the count of numbers after dot(.)

    while (char_float[index] != '\0')
    { // Till the end of string:
        index++;
        float_count++;
    }

    float float_decimal = pow(10, -float_count);

    temp_index += float_count;
    temp_index--;

    for (int j = 0; j < float_count; j++)
    {
        output += (char_float[temp_index] - 48) * float_decimal;
        // the number is converted from char to int and the output is assembled.

        temp_index--;
        float_decimal *= 10;
    }

    return output;
}

int main()
{
    printf("*atof Calculator by Mehmet Akif KOZ 192010010023\n");
    printf("*This program calculates the sum, difference, product and division of two float numbers using atof function.\n");
    printf("*Instructions: Type a mathematical expression and press \"Enter\" on your keyboard to display the result.\n\n");

    char input[250];
    gets(input);

    int error = check_error(input);

    if (error == 1) // If there is any error:
    {
        printf("Error code 1: Invalid String\n");
        exit(1); //Error code 1
    }

    float number1, number2;
    // The variables number1 and number2 are defined to be of type float.

    char operation;
    // The variable operation is defined to be of type char.

    number1 = string_to_float(input);
    // number1 is obtained from user input.

    int index = 0;

    while (1) // operation is stripped.
    {
        if (input[index] == '+' || input[index] == '-' || input[index] == '*' || input[index] == '/')
        {
            break;
        }

        index++;
    }

    operation = input[index];
    // operation is converted into float.

    while (1)
    {
        if ('0' <= input[index] && input[index] <= '9')
        {
            break;
        }

        index++;
        // Starting index of number2 is index.
    }

    char temp[250];
    int temp_index = 0;

    while (input[index] != 0)
    {
        temp[temp_index] = input[index];
        // number2 is assigned in a temporary char array in string form.
        index++;
        temp_index++;
    }

    number2 = string_to_float(temp);
    // number2 is converted into float.

    if (operation == 43) // If the operation is sum (decimal 43 corresponds to "+" in ASCII Table):
    {
        float sum;
        // The variable sum is defined to be of type float.

        sum = number1 + number2;
        // The sum of variables number1 and number2 is calculated and it is assigned to variable sum.

        printf("%.2f + %.2f = %.2f\n", number1, number2, sum);
        // The sum is displayed.
    }

    if (operation == 45) // If the operation is difference (decimal 45 corresponds to "-" in ASCII Table)
    {
        float difference;
        // The variable difference is defined to be of type float.

        difference = number1 - number2;
        // The difference of variables number1 and number2 is calculated and it is assigned to variable difference.

        printf("%.2f - %.2f = %.2f\n", number1, number2, difference);
        // The difference is displayed.
    }

    if (operation == 42) // If the operation is product (decimal 42 corresponds to "*" in ASCII Table):
    {
        float product;
        // The variable product is defined to be of type float.

        product = number1 * number2;
        // The product of variables number1 and number2 is calculated and it is assigned to variable product.

        printf("%.2f * %.2f = %.2f\n", number1, number2, product);
        // The product is displayed.
    }

    if (operation == 47) // If the operation is division (decimal 47 corresponds to "/" in ASCII Table)
    {
        float division;
        // The variable division is defined to be of type float.

        division = number1 / number2;
        // The division of variables number1 and number2 is calculated and it is assigned to variable division.

        printf("%.2f / %.2f = %.2f\n", number1, number2, division);
        // The division is displayed.
    }

    return 0;
}
