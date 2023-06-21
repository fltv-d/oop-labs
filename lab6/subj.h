#ifndef _SUBJ_H_
#define _SUBJ_H_
#include "dll.h"

class Base : public Item
{
	friend class SubjList;
protected:
	int personnelNumber;
public:
	int operator > (const Base &i);
	int operator == (const Base &i);
	int operator == (const int i);
	virtual void Input();
	virtual void Print() const;
	virtual int Type() const = 0;
};

class SubjList : public List 
{
public:
	Base &operator[] (const int i);
    void Print(int number);
    void Run();
    void SortingItems();
    void SearchingItems();
    int DoMenu(int number);
    Item *Create(int number);
};

#endif

