#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  char* err;
  void* data;
} Result;

#ifdef LOGGING

  void* unwrap(Result a, FILE* l)
  {
    if (a.err == NULL)
    {
      return a.data;
    }
    else
    {
      fprintf(l, ("[ERROR]: %s", a.err));
      fclose(l);
      printf(("[ERROR]: %s", a.err));
      exit(-1);
    };
  };

#else

  void* unwrap(Result a)
  {
    if (a.err == NULL)
    {
      return a.data;
    }
    else
    {
      printf(("[ERROR]: %s", a.err));
      exit(-1);
    };
  };

#endif