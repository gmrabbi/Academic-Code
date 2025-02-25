#include <stdio.h>
#include <string.h>

int main()
{
    int len , i;
    char s[16];
    gets(s);
    len = strlen(s);
    //printf("%d\n", len);
    for(int k = 0 ; s[k] != '\0'; k++)
    {
        if(s[k] != '0' && s[k] != '1')
        {
            printf("Wrong input");
            getch();
            exit(0);
        }
    }

    for(i = len -1 ; s[i] != '1'; i--);
    for(int j = i-1; j>=0; j--)
    {
        if(s[j] == '0')
            s[j] = '1';
        else
            s[j] = '0';
    }
    printf("%s", s);
    return 0;
}
