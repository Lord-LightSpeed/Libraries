#include <stdio.h>

typedef struct
{
  void* data;
  LinkedListNode* next;
} LinkedListNode;

typedef struct 
{
  LinkedListNode* head;
} LinkedList;

int GetLength(LinkedList l)
{
  LinkedListNode** p = &(l.head);
  int count;
  while ((*p) != NULL)
  {
    p = &((*p)->next);
    ++count;
  };
  return count;
};

void* Getitem(LinkedList l, int a)
{
  LinkedListNode** p = &(l.head);
  int count = 0;
  while (((*p) != NULL) && (count < a))
  {
    p = &((*p)->next);
    ++count;
  };
  if (count = a)
  {
    return (*p)->data;
  }
  else
  {
    return NULL;
  };
};