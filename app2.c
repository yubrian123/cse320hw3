#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Function that returns the resulting maxtric after matrix multiplcation
void maxtricMultiply(int m1, int m2, int matrix1[][m2],
                     int n1, int n2, int matrix2[][n2],
                     int maxtrix3[m1][m1])
{
  int x;
  int i;
  int j;
  for (i = 0; i < m1; i++)
  {
      for (j = 0; j < n2; j++)
      {
          maxtrix3[i][j] = 0;
          for (x = 0; x < m2; x++)
          {
              *(*(maxtrix3 + i) + j) += *(*(matrix1 + i) + x) *
                                   *(*(matrix2 + x) + j);
          }
      }
  }
}

int findTrace(int n, int matrix[][n])
{
  int sum = 0;
  int i;
  for(i = 0; i < n; i++)
  {
    sum += matrix[i][i];
  }
  return sum;
}

int main(int argc, char** argv) {

  char* inputFile = *(argv +1);
  FILE *fp;
  fp = fopen(inputFile, "r");

  if(fp == NULL)
  {
     printf("File Not Found\n");
     exit(0);
  }

  //matrix a dimensions
  int a;
  int b;
  fscanf(fp, "%d %d", &a, &b);
  int matrixA[a][b];
  int i,j;

  //filling in Matrix A
  for(i = 0; i < a; i++)
  {
    for(j = 0; j < b; j++)
    {
      fscanf(fp, "%d", &(matrixA[i][j]));
    }
  }

  //dimensions of matrix b
  int c;
  int d;
  fscanf(fp, "%d %d", &c, &d);
  int matrixB[c][d];

  //filling in  Matrix B
  for(i = 0; i < c; i++)
  {
    for(j = 0; j < d; j++)
    {
      fscanf(fp, "%d", &(matrixB[i][j]));
    }
  }

  //getting matrix c
  int matrixC[a][d];
  maxtricMultiply(a, b, matrixA, c, d, matrixB, matrixC);

  int trace = findTrace(a, matrixC);

  FILE *file_pointer;
  file_pointer = fopen("part2_trace.dat", "w");
  fprintf(file_pointer, "%d", trace);
  fclose(file_pointer);
  exit(0);
}

