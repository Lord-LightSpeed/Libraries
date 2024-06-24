#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
  char* data;
  size_t length;
} StringView;

void StringViewappend(StringView* s, StringView a)
{
  size_t sizeold;
  sizeold = s->length;
  s->length += a.length;
  s->data = realloc(s->data, s->length);
  memcpy((s->data + sizeold), a.data, a.length);
};