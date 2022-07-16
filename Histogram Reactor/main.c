#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double zScore(double x, double mean, double standard_deviation)
{
    return (x - mean) / standard_deviation;
}

double findMinNumber(double *numbers, int size)
{
    double minNumber = numbers[0];

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] < minNumber)
        {
            minNumber = numbers[i];
        }
    }
    return minNumber;
}

double findMaxNumber(double *numbers, int size)
{
    double maxNumber = numbers[0];

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] > maxNumber)
        {
            maxNumber = numbers[i];
        }
    }
    return maxNumber;
}

struct class
{
    double lower_class_limit;
    double upper_class_limit;
    double class_mid_point;
    int freq;
    double rel_freq;
};

void quartile(double *numbers, int size, double *q1, double *q2, double *q3)
{
    if (size % 4 == 0)
    {
        *q1 = numbers[size / 4 - 1];
        *q2 = (numbers[(size / 2) - 1] + numbers[size / 2]) / 2;
        *q3 = numbers[size - size / 4];
    }
    else if (size % 4 == 1)
    {
        *q1 = (numbers[size / 4 - 1] + numbers[size / 4]) / 2;
        *q2 = numbers[size / 2];
        *q3 = (numbers[size - size / 4] + numbers[size - size / 4 - 1]) / 2;
    }
    else if (size % 4 == 2)
    {
        *q1 = (numbers[size / 4 - 1] + numbers[size / 4]) / 2;
        *q2 = (numbers[(size / 2) - 1] + numbers[size / 2]) / 2;
        *q3 = (numbers[size - size / 4] + numbers[size - size / 4 - 1]) / 2;
    }
    else if (size % 4 == 3)
    {
        *q1 = numbers[size / 4];
        *q2 = numbers[size / 2];
        *q3 = numbers[size - size / 4 - 1];
    }
}

int outlier_test(double q1_15iqr, double var, double q3_15iqr)
{
    if (q1_15iqr <= var && var <= q3_15iqr)
    {
        return 0; // NOT AN OUTLIER
    }
    else
    {
        return 1; // OUTLIER
    }
}

void print_outlier_test(double q1_15iqr, double var, double q3_15iqr)
{
    if (outlier_test(q1_15iqr, var, q3_15iqr) == 1) // IF THE VARIABLE IS AN OUTLIER
    {
        printf("%.2lf IS OUTSIDE OF THE RANGE [%.2lf ,%.2lf] THEREFORE IT IS AN OUTLIER.\n", var, q1_15iqr, q3_15iqr);
    }
    else
    {
        printf("%.2lf IS INSIDE OF THE RANGE [%.2lf ,%.2lf] THEREFORE IT IS NOT AN OUTLIER.\n", var, q1_15iqr, q3_15iqr);
    }
}

