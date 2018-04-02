#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include<sys/wait.h>

int main(int argc, char** argv)
{
  if(*(argv + 1) == NULL)
  {
    perror("File Not Found. \n");
    return errno;
  }

  char* filename;
  char command[255];
  char fibArg[255];
  pid_t pid;

  filename = *(argv + 1);
  FILE *fp;
  fp = fopen(filename, "r");
  if(fp == NULL)
  {
    perror("File Not Found. \n");
    fclose(fp);
    return errno;
  }

  prompt:
  printf("Please choose between solver, trace, fib, change, or quit \n");
    scanf("%s", command);
    if(strcmp(command, "solver") == 0)
    {
      if((pid = fork()) == 0)
      {
        char* args[] = {"./solver", filename, NULL};
        execve("./solver", args, NULL);
        exit(0);
      }
      else if(pid < 0)
      {
	fclose(fp);
	perror("Fork Failed");
	return errno;
      }
      else
      {
	wait(NULL);
      }
      sleep(1);
      goto prompt;
    }
    else if(strcmp(command, "trace") == 0)
    {
      if((pid = fork()) == 0)
      {
        char* args[] = {"./trace", filename, NULL};
        execve("./trace", args, NULL);
        exit(0);
      }
      else if(pid < 0)
      {
	fclose(fp);
	perror("Fork Failed");
	return errno;
      }
      else
      {
	wait(NULL);
      }
      sleep(1);
      goto prompt;
    }
    else if(strcmp(command, "fib") == 0)
    {
      if((pid = fork()) == 0)
      {
        fscanf(fp, "%s", fibArg);
        char* args[] = {"./fib", fibArg, NULL};
        execve("./fib", args, NULL);
        exit(0);
      }
      else if(pid < 0)
      {
	fclose(fp);
	perror("Fork Failed");
	return errno;
      }
      else
      {
	wait(NULL);
      }
      sleep(1);
      goto prompt;
    }
    else if(strcmp(command, "change") == 0)
    {
      fclose(fp);
      printf("Enter New File: \n");
      scanf("%s", filename);
      fp = fopen(filename, "r");
      if(fp == NULL)
      {
        perror("File Not Found. \n");
        fclose(fp);
        return errno;
      }
      goto prompt;
    }
    else if(strcmp(command, "quit") == 0)
    {
      fclose(fp);
      return 0;
    }
    else
    {
      perror("Unknown Command");
      goto prompt;
    }
}

