#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0, sing = 0;
    char st1[20];
    gets(st1);
    char st2[strlen(st1)] ;
    for(i = 0 ; st1[i] != '\0'; i++ )
    {
        st2[strlen(st1)-i-1] = st1[i];
    }
    for(int j = 0; st1[j] != '\0'; j++)
    {
        if(st1[j] != st2[j])
        {
            sing = 1;
            break;
        }
    }
   // printf("%s \n%s \n", st1, st2);
    if(sing)
            printf("Not Palindrom\n");
    else
            printf("Palindrom\n");

    return 0;
}
