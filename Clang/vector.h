#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct Vector
{
  int capacity;
  int size;
  size_t elem_size;
  void *start;
  void (*lengthen)(struct Vector *self);
} Vector;

Vector Vector_Create(size_t elem_size, int initial_capacity);
void Vector_Lengthen(Vector *v);
void Vector_Push(Vector *v, const void *elem);

#endif
