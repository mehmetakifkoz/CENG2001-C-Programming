#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    printf("*Square Hole by Mehmet Akif KOZ 192010010023\n");
    printf("*This program prints a square with a square hole in it.\n");
    printf("*Instructions: Type the values and press \"Enter\" on your keyboard.\n\t       Outer width is the width of the square.\n\t       Inner width is the width of the hole\n\t       Margin is the spacing from left, right, top and bottom.\n\n");

    int outerWidth;
    int innerWidth;
    int margin;
    // The variables outerWidth, innerWidth and margin are defined to be of type integer.

    printf("Outer width = ");
    scanf("%d", &outerWidth);
    // The variable outerWidth is obtained from user input.

    if (outerWidth % 2 == 0) // If the variable outerWidth is even:
    {
        printf("Warning: Invalid value for outer width. It must be an odd number.\n");

        printf("\nPress any key to continue.");
        getch();
        // Some devices close the program immediately after running it. getch(); is used to prevent this.

        exit(1);
        // Error code 1
        // The program had an error due to invalid entry for the variable outerWidth.
    }

    printf("Inner width = ");
    scanf("%d", &innerWidth);
    // The variable innerWidth is obtained from user input.

    if (innerWidth % 2 == 0) // If the variable innerWidth is even:
    {
        printf("Warning: Invalid value for inner width. It must be an odd number.\n");

        printf("\nPress any key to continue.");
        getch();
        // Some devices close the program immediately after running it. getch(); is used to prevent this.

        exit(2);
        // Error code 2
        // The program had an error due to invalid entry for the variable innerWidth.
    }

    printf("Margin = ");
    scanf("%d", &margin);
    // The variable margin is obtained from user input.

    int thickness = (outerWidth - innerWidth) / 2;
    // The thickness of the square is calculated and assigned to variable thickness.

    int count = margin + outerWidth + margin;
    // The count of repetition is calculated and assigned to variable count.

    // This program is based on the carving idea.
    for (int i = 1; i <= count; i++) // i stands for rows.
    {
        for (int j = 1; j <= count; j++) // j stands for columns.
        {
            // Imagine having a square wood which is count by count centimeters.

            if (i <= margin ||        // If the row number is less than or equal to the margin value or
                j <= margin ||        // the column number is less than or equal to the margin value or
                i > count - margin || // the row number is less than the value (count - margin) or
                j > count - margin)   // the column number is less than the value (count - margin):
            {
                printf("  ");
                // The margin is carved.
            }
            else if (margin + thickness < i && i <= margin + thickness + innerWidth && // If the rows are between the range from (margin + thickness) to [margin + thickness + innerWidth] and
                     margin + thickness < j && j <= margin + thickness + innerWidth)   // the columns are between the range from (margin + thickness) to [margin + thickness + innerWidth]:
            {
                printf("  ");
                // A square hole is carved at the center of the square.
            }
            else
            {
                printf("* ");
                // The wood is not carved.
            }
        }
        printf("\n");
        // New line is added after completing one.
    }

    printf("Press any key to continue.");
    getch();
    // Some devices close the program immediately after running it. getch(); is used to prevent this.

    return 0;
    // The program is executed successfully.
}
