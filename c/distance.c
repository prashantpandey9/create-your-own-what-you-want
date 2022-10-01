#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    float x, y;
};


double getDistance(struct Point a, struct Point b)
{
    double distance;
    distance = sqrt((a.x - b.x) * (a.x - b.x) + (a.y-b.y) *(a.y-b.y));
    return distance;
}
struct Point midpoint(struct Point a, struct Point b)
{
    struct Point middle;
    middle.x = (a.x + b.x) / 2;
    middle.y = (a.y + b.y) / 2;
    return middle;
}
double areaoftriangle(struct Point a, struct Point b,struct Point c)
{
    double area;
    area=0.5 * (a.x * (b.y-c.y) + c.x * (c.y-a.y) + c.x * (a.y-b.y));
    return area;
}

int main()
{
    struct Point a, b, c;
    printf("Enter coordinate of point a: ");
    scanf("%f %f", &a.x, &a.y);
    printf("Enter coordinate of point b: ");
    scanf("%f %f", &b.x, &b.y);
    printf("Enter coordinate of point c: ");
    scanf("%f %f", &c.x, &c.y);
    printf("Distance between a and b: %lf\n", getDistance(a, b));
    struct Point m = midpoint(a, b);
    printf("The midpoint between two points a and b: (%f, %f)\n", m.x,m.y);
    printf("Area of the triangle formed by three coordinates a,b&c: %lf \n", areaoftriangle(a,b,c));
    return 0;
}

