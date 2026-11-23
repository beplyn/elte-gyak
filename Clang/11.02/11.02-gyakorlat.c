#include <stdio.h>
#include <stdlib.h>

int *f() {
  int *p = malloc(sizeof(int));
  return p;
}

int main(void) {
  int i = 1;
  int *p = &i;

  {
    printf("%d\n", i);
    int i = 2;
    printf("%d\n", i);
  }
  printf("%d\n", i);

  int *u = f();
  printf("%d\n", *u);
  free(u);

  return 0;
}
