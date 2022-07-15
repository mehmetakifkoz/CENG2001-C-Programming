#include <stdio.h>
#include <math.h>
#include <string.h>

long long int encode(int number)
{ // When encoding, the function takes a number, and for each digit, it constructs a new number by for each digit, taking the modulus of that digit by 3 and repeating the value of the digit as many as the remainder(in addition to the digit itself).
    // The type of function "encode" returns is defined to be long long integar.
    // The type of variable "number" is defined to be type of integar.
    // Variable "number" is taken as an input.

    long long int encoded_number = 0;
    // The function "encode" returns variable "encoded_number", therefore it is defined to be type of long long integar type.

    long long int encoded_digits = 1;
    // The number of digits which the "encoded_number" has is defined to be type of long long integar and assigned to variable "encoded_digits".
    // "encoded_digits" increases while the function is progressing.

    int n = number;
    // The variable "number" is assigned to variable "n" as a dummy, because the actual "number" could be needed later on.

    while (n > 0) // While "n" is greater than 0:
    {
        int digit_number = n % 10;
        // First digit number is assigned to variable "digit_number".

        int count = digit_number % 3 + 1;
        // The count of repetition is calculated and assigned to variable count.

        for (int i = 0; i < count; i++) // Initial value of i is defined as 0.
        {                               // This loop runs as long as i is less than count.
                                        // After each loop the initial value is increased by 1 (i++).

            encoded_number += digit_number * encoded_digits;
            // "encoded_number" is assembled.

            encoded_digits *= 10;
            // "encoded_digits" increases in each iteration.
        }

        n = n / 10;
        // First digit is deleted.
    }

    return encoded_number;
    // Variable "encoded_number" is returned as an output.
}

long long int split(long long int encoded_number)
{ // This function splits a given number by repetition.

    long long int e = encoded_number;
    // dumy

    long long int digit = 1;
    //digit of splitted_number

    long long int splitted_number = 0;

    while (e != 0) // while e is not 0.
    {
        int first_digit = e % 10;
        // first digit of encoded number

        int second_digit = (e / 10) % 10;
        // second digit of encoded number

        if (first_digit == second_digit)
        { //if first digit is equal to second digit:

            splitted_number += first_digit * digit;
            // splitted number is assembled.

            digit *= 10;
        }
        else if (digit != 1)
        { // if digit is not 1:

            splitted_number += first_digit * digit;
            // splitted number is assembled.

            break;
            // While loop is ended.
        }
        else
        { // This happens if the number don't repeat:
            return first_digit;
            // First digit is returned from the function.
        }

        e = e / 10;
        // first digit is deleted.
    }

    return splitted_number;
}

int check_encoded_number(long long int encoded_number)
{ // This function checks given encoded number.
    // If the encoded number is valid returns 1, if not returns 0.

    long long int e = encoded_number;
    // dummy

    while (e != 0)
    {

        long long int split_number = split(e);
        // encoded number is splitted by repetition and assigned to "split_number".

        int digit_number = split_number % 10;
        // first digit number of splitted number is calculated.

        long long int s = split_number;
        // dummy

        long long int digits = 1;
        // The number of digits of splitted number is defined as digits.

        int count = 0;
        // count for repetition of numbers is calculated.

        do // do while loop is used to not miss "0".
        {
            count++;
            // count is increased by 1.

            digits *= 10;
            // skipped to the next digit.

            s = s / 10;
            // first digit of splitted number is deleted.

        } while (s != 0);

        if (!(                                               // There are 3 cases possible for a encoded number to be valid:
                (digit_number % 3 == 0 && count % 1 == 0) || // 1. A number's modulus of 3 is 0 and it repeats 1 times.
                (digit_number % 3 == 1 && count % 2 == 0) || // 2. A number's modulus of 3 is 1 and it repeats 2 times.
                (digit_number % 3 == 2 && count % 3 == 0)))  // 3. A number's modulus of 3 is 2 and it repeats 3 times.
        {
            return 0;
            // The function returns false.
        }

        e = e / digits;
        // Total number of digits which are same are deleted.
        // If not same just 1 digit is deleted.
    }
    return 1;
    // The function returns True.
}

