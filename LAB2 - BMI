#include <stdio.h>
#include <math.h>

int main()
{
    float weightInKilograms, heightInMeters, BMI;

    printf("Enter your weight in kilograms: ");
    scanf("%f", &weightInKilograms);
    printf("Enter your height in meters: ");
    scanf("%f", &heightInMeters);

    BMI = weightInKilograms / (heightInMeters * heightInMeters);

    if (BMI < 18.5)
    {
        printf("Your body mass index is %f and you are underweight.\n",BMI);
    }
    else if ((BMI >= 18.5) && (BMI < 25))
    {
        printf("Your body mass index is %f and you are normal.\n",BMI);
    }
    else if ((BMI >= 25) && (BMI < 30))
    {
        printf("Your body mass index is %f and you are overweight.\n",BMI);
    }
    else if (BMI >= 30)
    {
        printf("Your body mass index is %f and you are obese.\n",BMI);
    }

    return 0;
}
