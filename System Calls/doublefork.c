#include<stdio.h>
#include<unistd.h>
int main()
{
  printf("Calling double fork:\n");
  fork();
  fork();
  printf("Good Morning!\n");
  return 0;
}
