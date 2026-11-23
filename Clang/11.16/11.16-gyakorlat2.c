#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Circle
{
  double x, y;
  double r;
};
typedef struct Circle Circle;

double area(Circle c) { return c.r * c.r * 3.14; }
double areaSum(Circle circles[], int size)
{
  uint sum = 0;
  for (int i = 0; i < size; ++i)
    sum += area(circles[i]);

  return sum;
}

int main()
{
  Circle circles[3];

  for (int i = 0; i < 3; ++i)
    scanf("%lf %lf %lf", &circles[i].x, &circles[i].y, &circles[i].r);

  double sum = areaSum(circles, 3);
  printf("%lf a terulet osszege\n", sum);
  return 0;
}
