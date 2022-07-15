#include <stdio.h>
#include <math.h>

int main()
{
    printf("*Calculator by Mehmet Akif KOZ 192010010023\n");
    printf("*This program calculates the sum, difference, product and division of two numbers.\n");
    printf("*Instructions: Type a mathematical expression and press \"Enter\" on your keyboard to display the result.\n\n");

    float number1, number2;
    // The variables number1 and number2 are defined to be of type float.

    char operation;
    // The variable operation is defined to be of type char.

    scanf("%f %c %f", &number1, &operation, &number2);
    // The variables are obtained from user input.

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
