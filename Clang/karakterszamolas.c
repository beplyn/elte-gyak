#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  unsigned char character;
  int amount;
} Appearance;

typedef struct
{
  Appearance *start;
  int size;
  int capacity;
} Vector;

int record_char(Vector *vec, unsigned char c)
{
  for (int i = 0; i < vec->size; i++)
  {
    if (vec->start[i].character == c)
    {
      vec->start[i].amount++;
      return 1;
    }
  }

  if (vec->size == vec->capacity)
  {
    int new_cap = vec->capacity == 0 ? 5 : vec->capacity * 2;
    Appearance *tmp = realloc(vec->start, sizeof(Appearance) * new_cap);
    if (NULL == tmp)
    {
      return 0;
    }
    vec->start = tmp;
    vec->capacity = new_cap;
  }

  vec->start[vec->size].character = c;
  vec->start[vec->size].amount = 1;
  vec->size++;
  return 1;
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    fprintf(stderr, "filename argument missing\n");
    return 1;
  }

  FILE *ifp = fopen(argv[1], "r");
  if (NULL == ifp)
  {
    fprintf(stderr, "Error opening %s: %s\n", argv[1], strerror(errno));
    return 1;
  }

  Vector counter = {
      .start = malloc(sizeof(Appearance) * 5),
      .size = 0,
      .capacity = 5,
  };
  if (NULL == counter.start)
  {
    perror("malloc");
    fclose(ifp);
    return 1;
  }

  int ch;
  while ((ch = fgetc(ifp)) != EOF)
  {
    if (!record_char(&counter, ch))
    {
      perror("realloc");
      free(counter.start);
      fclose(ifp);
      return 1;
    }
  }

  for (int i = 0; i < counter.size; i++)
  {
    unsigned char c = counter.start[i].character;
    if (c == '\n')
      printf("\\n: %d\n", counter.start[i].amount);
    else if (c == '\t')
      printf("\\t: %d\n", counter.start[i].amount);
    else if (c >= 32 && c <= 126)
      printf("%c:  %d\n", c, counter.start[i].amount);
    else
      printf("0x%02x: %d\n", c, counter.start[i].amount);
  }

  free(counter.start);
  fclose(ifp);
  return 0;
}
