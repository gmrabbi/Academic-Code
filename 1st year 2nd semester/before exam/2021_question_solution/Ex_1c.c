#include <stdio.h>

int main()
{
    int num, max=0, cnt=0, temp, rev=0;
    printf("Enter a number : ");
    scanf("%d", &num);
    rev = num;

    while (rev)
    {
        int n = rev%10;
        rev /= 10;
        if (n>max)
            max = n;
    }

    switch(max)
    {
        case 1 : printf("One "); break;
        case 2 : printf("Two "); break;
        case 3 : printf("Three "); break;
        case 4 : printf("Four "); break;
        case 5 : printf("Five "); break;
        case 6 : printf("Six "); break;
        case 7 : printf("Seven "); break;
        case 8 : printf("Eight "); break;
        case 9 : printf("Nine "); break;
        default: printf("Zero ");
    }
    printf(" is the largest digit.");
    return 0;
}
