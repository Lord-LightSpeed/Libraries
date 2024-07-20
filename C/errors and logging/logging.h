#include <stdio.h>
#include <windows.h>

#define LOGGING

FILE* fl;

void setuplog()
{
  SYSTEMTIME t;
  GetLocalTime(&t);
  char* fn;
  fn = "LOG-%d-%d-%d-%d-%d-%d-%d.txt", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond, t.wMilliseconds;
  if (fl = NULL)
  {
    fl = fopen((fn), "a");
  }
  else
  {
    fprintf(fl, ("[info]:  attempted to create file: %s", fn));
    fprintf(fl, "[ERROR]: LOG FILE ALREADY EXISTS");
    printf("[ERROR]: LOG FILE ALREADY EXISTS");
    fclose(fl);
    exit(-1);
  };
};

void infolog(char* info)
{
  fprintf(fl, ("[INFO]:  %s", info));
};

void errorlog(char* error)
{
  fprintf(fl, ("[ERROR]: %s", error));
};

void endlog()
{
  if (fl != NULL)
  {
    fclose(fl);
    fl = NULL;
  };
};