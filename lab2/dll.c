#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void Add(List *list, Item *node) 
{
    if(list->head!=NULL)
    {
    	list->tail->next = node;
        node->next = NULL;
        node->prev = list->tail;
        list->tail = node;    
	}
	if(list->head==NULL)
	{
		list->head = node;
		list->tail = node;
		node->prev = NULL;
		node->next = NULL;
	}
}

int Count(List *list)
{
	unsigned int number = 0;
	Item *node;	
	node = list->head;
	while(node != NULL)
	{
		number++;
		node = node->next;
	}
	return number;
}

Item* GetItem(List *list, unsigned int number)
{
	Item *node = list->head;
    unsigned int i = 0;
    while (node != NULL && i < number) 
	{
        node = node->next;
        i++;
    }
    return node;
}

Item* Remove(List *list, unsigned int number)
{
	Item *node;
    node = GetItem(list, number);
    if(node != NULL)
    {
        if (node->prev != NULL) 
    	{
            node->prev->next = node->next;
        }
        if (node->next != NULL) 
    	{
            node->next->prev = node->prev;
        }
        if (node->prev == NULL) 
    	{
            list->head = node->next;
        }
        if (node->next == NULL) 
    	{
            list->tail = node->prev;
        }
    }
    return node;
}

void Delete(List *list, unsigned int number)
{
    free(Remove(list, number));
}

void Insert(List *list, Item *node, unsigned int number)
{
    unsigned int i = Count(list);
    if(i != number)
    {
        Item *p=GetItem(list, number);
        if(p->prev == NULL)
        {
        	list->head = node;
   	    }
        if(i > 1 && number != 0)
        {
            p->prev->next = node; 
        }
        node->next = p;
        node->prev = p->prev;
        p->prev = node; 
    }
    else
    {
        Add(list, node);
    }
}

int GetIndex(List *list, Item *node)
{
    unsigned int number = 0;
    Item *p = list->head;
    while (node != p && number < Count(list)) 
	{
        p = p->next;
        number++;
    }
    return number;
}

void Clear(List *list) 
{
    Item *node, *help;
	node = list->head;
	list->head = NULL;
	list->tail = NULL;
	while(node != NULL)
	{
        help = node->next;
        free(node);
		node = help;
	}
}
