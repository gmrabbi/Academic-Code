#include <stdio.h>

void Dec_bin(int n)
{
    if(n==0)
        return;
    Dec_bin(n/2);
    printf("%d", n%2);
}

int main()
{
    int n = 8;
    Dec_bin(n);
    return 0;
}
