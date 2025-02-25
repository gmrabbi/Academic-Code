#include <stdio.h>


void rm_vowel(char* c)
{
    int n = 0;
    char ch[];
    for(int i = 0 ; c[i] != '\0'; i++)
    {
        if(c[i]=='A' ||c[i]=='a'||c[i]=='E'||c[i]=='e' ||c[i]=='I' ||c[i]=='i' ||c[i]=='O'||c[i]=='o'||c[i]=='u'||c[i]=='U' )
            continue;
        else
            ch[n] = c[i];
    }
    &c = *ch;
}

int main()
{
    char c = "well done";
    rm_vowel(c);
    printf("%s", c);
    return 0;
}
