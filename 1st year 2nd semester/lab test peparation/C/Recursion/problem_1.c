#include <stdio.h>

void Natural_num(int n)
{
    if(n<=50)
    {
        printf("%d ", n);
        return Natural_num(n+1);
    }

}

int main()
{
    Natural_num(1);
    return 0;
}
