#include <stdio.h>

struct Complex
{
    int real;
    float img;
};

struct Complex add(struct Complex c1 , struct Complex c2)
{
    struct Complex s3;
    s3.img = c1.img + c2.img;
    s3.real = c1.real + c2.real;
    return s3;
};

int main()
{
    struct Complex s1 = {3, 3.23};
    struct Complex s2 = {4, 8.232};
    struct Complex s3;

    s3 = add(s1 , s2);
    printf("%d %f ", s3.real , s3.img);
    return 0;
}
