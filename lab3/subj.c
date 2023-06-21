#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subj.h"

typedef struct FIO
{
	struct Item *prev;
	struct Item *next;	
	unsigned int type;
	unsigned int personnelNumber;
	char SecondName[30];
	char FirstName[15];
	char Patronymic[20];
} FIO;

typedef struct Mail
{
	struct Item *prev;
	struct Item *next;	
	unsigned int type;
	unsigned int personnelNumber;
	char Country[30];
	char City[30];
	char Street[20];
	char House[10];
	char Apartment[10];
} Mail;

typedef struct Telephone
{
	struct Item *prev;
	struct Item *next;	
	unsigned int type;
	unsigned int personnelNumber;
	char PhoneNumber[18];
	char Explanations[50];
} Telephone;

typedef struct Date
{
	struct Item *prev;
	struct Item *next;	
	unsigned int type;
	unsigned int personnelNumber;
	char Day[11];
	char Month[9];
	char Year[4];
	char Note[50];
} Date;

void Input(Base *p)
{
    if (p)
      switch (p->type)
      {
        case 1:
            InputFIO(p);
            break;
        case 2:
            InputMail(p);
            break;
        case 3:
            InputTelephone(p);
            break;
        case 4:
            InputDate(p);
            break;
        defaul:
            printf("ERROR: object type unknown!\n");
      }
    else
        printf("ERROR: null pointer!\n");		
}

void InputFIO(Base *p)
{
    FIO *a;
    a = (FIO*)p;
	printf("FIO:");
    fflush(stdin);
    do
    {
    	printf("\n\tPersonnel number(not less than 0): ");
    	scanf("%d", &(a->personnelNumber));
    } while(a->personnelNumber < 0);
	fflush(stdin);
	printf("\n\tSecond name(max - 30 symbols): ");
	scanf("%s", &(a->SecondName));
	fflush(stdin);
	printf("\n\tFirst name(max - 15 symbols): ");
	scanf("%s", &(a->FirstName));
	fflush(stdin);
	printf("\n\tPatronymic(max - 20 symbols): ");
	scanf("%s", &(a->Patronymic));	
}

void InputMail(Base *p)
{
    Mail *a;
    a = (Mail *)p;
	printf("Mail:");
    fflush(stdin);
    do
    {
    	printf("\n\tPersonnel number(not less than 0): ");
    	scanf("%d", &(a->personnelNumber));
    } while(a->personnelNumber < 0);
	fflush(stdin);
	printf("\n\tCountry(max - 30 symbols): ");
	scanf("%s", &(a->Country));
	fflush(stdin);
	printf("\n\tCity(max - 30 symbols): ");
	scanf("%s", &(a->City));
	fflush(stdin);
	printf("\n\tStreet(max - 20 symbols): ");
	scanf("%s", &(a->Street));
	fflush(stdin);
	printf("\n\tHouse(max - 10 symbols): ");
	scanf("%s", &(a->House));	
	fflush(stdin);
	printf("\n\tApartment(max - 10 symbols): ");
	scanf("%s", &(a->Apartment));			
}

void InputTelephone(Base *p)
{
    Telephone *a;
    a = (Telephone *)p;
	printf("Telephone:");
    fflush(stdin);
    do
    {
    	printf("\n\tPersonnel number(not less than 0): ");
    	scanf("%d", &(a->personnelNumber));
    } while(a->personnelNumber < 0);
	fflush(stdin);
	printf("\n\tPhone number(max - 18 symbols): ");
	scanf("%s", &(a->PhoneNumber));
	fflush(stdin);
	printf("\n\tExplanations(max - 50 symbols): ");
	scanf("%[^\n]", &(a->Explanations));
}

void InputDate(Base *p)
{
    Date *a;
    a = (Date *)p;
	printf("Date:");
    fflush(stdin);
    do
    {
    	printf("\n\tPersonnel number(not less than 0): ");
    	scanf("%d", &(a->personnelNumber));
    } while(a->personnelNumber < 0);
	fflush(stdin);
	printf("\n\tDay(max - 11 symbols): ");
	scanf("%s", &(a->Day));
	fflush(stdin);
	printf("\n\tMonth(max - 9 symbols): ");
	scanf("%s", &(a->Month));
	fflush(stdin);
	printf("\n\tYear(max - 4 symbols): ");
	scanf("%s", &(a->Year));
	fflush(stdin);
	printf("\n\tNote(max - 50 symbols): ");
	scanf("%[^\n]", &(a->Note));			
}

void Print(Base *p)
{
    if (p)
      switch (p->type)
      {
        case 1:
            PrintFIO(p);
            break;
        case 2:
            PrintMail(p);
            break;
        case 3:
            PrintTelephone(p);
            break;
        case 4:
            PrintDate(p);
            break;
        defaul:
            printf("ERROR: object type unknown!\n");
      }
    else
        printf("ERROR: null pointer!\n");	
}

