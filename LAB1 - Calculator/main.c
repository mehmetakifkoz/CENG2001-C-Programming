#include <stdio.h>
#include <math.h>

int main()
{
    printf("*Calculator by Mehmet Akif Koz 192010010023\n");
    printf("*This program displays the sum, difference, average, square of the sum, cube of the difference and square of the average of two numbers.\n");
    printf("*Instructions: Type the first whole number and press \"Enter\" on your keyboard. After that do the same with second number.\n");

    int number1, number2;
    // The variables are defined number1 and number2 to be of type int.
    printf("\nEnter two numbers: \n");
    scanf("%d", &number1);
    scanf("%d", &number2);
    // The variables are obtained them from keyboard.

    int sum;
    // The variable sum is defined to be of type int.
    sum = number1 + number2;
    // The sum of variables number1 and number2 is calculated and it is assigned to variable sum.

    int difference;
    // The variable difference is defined to be of type int.
    difference = number1 - number2;
    // The difference of variables number1 and number2 is calculated and it is assigned to variable difference.

    float average;
    // The variable average is defined to be of type float.
    average = (number1 + number2) / 2;
    // The average of variables number1 and number2 and assign it to variable average.

    printf("%d + %d = %d\n", number1, number2, sum);
    // The sum is displayed.
    printf("%d - %d = %d\n", number1, number2, difference);
    // The difference is displayed.
    printf("Average of %d and %d is %.2f\n", number1, number2, average);
    // The average is displayed.
    printf("Square of the sum is %d\n", sum * sum);
    // The square of the sum is displayed.
    printf("Cube of the difference is %d\n", difference * difference * difference);
    // The cube of the difference is displayed.
    printf("Square of the average of %d and %d is %.2f\n", number1, number2, average * average);
    // Square of the average of two numbers is displayed.
  return 0;
}
