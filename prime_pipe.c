#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
  int p[2], num, flag = 0;
  
  if (pipe(p) < 0)
  {
    printf("Pipe creation failed");
    exit(1);
  }

  printf("Enter a number: ");
  scanf("%d", &num);
  
  write(p[1], &num, sizeof(num));

  read(p[0], &num, sizeof(num));

  if (num < 2)
  {
    flag = 1;
  }

  for (int i = 2; i * i <= num; i++)
  {
    if (num % i == 0)
    {
        flag = 1;
        break;
    }
  }

  if (flag == 0)
  {
    printf("Prime number\n");
  }

  else
  {
    printf("Not a prime number\n");
  }

  return 0;
}
