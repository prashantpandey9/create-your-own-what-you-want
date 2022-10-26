

// Implementing  multi structure

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct college
{
    char coll_name[100];
    char city[100];
    int pin;
};

struct student
{

    char name[100];
    char age[100];
    int roll;

    struct college c;
} s;

void display1(struct college c);
void display(struct student s);

int main()
{

   //struct college c;
    struct student s;

    printf(" \n ************  College details **************");

    printf("\nEnter College name :- ");
    scanf("%                  s", &s.c.coll_name);
    fflush(stdin);

    printf("\nEnter College city :- ");
    scanf("%s", &s.c.city);
    fflush(stdin);

    printf("\nEnter College Pin Code :- ");
    scanf("%d", &s.c.pin);
    fflush(stdin);

    printf(" \n ************  Student details **************");

    printf("\nEnter Student name :- ");
    scanf("%s", &s.name);
    fflush(stdin);

    printf("\nEnter %s's age :- ", s.name);
    scanf("%s", &s.age);
    fflush(stdin);

    printf("\nEnter %s 's Roll no :- ",s.name);
    scanf("%d", s.roll);
    fflush(stdin);
    printf("\n");

    display1(s.c);
    display(s);

    return 0;
    
}

void display1(struct college c)
{

    printf("\n****************** Display COLLEGE Details ************************\n");

    printf(" College name is :-  %s", s.c.coll_name);
    printf(" \nCollege city is :- %s", s.c.city);
    printf(" \nCollege Pin code is :- %d", s.c.pin);
}

void display(struct student s)
{

    printf("\n****************** Display STUDENT Details ************************\n");

    printf(" College name is :- %s", s.name);
    printf(" \nCollege city is :- %s", s.age);
    printf(" \nCollege Pin code is :- %d", s.roll);
}