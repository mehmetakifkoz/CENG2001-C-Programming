#include <stdio.h>

int find_median(int a, int b, int c)
{
    if (a < b && b < c)
    {
        return b;
    }
    else if (a < c && c < b)
    {
        return c;
    }

    else if (b < a && a < c)
    {
        return a;
    }

    else if (b < c && c < a)
    {
        return c;
    }

    else if (c < a && a < b)
    {
        return a;
    }

    else if (c < b && b < a)
    {
        return b;
    }

    else if (a == b < c)
    {
        return b;
    }

    else if (a == c < b)
    {
        return c;
    }

    else if (b == c < a)
    {
        return c;
    }

    else if (a == b == c)
    {
        return a;
    }
}

int main()
{
    int a, b, c;
    printf("Enter three numbers: \n");
    scanf("%d %d %d", &a, &b, &c);

    int median = find_median(a, b, c);

    printf("The median of %d, %d and %d is %d.\n", a, b, c, median);
}
