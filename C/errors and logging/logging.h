#include <stdio.h>
#include <windows.h>

#define LOGGING

FILE* filelocation;

void setuplog()
{
  SYSTEMTIME t;
  GetLocalTime(&t);
  char* filename;
  filename = "LOG-%u-%u-%u-%u-%u-%u-%u.txt", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond, t.wMilliseconds;
  if (filelocation = NULL)
  {
    filelocation = fopen((filename), "a");
  }
  else
  {
    fprintf(filelocation, ("[info]:  attempted to create file: %s", filename));
    fprintf(filelocation, "[ERROR]: LOG FILE ALREADY EXISTS");
    printf("[ERROR]: LOG FILE ALREADY EXISTS");
    fclose(filelocation);
    exit(-1);
  };
};

void infolog(char* info)
{
  fprintf(filelocation, ("[INFO]:  %s", info));
};

void errorlog(char* error)
{
  fprintf(filelocation, ("[ERROR]: %s", error));
};

void endlog()
{
  if (filelocation != NULL)
  {
    fclose(filelocation);
    filelocation = NULL;
  };
};