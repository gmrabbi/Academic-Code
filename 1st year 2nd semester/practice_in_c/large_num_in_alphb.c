#include <stdio.h>

int main()
{
    int num, arr[20],i=0 ;
    printf("Enter a number : ");
    scanf("%d", &num);

    int temp = num;
    while(temp)
    {
        arr[i++] = temp%10;
        temp /= 10;
    }
    int max = arr[0];
    for(int j=0; j<i; j++)
    {
        if(max<arr[j])
            max = arr[j];
    }
    printf("The larges number is ");
    switch(max)
    {
        //case 0: printf("Zero "); break;
        case 1: printf("One "); break;
        case 2: printf("Two "); break;
        case 3: printf("Three "); break;
        case 4: printf("Four "); break;
        case 5: printf("Five "); break;
        case 6: printf("Six "); break;
        case 7: printf("Seven "); break;
        case 8: printf("Eight "); break;
        case 9: printf("Nine "); break;

        default: printf("Zero ");
    }

    return 0;
}
