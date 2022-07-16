#include <stdio.h>
#include <string.h>

int checkIdentityNumber(char *id)
{
    int len = strlen(id);
    int sum = 0;

    for (int i = 0; i < len - 1; i++)
        sum += id[i] - 48;

    if (len != 11)
        return 0; // Invalid
    else if (id[0] == '0')
        return 0; // Invalid
    else if (sum % 10 != id[10] - 48)
        return 0; // Invalid
    else
        return 1; // Valid
}

int main()
{
    char identityNumber[] = "10000000146";
    printf("%d\n", checkIdentityNumber(identityNumber));
}
