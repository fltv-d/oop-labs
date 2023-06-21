#include "dll.h"

Item::Item() 
{
	next = 0;
	prev = 0;
}

Item::~Item()
{
	if(Next() == 0 && Prev() == 0)
	{
		next = 0;
		prev = 0;
	}
	else
	{
    	if (Prev() != 0) 
        {
            prev->next = Next();
        }
        if (Next() != 0) 
        {
            next->prev = Prev();
        }
        if (Prev() == 0) 
        {
        	next->prev = 0;
        }
        if (Next() == 0) 
        {
         	prev->next = 0;
        }
    }
}

Item *Item::Next() const
{
	return next;
}

Item *Item::Prev() const
{
	return prev;
}

List::List() 
{
	head = 0;
	tail = 0;
	count = 0;
}

List::~List()
{
	Clear();
}
Item *List::Head() const
{
    return head;
}

Item *List::Tail() const
{
   	return tail;
}

void List::Add(Item *node)
{   
    if(Head() != 0)
    {
    	tail->next = node;
        node->next = 0;
        node->prev = Tail();
        tail = node;    
	}
	if(Head() == 0)
	{
		head = node;
		tail = node;
		node->prev = 0;
		node->next = 0;
	}    
	count++; 
}

void List::Insert(Item *node, int number)
{
	if(number >= 0 && number < count)
    {
        Item *p = GetItem(number);
        if(p->Prev() == 0)
        {
        	head = node;
   	    }
        if(count > 1 && number != 0)
        {
            p->prev->next = node; 
        }
        node->next = p;
        node->prev = p->Prev();
        p->prev = node; 
        count++;
    }
    else
    {
        Add(node);
    }
}

Item *List::GetItem(int number) const
{
	Item *node = Head();
    unsigned int i = 0;
    while (node != 0 && i < number) 
	{
        node = node->Next();
        i++;
    }
    return node;
}

int List::GetIndex(const Item *node) const
{
    int number = 0;
    Item *p = Head();
    while (node != p && number < count) 
	{
        p = p->Next();
        number++;
    }
    return number;	
}

Item *List::Remove(int number) 
{
	Item *node;
    node = GetItem(number);
    if(node != 0)
    {
        if (node->Prev() != 0) 
    	{
            node->prev->next = node->Next();
        }
        if (node->Next() != 0) 
    	{
            node->next->prev = node->Prev();
        }
        if (node->Prev() == 0) 
    	{
    		node->next->prev = 0;
            head = node->Next();
        }
        if (node->Next() == 0) 
    	{
    		node->prev->next = 0;
            tail = node->Prev();
        }
    }
    count--;
    return node;
}

void List::Delete(int number)
{
    Item *p = GetItem(number); 
    if (p->Prev() == 0) 
    {
        head = p->Next();
    }
    if (p->Next() == 0) 
    {
        tail = p->Prev();
    }
    if (p)
        count--;
        delete p;
}

int List::Count() const
{
  return count;  
}

void List::Clear()
{
	while(count != 0)
	{
		Delete(0);
    }
    head = 0;
    tail = 0;
}

