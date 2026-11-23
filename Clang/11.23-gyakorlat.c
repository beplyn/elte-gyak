#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
  double area;
  double x_coord;
  double y_cord;
} Circle;

Circle *legnagyobb(Circle arr[], int length)
{
  if (length <= 0)
    return NULL;

  Circle *max = &arr[0];
  for (int i = 1; i < length; ++i)
  {
    if (arr[i].area > max->area)
    {
      max = &arr[i];
    }
  }
  return max;
}

int main(void)
{
  srand(time(NULL));
  int length = rand() % 10 + 1;

  Circle crcls[length];
  for (int i = 0; i < length; ++i)
  {
    srand(time(NULL));
    Circle tmp;
    tmp.area = rand() % 60 + 1;
    tmp.x_coord = rand() % 60 + 1;
    tmp.y_cord = rand() % 60 + 1;

    crcls[i] = tmp;
  }

  Circle *mx = legnagyobb(crcls, length);

  printf("area: %lf \t x:%lf \t y:%lf", &mx->area, &mx->x_coord, &mx->y_cord);
  return 0;
}