void PrintFIO(Base *p)
{
    FIO *a;
    a = (FIO *)p;
	printf("FIO:\n");
	printf("\tPersonnel number: %d\n", a->personnelNumber);
	printf("\tSecond name: %s\n\tFirst name: %s\n\tPatronymic: %s\n", a->SecondName, a->FirstName, a->Patronymic);
}

void PrintMail(Base *p)
{
    Mail *a;
    a = (Mail *)p;
	printf("Mail:\n");
	printf("\tPersonnel number: %d\n", a->personnelNumber);
	printf("\tCountry: %s\n\tCity: %s\n\tStreet: %s\n\tHouse: %s\n\tApartment: %s\n", a->Country, a->City, a->Street, a->House, a->Apartment);	
}

void PrintTelephone(Base *p)
{
    Telephone *a;
    a = (Telephone *)p;
	printf("Telephone:\n");
	printf("\tPersonnel number: %d\n", a->personnelNumber);
	printf("\tPhone number: %s\n\tExplanations: %s\n", a->PhoneNumber, a->Explanations);	
}

void PrintDate(Base *p)
{
    Date *a;
    a = (Date *)p;
	printf("Date:\n");
	printf("\tPersonnel number: %d\n", a->personnelNumber);
	printf("\tDay: %s\n\tMonth: %s\n\tYear: %s\n\tNote: %s\n", a->Day, a->Month, a->Year, a->Note);	
}

int Sort(const void *p1, const void *p2)
{
    return strcmp(* (char * const *) p1, * (char * const *)p2);
} 

void SortingItems(List *list)
{
	Base *a;
	char **b;
	unsigned int n = 0, i = 0, k = 0, count = 0, help = 0, m = 0;
	while(n < Count(list))
	{
		a = ((Base*)GetItem(list, n));
		if(a->type == 1)
		{
			i++;
		}
		n++;
    }
    if(i > 0)
    {
        b = (char**)calloc(i, sizeof(*b));
        for(n = 0; n < i; n++)
        {
        	b[n] = (char*)calloc(30, sizeof(*b[n]));
        }
        i = 0;
        n = 0;
	while(n < Count(list))
	{
		a = ((Base*)GetItem(list, n));
		if(a->type == 1)
		{
			strcpy(b[i], ((FIO*)a)->SecondName);
			i++;
		}
		n++;
    }    
    n = 0;
    qsort(&b[0], i, sizeof(char*), Sort);
    count = 0;
	while(n < i)
	{
		while(count < Count(list))
		{
    		if(((Base*)GetItem(list, count))->type == 1 && strcmp(b[n], ((FIO*)GetItem(list, count))->SecondName) == 0)
	    	{
		    	a = ((Base*)GetItem(list, count));
		    	if(n == 0 && GetIndex(list, (Item*)a) != 0)
                {
                	a = ((Base*)Remove(list, count));
                    Insert(list, (Item*)a, 0);
                }
                else
                {
                    a = ((Base*)Remove(list, count));
                    Insert(list, (Item*)a, help);
                }
                if(n == 0)
                {
                    m = n;
                }
                else
                {
                	m = help;
                }
                help = GetIndex(list, (Item*)a) + 1;
                k = help;
                while(k < Count(list))
                {
                	if(((Base*)GetItem(list, m))->personnelNumber == ((Base*)GetItem(list, k))->personnelNumber && k != n)
                	{
                		a = ((Base*)Remove(list, k));
            	    	Insert(list, (Item*)a, help);
            	    	help = GetIndex(list, (Item*)a) + 1;
                    }
                    k++;
                }
            }
            count++;
        }
        n++;
        count = help;
   }
    for(n = 0; n < i; n++)
    {
        free(b[n]);
    }
    free(b);
    printf("The list is sorted successfully\n");
    }
    else
    {
    	printf("Not notes that include the second name.\n");	
    }
}

