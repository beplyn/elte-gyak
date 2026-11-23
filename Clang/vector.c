#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Vector_Lengthen(Vector *v)
{
  int new_capacity = (v->capacity == 0) ? 4 : v->capacity * 2;

  void *new_start = realloc(v->start, new_capacity * v->elem_size);
  if (new_start == NULL)
  {
    fprintf(stderr, "Hiba: sikertelen memóriafoglalás!\n");
    return;
  }

  v->start = new_start;
  v->capacity = new_capacity;
}

Vector Vector_Create(size_t elem_size, int initial_capacity)
{
  Vector v = {.size = 0,
              .capacity = initial_capacity,
              .elem_size = elem_size,
              .start = malloc(initial_capacity * elem_size),
              .lengthen = Vector_Lengthen};
  return v;
}

void Vector_Push(Vector *v, const void *elem)
{
  if (v->size >= v->capacity)
  {
    v->lengthen(v);
  }
  void *target = (char *)v->start + (v->size * v->elem_size);
  memcpy(target, elem, v->elem_size);
  v->size++;
}
