#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

uint64_t fib(int n)
{
  /* Declare an array to store Fibonacci numbers. */
  uint64_t f[n];
  int i;

  /* 0th and 1st number of the series are 0 and 1*/
  f[0] = 0;
  f[1] = 1;

  for (i = 2; i <= n; i++)
  {
      /* Add the previous 2 numbers in the series
         and store it */
      f[i] = f[i-1] + f[i-2];
  }

  return f[n];
}

int main(int argc, char** argv) {

  char* inputNum = *(argv +1);

  int nthFib = atoi(inputNum);

  uint64_t nthFibResult = fib(nthFib);

  FILE *file_pointer;
  file_pointer = fopen("part2_fib.dat", "w");
  fprintf(file_pointer, "%lu", nthFibResult);
  fclose(file_pointer);
  exit(0);
}

