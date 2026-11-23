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

BinaryTreeElement *Initialize()
{
  BinaryTreeElement *first;
  first = malloc(sizeof(BinaryTreeElement));

  return first;
};
