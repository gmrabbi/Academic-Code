#include <stdio.h>

int main()
{
    char c;
    char name[80];
    int num = 0;
    do
    {
        scanf("%c", &c);
        name[num++] = c;
    }while(c!='\n');

    name[num--] = '\0';
    for(int i=0; i<num; i++)
        printf("%c", name[i]);
    printf("\nDone");

    return 0;
}
