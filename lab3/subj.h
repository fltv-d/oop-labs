#ifndef _SUBJ_H_
#define _SUBJ_H_
#include "dll.h"

typedef struct Base 
{
    struct Item *next;
	struct Item *prev;	
	unsigned int type;
	unsigned int personnelNumber;
} Base;

void Input(Base *p);
void InputFIO(Base *p);
void InputMail(Base *p);
void InputTelephone(Base *p);
void InputDate(Base *p);
void Print(Base *p);
void PrintFIO(Base *p);
void PrintMail(Base *p);
void PrintTelephone(Base *p);
void PrintDate(Base *p);
int Sort(const void *p1, const void *p2);
void SortingItems(List *list);
void SearchingItems(List *list);
Base* Create(unsigned int number);
void PrintListObjects(List *list);
int DoMenu(unsigned int number);

#endif
