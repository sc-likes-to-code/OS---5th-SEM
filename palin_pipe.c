#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
  int p[2], num, n, rev = 0;
  
  if (pipe(p) < 0)
  {
    printf("Pipe creation failed");
    exit(1);
  }

  printf("Enter a number: ");
  scanf("%d", &num);
  
  write(p[1], &num, sizeof(num));

  read(p[0], &num, sizeof(num));

  n = num;
  while (n != 0)
  {
    rev = rev * 10 + (n % 10);
    n /= 10;
  }

  if (num == rev)
    printf("Palindrome number");
  else
    printf("Not a Palindrome number");

  return 0;
}
