#include <stdio.h>

struct personal
{
    char name[20];
    int date;
    char month[10];
    int year;
    int salary;
} person;

int main()
{
    //struct personal person;

    printf("Input information ...\n");
    printf("name , date , month , year , salary\n");

    scanf("%s %d %s %d %d", person.name, &person.date, person.month, &person.year, &person.salary);
    printf("\n%s %d %s %d %d\n", person.name, person.date, person.month , person.year , person.salary);
    printf("Done.");


}
