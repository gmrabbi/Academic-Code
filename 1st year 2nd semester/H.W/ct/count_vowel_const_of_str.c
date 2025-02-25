#include <stdio.h>
#include <string.h>

int main()
{
    char s[32];
    int vowel = 0 , con= 0;
    gets(s);
    for(int i =0 ; s[i] != '\0'; i++)
    {
        if((s[i]>= 97 || s[i] <= 122 ) && (s[i]>= 65 || s[i] <= 90)){
            if(s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I' || s[i] == 'i' || s[i] == 'O' || s[i] == 'o' || s[i] == 'U' || s[i] == 'u' )
                vowel += 1;
            else
                con += 1;

          }
    }
    printf("Vowel = %d \nConsonent = %d", vowel, con);
    return 0;
}
