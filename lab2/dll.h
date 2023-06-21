#ifndef _DLL_H_
#define _DLL_H_

typedef struct Item
{
	struct Item *prev;
	struct Item *next;	
} Item;

typedef struct List
{
	struct Item *head;
	struct Item *tail;
} List;

void Add(List *list, Item *node);
int Count(List *list);
Item* GetItem(List *list, unsigned int number);
Item* Remove(List *list, unsigned int number);
void Delete(List *list, unsigned int number);
void Insert(List *list, Item *node, unsigned int number);
int GetIndex(List *list, Item *node);
void Clear(List *list);

#endif
