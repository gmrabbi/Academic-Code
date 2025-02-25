#include <stdio.h>

struct Student
{
    int number;
    char name[20];
    int marks;
};

int main()
{
    struct Student s1 = {1 , "Rahim" , 201};
    struct Student s2 = {2 , "Karim" , 220};
    struct Student s3;

    s3 = s2;
    int x;
    x = ((s2.number == s3.number)&&(s2.marks == s3.marks))?1:0;
    if(x)
    {
        printf("Student 1 and Student 2 are same.\n");
        printf("%d %s %d\n", s2.number , s2.name , s2.marks);
    }
    else
        printf("student 1 and student 2 are not same.\n");

    return 0;

}
