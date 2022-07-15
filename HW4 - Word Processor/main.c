#include <stdio.h>
#include <math.h>

int len(char input[], int scanf_output)
{ // This function calculates the number of character in a given string.

    if (scanf_output == 0)
    { // If user presses "Enter" without typing anything:
        return 0;
        // Since there is nothing to count, function returns 0.
    }

    int index = 0;
    int count = 0;

    while (input[index] != '\0')
    {
        index++;
        count++;
        // The number of characters is counted.
    }

    return count;
    // The number of characters is returned.
}

int number_of_words(char input[])
{ // This function counts the number of words in a given string.

    int index = 0;
    int count = 1;

    while (input[index] != '\0')
    { // '\0' represents the end of string in C programming language.
        if (input[index] == ' ')
        {
            count++;
            // The number of words is counted.
        }
        index++;
    }

    return count;
    // The number of words is returned.
}

int check_string(char input[], int scanf_output)
{ // This function checks a given string whether it is valid or not to be processed.

    int index = 0;

    if (scanf_output == 0)
    { // If user presses "Enter" without typing anything:
        return 0;
        // Invalid string...
    }

    while (input[index] != '\0')
    { // '\0' represents the end of string in C programming language.

        if (input[index] == ' ')
        {
            if (input[index + 1] == ' ' || input[index - 1] == ' ' || // If a string contains whitespaces next to each other or
                input[index + 1] == '\0' || input[index - 1] == '\0') // a string starts or ends with a whitespace:
            {
                return 0;
                // Invalid string...
            }
        }
        index++;
    }
    return 1;
    // Valid string...
}

void printf_reverse(char input[], int scanf_output)
{ // This function reverses the order of words in a given string in-place and displays it.
    //To accomplish this first we need to reverse the whole string,
    // and then reverse each words in a string.

    int last_index = len(input, scanf_output) - 1;

    char output[250];

    int output_index = 0;

    while (last_index >= 0)
    {
        output[output_index] = input[last_index];
        //The given string is reversed.

        last_index--;
        output_index++;
    }

    int i, j, k, length;

    // reverse words in the given string
    length = len(input, scanf_output);

    output[length] = '\0';
    // The last index of output is set as '\0' to indicate end of string.

    char tmp;
    // temporary character...

    // Reference to following codeblocks: https://youtu.be/DlygTBMhonA
    for (i = 0, j = 0; j < length; j++)
    {
        if (output[j] == ' ' || j == length - 1)
        { // If output[j] is a whitespace or
            // j is pointing at the 2nd last character

            if (j < length - 1)
            {
                k = j - 1;
            }
            else
            {
                k = j;
            }

            // reverse characters of the word
            while (i < k)
            {
                tmp = output[i];
                output[i] = output[k];
                output[k] = tmp;
                i++;
                k--;
            }

            //set i to point at j+1
            i = j + 1;
        }
    }

    //output
    printf("%s", output);
}

void printf_uppercase(char input[], int scanf_output)
{ // This function converts first character of each word to uppercase and displays it.
    
    char output[250];

    for (int index = 0; index < len(input, scanf_output); index++)
    {
        if ((input[index - 1] == ' ' || index == 0) && (97 <= input[index] && input[index] <= 122))
        { // If the character before is a whitespace or the index number is 0 and
            // the character is between 97 and 122 meaning that it is an alphabet character.
            output[index] = input[index] - 32;
            // The character is uppered.
        }
        else
        {
            output[index] = input[index];
        }
    }

    printf("%s", output);
}

int main()
{
    printf("*Word Processor by Mehmet Akif KOZ 192010010023\n\n");

    printf("*This program performs the following operations:\n");
    printf(" It counts the number of characters in the string.\n");
    printf(" It counts the number of words in the string. The delimeter is a white space, \" \".\n");
    printf(" It reverses the order of words in the string in-place and display.\n");
    printf(" Converts first character of each word to uppercase. (Not in-place)\n\n");

    printf("*Instructions: Type a string and press \"Enter\" on your keyboard.\n\n");

    char input[250];
    printf("Please enter a sting: ");
    int scanf_output = scanf("%[^\n]", input);

    printf("Number of characters: ");
    printf("%d\n", len(input, scanf_output));

    printf("     Number of words: ");
    if (check_string(input, scanf_output) == 0)
    {
        printf("Error\n");
    }
    else
    {
        printf("%d\n", number_of_words(input));
    }

    printf("            Reversed: ");
    printf_reverse(input, scanf_output);
    printf("\n");

    printf("         Capitalized: ");
    printf_uppercase(input, scanf_output);
    printf("\n");
    return 0;
}
