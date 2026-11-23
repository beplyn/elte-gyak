#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinaryTreeElement BinaryTreeElement;
struct BinaryTreeElement
{
  struct BinaryTree *right;
  int value;
  struct BinaryTree *left;
};

typedef struct LinkedListElement LinkedListElement;
struct LinkedListElement
{
  struct LinkedListElement *element_before;
  int value;
  struct LinkedListElement *element_after;
};

union ComplexTypes
{
  LinkedListElement;
  BinaryTreeElement;
};

union ComplexTypes *Initialize(const char *typ)
{
  union ComplexTypes *first;
  if (strcmp(typ, "BT"))
    first = malloc(sizeof(BinaryTreeElement));
  if (strcmp(typ, "LL"))
    first = malloc(sizeof(LinkedListElement));

  return first;
};

union