int decode(long long int encoded_number)
{ // When decoding, the function takes a number and correlate a new number by applying the inverse operation of encoding.
    // The type of function "decode" returns is defined to be "int".
    // The type of variable "encoded_number" is defined to be type of "long long int".
    // Variable "encoded_number" is taken as an input.

    int number = 0;
    // The function "decode" returns variable "number", therefore it is defined to be type of "int" type.

    long long int digits = 1;
    // The number of digits which the "number" has is defined to be type of "long long int" and assigned to variable "encoded_digits".
    // "encoded_digits" increases while the function is progressing.

    long long int e = encoded_number;
    // The variable "encoded_number" is assigned to variable "e" as a dummy, because the actual "encoded_number" could be needed later on.

    int count = 1;
    // The count of repetition of a digit number is defined as "count".
    // The initial value of "count" is 1. It increases while the function is progressing.

    int error1 = 0;
    // This variable checks if there is any error or not.

    while (e != 0) // While e is not 0:
    {
        long long int digit_number = e % 10;
        // First digit number is assigned to variable "digit_number".

        if (digit_number % 3 == 0 && count == 1)
        { // if the remainder of "digit_number" divided by 3 is 0 or count is 1:

            number += digit_number * digits;
            // "number" is assembled.

            digits *= 10;
            // Skipped to the next digit.
        }
        else if (digit_number % 3 == 1 && count <= 2)
        { // else if the remainder of "digit_number" divided by 3 is 1 or count is less than or equal to 2:

            if (count == 2) // If count is 2:
            {
                number += digit_number * digits;
                // "number" is assembled.

                digits *= 10;
                // Skipped to the next digit.

                count = 1;
                // "count" is resetted
            }
            else
            {
                count++;
                // "count" is increased by 1.
            }
        }
        else if (digit_number % 3 == 2 && count <= 3)
        { // else if the remainder of "digit_number" divided by 3 is 2 or count is less than or equal to 3:
            if (count == 3)
            {
                number += digit_number * digits;
                // "number" is assembled.

                digits *= 10;
                // Skipped to the next digit.

                count = 1;
                // "count" is resetted
            }
            else
            {
                count++;
                // "count" is increased by 1.
            }
        }

        e = e / 10;
        // First digit is deleted.
    }

    return number;
    // Variable "number" is returned as an output.
}

int main()
{
    printf("*Enigma by Mehmet Akif KOZ 192010010023\n");
    printf("*This program encodes/decodes a given number.\n");
    printf("*Instructions: Type your command to get resutls.\n");

    long long int number;
    char command;

    while (1) // While True:
    {

        printf("\nPress 'E' or 'e' to encode, 'D' or 'd' to decode, 'Q' or 'q' to exit: ");
        scanf(" %s", &command);

        if (command == 81 || command == 113) // if command is "Q" or "q":
        {
            break;
        }
        else if (command == 69 || command == 101) // else if command is "E" or "e":
        {
            printf("Please enter a number: ");
            scanf("%lld", &number);
            // "number" is obtained from user input.

            if (number > 99999) // If number has more than 5 digits:
            {
                printf("Warning: The input may have 5 digits max.\n");
            }
            else
            {
                long long int encoded_number = encode(number);
                // The number is encoded.

                printf("Encoded Number = %lld\n", encoded_number);
                // The encoded number is displayed.
            }
        }
        else if (command == 68 || command == 100) // else if command is "D" or "d":
        {
            printf("Please enter a number: ");
            scanf("%lld", &number);
            // "number" is obtained from user input.

            if (check_encoded_number(number) == 0) // If the given encoded number is invalid:
            {
                printf("Warning: Invalid Encoded Number.\n");
            }
            else if (check_encoded_number(number) == 1) // Else if the given encoded number is valid:
            {
                int decoded_number = decode(number);
                // The encoded number is decoded.

                printf("Decoded Number = %d\n", decoded_number);
                // The decoded number is displayed.
            }
        }
        else
        {
            printf("Warning: Invalid key.\n");
        }
    }

    return 0;
    // The program is successfully executed.
}
