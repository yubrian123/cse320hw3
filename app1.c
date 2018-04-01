#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double functionOfX(int numPoly, double equation[], double xValue)
{
    int counter = 0;
    int degree = numPoly;
    double tmp = 0;
    while(counter <= numPoly)
    {
      tmp = tmp + equation[counter] * pow(xValue, degree);
      degree--;
      counter++;
    }
    return tmp;
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

  int numPoly;
  double tolerance;
  double a;
  double b;
  fscanf(fp, "%d %lf %lf %lf", &numPoly, &tolerance, &a, &b);
  double equation[numPoly];
  int counter = 0;

  //fill out equation
  while(counter <= numPoly)
  {
    fscanf(fp, "%lf", &equation[counter]);
    counter++;
  }
  fclose(fp);

  FILE *file_pointer;
  file_pointer = fopen("part2_solver.dat", "w");

  //Check if f(a) == 0
  if(functionOfX(numPoly, equation, a) == 0)
  {
    fprintf(file_pointer, "%lf", a);
    fclose(file_pointer);
    exit(0);
  }

  //check if f(b) == 0
  if(functionOfX(numPoly, equation, b) == 0)
  {
    fprintf(file_pointer, "%lf", b);
    fclose(file_pointer);
    exit(0);
  }

  double c;
  while (fabs(a-b) >= tolerance)
  {
        // Find middle point
        c = (a+b)/2;

        // Check if middle point is root
        if (functionOfX(numPoly, equation, c) == 0.0)
        {
          fprintf(file_pointer, "%lf", c);
          fclose(file_pointer);
          exit(0);
        }

        // Decide the side to repeat the steps
        else if (functionOfX(numPoly, equation, c)*functionOfX(numPoly, equation, a) < 0)
            b = c;
        else
            a = c;
  }
  fprintf(file_pointer, "%lf", a);
  fclose(file_pointer);
  exit(0);
}