int main()
{
    printf("*Histogram_Reactor by Mehmet Akif KOZ 192010010023\n");

    printf("*This program:\n");
    printf("\ta. Calculates maximum and minimum values of a data set. Calculates the range.\n");
    printf("\tb. Constructs a relative frequency histogram for a data set.\n");
    printf("\tc. Finds the mean and the standard deviation.\n");
    printf("\td. Arranges the data from smallest to largest.\n\t   Finds the z-scores for the largest and smallest observations. Determines whether they are outliers or not and proves it.\n");
    printf("\te. Calculates the median.\n");
    printf("\tf. Finds the lower and upper quartiles.\n");

    printf("*Instructions: Put the data values in the \"numbers\" array before running the program. Then enter the class width and starting value.\n");

    double numbers[] = {
        23.1,
        21.3,
        23.6,
        23.7,
        20.2,
        24.4,
        25.3,
        27.0,
        24.7,
        22.7,
        26.2,
        23.2,
        25.9,
        24.7,
        24.4,
        24.2,
        24.9,
        22.2,
        22.9,
        24.6};

    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("\n");
    
    printf("a.\n");
    double min = findMinNumber(numbers, size);
    printf("MIN = %.2lf\n", min);

    double max = findMaxNumber(numbers, size);
    printf("MAX = %.2lf\n", max);

    double range = max - min;
    printf("RANGE = %.2lf\n", range);
    printf("\n");

    printf("\n");
    
    printf("b.\n");
    double class_width;
    printf("CLASS WIDTH = ");
    scanf("%lf", &class_width);

    double starting;
    printf("STARTING = ");
    scanf("%lf", &starting);

    int number_of_classes = 0;
    for (double i = starting; i < max; i += class_width)
    {
        number_of_classes++;
    }
    printf("NUMBER OF CLASSES = %d\n", number_of_classes);

    struct class *myClass = (struct class *)calloc(number_of_classes, sizeof(struct class));

    double lower = starting;

    for (int i = 0; i < number_of_classes; i++)
    {
        myClass[i].lower_class_limit = lower;
        myClass[i].upper_class_limit = lower + class_width;
        lower += class_width;
        myClass[i].class_mid_point = ((float)myClass[i].upper_class_limit + myClass[i].lower_class_limit) / 2;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < number_of_classes; j++)
        {
            if (myClass[j].lower_class_limit <= numbers[i] && numbers[i] < myClass[j].upper_class_limit)
            {
                myClass[j].freq++;
            }
        }
    }

    for (int i = 0; i < number_of_classes; i++)
    {
        myClass[i].rel_freq = (float)myClass[i].freq / size;
    }

    printf("\nCLASSES\t\tFREQ.\tREL. FREQ.\tCLASS MIDPOINT\t\tREL. FREQ. HISTOGRAM\n");

    for (int i = 0; i < number_of_classes; i++)
    {
        printf("%.2lf - %.2lf\t%d\t%.2lf\t\t%.2lf\t\t\t", myClass[i].lower_class_limit, myClass[i].upper_class_limit, myClass[i].freq, myClass[i].rel_freq, myClass[i].class_mid_point);

        for (int j = 0; j < (myClass[i].rel_freq * 100); j++)
        {
            printf("-");
        }

        printf("\n");
    }

    printf("\n");
    
    printf("c.\n");
    double mean;
    for (int i = 0; i < size; i++)
    {
        mean += numbers[i] / size;
    }
    printf("MEAN = %.2lf\n", mean);

    double standard_deviation;
    for (int i = 0; i < size; i++)
    {
        standard_deviation += pow(mean - numbers[i], 2);
    }
    standard_deviation = standard_deviation / (size - 1);
    standard_deviation = sqrt(standard_deviation);
    printf("STANDARD DEVIATION = %lf\n", standard_deviation);

    printf("\n");
    
    printf("d.\n");
    double temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (numbers[i] < numbers[j])
            {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.2lf\t", numbers[i]);
    }
    printf("\n");

    double q1;
    double q2;
    double q3;
    quartile(numbers, size, &q1, &q2, &q3);
    double iqr = q3 - q1;
    double _15iqr = 1.5 * iqr;
    double q1_15iqr = q1 - _15iqr;
    double q3_15iqr = q3 + _15iqr;
    double largest_z_score = zScore(max, mean, standard_deviation);
    double smallest_z_score = zScore(min, mean, standard_deviation);

    printf("\n");
    printf("QUARTILE1 (Q1) = %.2lf\n", q1);
    printf("QUARTILE2 (Q2) = %.2lf\n", q2);
    printf("QUARTILE3 (Q3) = %.2lf\n", q3);
    printf("\n");

    printf("INTERQUARTILE RANGE(IQR): Q3-Q1\n");
    printf("\t\t\t  MIDDLE 50%% OF DATA\n");
    printf("\n");

    printf("OUTLIER\n");
    printf("1. FIND IQR ------------> %.2lf - %.2lf = %.2lf\n", q3, q1, iqr);
    printf("2. (1.5) * (IQR) -------> (1.5) * (%.2lf) = %.2lf\n", iqr, _15iqr);
    printf("3. Q1 - (1.5) * (IQR) --> %.2lf - (1.5) * (%.2lf) = %.2lf\n", q1, iqr, q1_15iqr);
    printf("4. Q3 + (1.5) * (IQR) --> %.2lf + (1.5) * (%.2lf) = %.2lf\n", q3, iqr, q3_15iqr);
    printf("5. IF A VARIABLE IS OUTSIDE OF THE RANGE [Q1 - (1.5) * (IQR) , Q3 + (1.5) * (IQR)] IT IS AN OUTLIER.\n");

    printf("\n");
    printf("Z-SCORE FOR THE LARGEST OBSERVATION = %lf\n", largest_z_score);
    print_outlier_test(q1_15iqr, max, q3_15iqr);
    printf("\n");
    printf("Z-SCORE FOR THE SMALLEST OBSERVATION = %lf\n", smallest_z_score);
    print_outlier_test(q1_15iqr, min, q3_15iqr);

    printf("\n");
    
    printf("e.\n");
    printf("MEDIAN = %.2lf\n", q2);

    printf("\n");
    
    printf("f.\n");
    printf("LOWER QUARTILE = %.2lf\n", q1);
    printf("UPPER QUARTILE = %.2lf\n", q3);

    free(myClass);

    printf("\n");
    return 0;
}
