#include <stdlib.h>
#include <string.h>

typedef struct
{
  void* items;
  int itemsinarray;
  int capacity;
  size_t sizeofitem;
} DynamicArray;

DynamicArray DynamicArrayAppend(DynamicArray da, void* item)
{
  if (da.itemsinarray = da.capacity)
  {
    da.items = realloc(da.items, (da.sizeofitem * da.capacity * 2));
    da.capacity = da.capacity * 2;
  };
  memcpy( (da.items + da.itemsinarray * da.sizeofitem), item, da.sizeofitem );
  ++da.itemsinarray;
  memset(item, 0, da.sizeofitem);
  free(item);
  return da;
};