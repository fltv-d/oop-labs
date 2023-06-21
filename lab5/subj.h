#ifndef _SUBJ_H_
#define _SUBJ_H_
#include "dll.h"

class Base : public Item
{
	friend class SubjList;
protected:
	int type;
	int personnelNumber;
public:
	void Input();
	void Print() const;
};

class SubjList : public List 
{
public:
    void Print(int number);
    void Run();
    void SortingItems();
    void SearchingItems();
    int DoMenu(int number);
    Item *Create(int number);
};

#endif

