#include <stdio.h>
#include <math.h>

int main()
{
    // input should be a cube number
    int input_number = 27;

    float g = 1;
    float threshold = 0.000001;

    while(fabs(g*g*g - input_number) > threshold)
    {
        g = (g + input_number/(g*g))/2;
    }

    printf("The cube root of %d is %f",input_number,g);

    return 0;
}