void SearchingItems(List *list)
{
	Base *item;
	char word[35];
	int i = 0, k = 0 , m = 0, count = 0;
	printf("Enter keyword(max - 35 symbols): ");
	scanf("%s", word);
	while(count < Count(list))
	{  
	    item = (Base*)GetItem(list, count);
        if(((Base*)item)->type == 3 || ((Base*)item)->type == 4)
        {
            if(((Base*)item)->type == 3)
		    {
		    	for(i = 0; i < 50; i++)
		    	{
		    		if(((Telephone*)item)->Explanations[i] == word[0])
		    		{
		    			k = i;
		    			m = 0;
		    			if(i == 0)
		    			{
		    		        while(((Telephone*)item)->Explanations[k] == word[m] && m < strlen(word))
		    		        {
		    		            if(m + 1 == strlen(word))
		    		            {
		    		            	Print((Base*)item);
		    		            	break;
		    		            }
		    		        k++;
		    		        m++;
		    		        }
		    	    	}
		    	    	else
		    	    	{
		    	    		if(k + strlen(word) >= strlen(((Telephone*)item)->Explanations))
		    	    		{
		    	    		if(((Telephone*)item)->Explanations[k-1] == 32)
		    	    		{
		    	    			while(((Telephone*)item)->Explanations[k] == word[m] && m < strlen(word))
		    		            {
		    		                if(m + 1 == strlen(word))
		    		                {
		    		                	Print((Base*)item);
		    		                	break;
		    		                }
		    		                k++;
		    		                m++;
		    		            }
		    	            }
		    	            }
		    	            else
		    	            {
		    	            	if(((Telephone*)item)->Explanations[k-1] == 32 && ((Telephone*)item)->Explanations[k + strlen(word)] == 32)
		    	    	    	{
		    	    		    	while(((Telephone*)item)->Explanations[k] == word[m] && m < strlen(word))
		    		                {
		    		                    if(m + 1 == strlen(word))
		    		                    {
		    		                    	Print((Base*)item);
		    		                    	break;
		    		                    }
		    		                    k++;
		    		                    m++;
		    		                }
		    	                }	
		    	            }
		    	        }
		        	}
		    	}
	        }
	        else
	        {
		    	for(i = 0; i < 50; i++)
		    	{
		    		if(((Date*)item)->Note[i] == word[0])
		    		{
		    			k = i;
		    			m = 0;
		    			if(i == 0)
		    			{
		    		        while(((Date*)item)->Note[k] == word[m] && m < strlen(word))
		    		        {
		    		            if(m + 1 == strlen(word))
		    		            {
		    		            	Print((Base*)item);
		    		            	break;
		    		            }
		    		        k++;
		    		        m++;
		    		        }
		    	    	}
		    	    	else
		    	    	{
		    	    		if(k + strlen(word) >= strlen(((Date*)item)->Note))
		    	    		{
		    	    		if(((Date*)item)->Note[k-1] == 32)
		    	    		{
		    	    			while(((Date*)item)->Note[k] == word[m] && m < strlen(word))
		    		            {
		    		                if(m + 1 == strlen(word))
		    		                {
		    		                	Print((Base*)item);
		    		                	break;
		    		                }
		    		                k++;
		    		                m++;
		    		            }
		    	            }
		    	            }
		    	            else
		    	            {
		    	            	if(((Date*)item)->Note[k-1] == 32 && ((Date*)item)->Note[k + strlen(word)] == 32)
		    	    	    	{
		    	    		    	while(((Date*)item)->Note[k] == word[m] && m < strlen(word))
		    		                {
		    		                    if(m + 1 == strlen(word))
		    		                    {
		    		                    	Print((Base*)item);
		    		                    	break;
		    		                    }
		    		                    k++;
		    		                    m++;
		    		                }
		    	                }	
		    	            }
		    	        }
		        	}
		    	}	        	
	        }
        }
        count++;
    }  
}

Base* Create(unsigned int number)
{
    Base *p = NULL;
    switch (number)
    {
      case 1:
        p = malloc(sizeof(FIO));
        break;
      case 2:  
        p = malloc(sizeof(Mail));
        break;
      case 3:  
        p = malloc(sizeof(Telephone));
        break;
      case 4:  
        p = malloc(sizeof(Date));
        break;
    }
    if (p)
      p->type = number; 
    return p;
}

void PrintListObjects(List *a)
{
    Item *p;
    if (a)
      if (a->head)
        for (p = a->head; p; p = p->next)
          Print((Base *)p);
      else
        printf("List is empty.\n");
    else
      printf("ERROR: wrong list!\n");
}

int DoMenu(unsigned int number)
{
    unsigned int i;
    if(number == 1)
    {
    	do
    	{
    	printf("List with information about people:\n"
		    	"1.  Add new item\n"
		    	"2.  Delete item from list\n"
		    	"3.  Search for an item by its number\n"
		    	"4.  Remove item\n"
		    	"5.  Inserting a item into a specified position\n"
		    	"6.  Counting items in a list\n"
		    	"7.  Clearing the list\n"
		    	"8.  The definition of the item number by the pointer to it\n"
		    	"9.  Show list\n"
		    	"10. Sorting items by second name\n"
		    	"11. Searching items by keyword\n"
		    	"0.  Exit\n"
		    	"Your choice: ");
		fflush(stdin);
        scanf("%d", &i);
        } while(i < 0 || i > 11);
	}
	else
	{
		do
		{
		printf("1. FIO\n"
		       "2. Mail\n" 
			   "3. Telephone\n"
			   "4. Date\n"  
			   "Your choice: ");
		fflush(stdin);
        scanf("%d", &i);
        } while(i < 1 || i > 4);
    }
    return i;
}

