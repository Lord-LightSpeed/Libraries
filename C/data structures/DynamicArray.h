#include <stdlib.h>
#include <string.h>

typedef struct
{
  void* items;
  int itemsinarray;
  int capacity;
  size_t sizeofitem;
} DynamicArray;

void DynamicArrayAppend(DynamicArray* da, void* item)
{
  if (da->itemsinarray = da->capacity)
  {
    da->items = realloc(da->items, (da->sizeofitem * da->capacity * 2));
    da->capacity = da->capacity * 2;
  };
  memcpy( (da->items + da->itemsinarray * da->sizeofitem), item, da->sizeofitem );
  ++da->itemsinarray;
};

void* GetItemFromDynamicArray(int index, DynamicArray da)
{
  if ((index + 1) > da.itemsinarray)
  {
    return NULL;
  };
  return (da.items + (da.sizeofitem * index));
};