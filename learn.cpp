#include <stdio.h>

int main()
{
  char name[20];
  char other[] = "Hello";

  printf("Enter your name: ");
  scanf("%s", name);

  printf("%s %s\n", other, name);
}