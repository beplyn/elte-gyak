#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[30];
  int age;
  int salary;

} Employee;

void raiseSalary(Employee employees[], int size, int threshold, int amount)
{
  for (int i = 0; i < size; ++i)
    if (employees[i].salary < threshold)
      employees[i].salary += amount;
}

void printEmployee(Employee e)
{
  printf("Name: %s\n Age: %d\n salary: %d", e.name, e.age, e.salary);
  return;
}

int main(void)
{
  Employee *employees = malloc(sizeof(Employee) * 5);
  int size = 0;
  int capacity = 5;

  char name[30];
  int age;
  int salary;

  FILE *f = fopen("emberek.txt", "r");

  while (fscanf(f, "%s %d %d", name, &age, &salary) == 3)
  {
    if (size == capacity)
    {
      capacity *= 2;
      employees = realloc(employees, capacity * sizeof(Employee));
    }
    strcpy(employees[size].name, name);
    employees[size].age = age;
    employees[size].salary = salary;
    ++size;
  }

  fclose(f);

  // raiseSalary(employees, ???, 100, 100);

  free(employees);
  return 0;
}
