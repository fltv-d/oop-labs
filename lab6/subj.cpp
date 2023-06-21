#include <conio.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include "subj.h"

using namespace std;

class FIO : public Base
{
private:
	char SecondName[30];
	char FirstName[15];
	char Patronymic[20];
public:
	void Input();
	void Print() const;
	int Type() const;
	const char* secondName() const;
};

class Mail : public Base
{
private:
	char Country[30];
	char City[30];
	char Street[20];
	char House[10];
	char Apartment[10];
public:
	void Input();
	void Print() const;
	int Type() const;
};

class Telephone : public Base
{
private:
	char PhoneNumber[18];
	char Explanations[50];
public:
	void Input();
	void Print() const;	
	int Type() const;
	const char* explanations() const;
};

class Date : public Base
{
private:
	char Day[11];
	char Month[9];
	char Year[4];
	char Note[50];
public:
	void Input();
	void Print() const;	
	int Type() const;
	const char* note() const;
};
Base &SubjList::operator[] (const int i)
{
	return *(Base*)GetItem(i);
}

int Base::operator > (const Base &i)
{
	if(strcmp(((FIO*)this)->secondName(), ((FIO&)i).secondName()) < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Base::operator == (const int i)
{
    if(this->Type() == 1)
    {
        return 1;           
    }  
    else
    {
        return 0;
    }  
}

int Base::operator == (const Base &i)
{
    if(this->personnelNumber == i.personnelNumber)
    {
        return 1;           
    }  
    else
    {
        return 0;
    }  
}

int FIO::Type() const { return 1;};

int Mail::Type() const { return 2;};

int Telephone::Type() const {return 3;};

int Date::Type() const {return 4;};

void Base::Input()
{
    this->Input();
}

void FIO::Input()
{
	cout << "FIO:";
    do
    {
    	cout << "\n\tPersonnel number(not less than 0): ";
    	cin >> personnelNumber;
    } while(personnelNumber < 0);
	cout << "\n\tSecond name(max - 30 symbols): ";
	cin >> SecondName;
	cout << "\n\tFirst name(max - 15 symbols): ";
	cin >> FirstName;
	cout << "\n\tPatronymic(max - 20 symbols): ";
	cin >> Patronymic;
}

void Mail::Input()
{
	cout << "Mail:";
    do
    {
    	cout << "\n\tPersonnel number(not less than 0): ";
        cin >> personnelNumber;
    } while(personnelNumber < 0);
	cout << "\n\tCountry(max - 30 symbols): ";
	cin >> Country;
	cout << "\n\tCity(max - 30 symbols): ";
	cin >> City;
	cout << "\n\tStreet(max - 20 symbols): ";
    cin >> Street;
	cout << "\n\tHouse(max - 10 symbols): ";
    cin >> House;
	cout << "\n\tApartment(max - 10 symbols): ";
	cin >> Apartment;		
}

void Telephone::Input()
{
	cout << "Telephone:";
    do
    {
    	cout << "\n\tPersonnel number(not less than 0): ";
    	cin >> personnelNumber;
    } while(personnelNumber < 0);
	cout << "\n\tPhone number(max - 18 symbols): ";
	cin >> PhoneNumber;
	cout << "\n\tExplanations(max - 50 symbols): ";
	cin.ignore();
	cin.getline(Explanations, 50);
}

void Date::Input()
{
	cout << "Date:";
    do
    {
    	cout << "\n\tPersonnel number(not less than 0): ";
		cin >> personnelNumber;
    } while(personnelNumber < 0);
	cout << "\n\tDay(max - 11 symbols): ";
    cin >> Day;
	cout << "\n\tMonth(max - 9 symbols): ";
	cin >> Month;
	cout << "\n\tYear(max - 4 symbols): ";
	cin >> Year;
	cout << "\n\tNote(max - 50 symbols): ";		
	cin.ignore();
	cin.getline(Note, 50);
}

void Base::Print() const
{
    this->Print();
}

void FIO::Print() const
{
	cout << "FIO:\n";
	cout << "\tPersonnel number: " << personnelNumber << '\n';
	cout << "\tSecond name: " << SecondName << "\n\tFirst name: " << FirstName << "\n\tPatronymic: " << Patronymic << '\n';
}

void Mail::Print() const
{
	cout << "Mail:\n";
	cout << "\tPersonnel number: " << personnelNumber << '\n';
	cout << "\tCountry: " << Country << "\n\tCity: " << City << "\n\tStreet: " << Street << "\n\tHouse: " << House << "\n\tApartment: " << Apartment << '\n';	
}

void Telephone::Print() const
{
	cout << "Telephone:\n";
	cout << "\tPersonnel number: " << personnelNumber << '\n';
	cout << "\tPhone number: " << PhoneNumber << "\n\tExplanations: " << Explanations << '\n';
}

void Date::Print() const
{
	cout << "Date:\n";
	cout << "\tPersonnel number: " << personnelNumber << '\n';
	cout << "\tDay: " << Day << "\n\tMonth: " << Month << "\n\tYear: " << Year << "\n\tNote: " << Note << '\n';	
}

const char* FIO::secondName() const
{
	return SecondName;
}

const char* Telephone::explanations() const
{
	return Explanations;
}

const char* Date::note() const
{
	return Note;
}

void SubjList::Print(int number)
{
	Item *node;
	if(number == 0)
	{
    	if (Head())
    	{
            for (node = Head(); node; node = node->Next())
            {
                ((Base*)node)->Print();
            }
        }
        else
        {
            cout << "List is empty.\n";
        }
    }
    else
    {
    	number = 0;
    	node = Head();
    	if(node == NULL)
	    {                                                                                              
	    	cout << "There are no nodes in the list.\n";
	    }
    	if(node != NULL)
    	{
        	printf("List: %p Head: %p Tail: %p\n", ((List*)this), Head(), Tail());
	    	if(sizeof(node)==4)
        	{
            	printf("#\tp\t        prev\t        next\n");
            }
            else
            {
            	printf("#\tp\t                prev\t                next\n");
	    	}
        	while(node != NULL)
        	{
	        	printf("%d\t%p\t%p\t%p\n", number, node, node->Prev(), node->Next());
	        	number++;
	        	node = node->Next();
	        }
        }
    }
}

void SubjList::Run()
{
    int choice, number, help;
    Item *p;
    do
    {
    	system("cls");
        choice = DoMenu(1);
        switch (choice)
        {
        case 1:
        	system("cls");
            number = DoMenu(0);  
            p = Create(number);      
			((Base*)p)->Input();	
            Add(p);
            break;
        case 2:
		    system("cls");
            cout << "Enter the item number: ";
            cin >> number;
            if(number >= 0 && number < Count())
            {
            	system("cls");
                Delete(number);
                cout << "The item is deleted successfully.\n";
            }
            else
            {
                system("cls");
                cout << "There is no such item in the list.\n";	
            }   
            getch();
            break;
        case 3:
            system("cls");
            cout << "Enter the item number: ";
            cin >> number;
            if(number >= 0 && number < Count())
            {
            	system("cls");
            	p = GetItem(number);
                cout << "Found item:\n";
		     	((Base*)p)->Print();
            }
            else
            {
                system("cls");
                cout << "There is no such item in the list.\n";
            } 
            getch();
            break;
        case 4:
            system("cls");
            number = DoMenu(0);  
            p = Create(number);
            ((Base*)p)->Input();
            cout << "Enter where to insert the item: ";
		    cin >> number;  
            Insert(p, number);          	
            break;
        case 5:
        	system("cls");
        	cout << "Items in the list: " << Count() << '\n';
            getch();
            break;
        case 6:
            system("cls");
            Clear();
	    	cout << "The list is cleaned successfully\n";
	    	getch();
            break;
        case 7:
     	    system("cls");
	        cout << "Enter the value of the pointer: ";
            fflush(stdin);
            scanf("%p", &p); 
            system("cls");
            if(Count() != GetIndex(p))
            {
                cout << "Found number: " << GetIndex(p) << '\n';
            }
            else
            {
                system("cls");
                cout << "There is no such item in the list.\n";   
            }
            getch(); 
            break;
        case 8:
            system("cls");
            cout <<	"1. Show doubly linked list\n" <<
			        "2. Show list with information about people\n" <<
            	    "3. Show the values of the elements on the screen\n" <<
				    "4. Show values of all elements of the specified type\n"; 
            cin >> help;
            switch(help)
            {
            	case 1:
                	system("cls");
                    Print(1);
	    	        getch();    
					break;        		
	    	    case 2:
                	system("cls");
                    Print(0);
	    	        getch();
	    	        break;
				case 3:
					system("cls");
					cout << "Enter personnel number: ";
					scanf("%d", &number);
					for(p = Head(); p; p = p->Next())
					{
						if(((Base*)p)->personnelNumber == number)
						{
							((Base*)p)->Print();
						}
					}
					getch();
					break;
				case 4:
					system("cls");
					cout << "Select data type\n" <<
					        "1. FIO\n" <<
		                    "2. Mail\n" <<
		            	    "3. Telephone\n" <<
		             	    "4. Date\n" <<
		             	    "Your choice: ";
					cin >> number;
					system("cls");
					for(p = Head(); p; p = p->Next())
					{
						if(((Base*)p)->Type() == number)
						{
							((Base*)p)->Print();
						}
					} 
					getch();
					break;	    	    	
	        }
            break;   	
        case 9:
            system("cls");
            cout << "Enter the item number: ";
            cin >> number;
            if(number >= 0 && number < Count())
            {
            	system("cls");
            	p = Remove(number);
            	cout << "Enter position where you want to insert the node: ";
            	cin >> number;
                Insert(p, number);
            }
            else
            {
                system("cls");
                cout << "There is no such item in the list.\n"; 
                getch();
            } 
            break;
        case 10:
            system("cls");
            SortingItems();
            getch();      	
        	break;
        case 11:
        	system("cls");
            SearchingItems();
            getch();
        	break;
        case 0:
        	break; 	
        }
    }
    while (choice != 0);
}

void SubjList::SortingItems()
{
	SubjList &a = *(this);
	int i, j, n = Count(), help = 0;
	for(i = 0; i < n - 1; i++)
	{
		if(a[i] == 1)
		{
	    	for(j = i + 1; j < n; j++)
	    	{
		    	if(a[j] == 1 && a[j] > a[i])
		    	{
		    		Insert(Remove(j), i);
		    	}
	    	}
    	}
	}
	for(i = 0; i < n - 1; i++)
	{
		if(a[i] == 1)
		{
			help = 1;
	    	for(j = i + 1; j < n; j++)
	    	{
		    	if(a[i] == a[j] && !(a[j] == 1))
		    	{
		    		Insert(Remove(j), i + help);
		    		help++;
		    	}
	    	}
    	}
	}
	if(help != 0)
	{
    	cout << "The list is sorted successfully\n";
    }
    else
    {
        cout << "Not notes that include the second name.\n";   
    } 
}

void SubjList::SearchingItems()
{
	Base *item;
	char word[35];
	int i = 0, k = 0 , m = 0, counter = 0;
	cout << "Enter keyword(max - 35 symbols): ";
	cin >> word;
	while(counter < Count())
	{  
	    item = (Base*)GetItem(counter);
        if(((Base*)item)->Type() == 3 || ((Base*)item)->Type() == 4)
        {
            if(((Base*)item)->Type() == 3)
		    {
		    	for(i = 0; i < 50; i++)
		    	{
		    		if(((Telephone*)item)->explanations()[i] == word[0])
		    		{
		    			k = i;
		    			m = 0;
		    			if(i == 0)
		    			{
		    		        while(((Telephone*)item)->explanations()[k] == word[m] && m < strlen(word))
		    		        {
		    		            if(m + 1 == strlen(word))
		    		            {
		    		            	((Base*)item)->Print();
		    		            	break;
		    		            }
		    		        k++;
		    		        m++;
		    		        }
		    	    	}
		    	    	else
		    	    	{
		    	    		if(k + strlen(word) >= strlen(((Telephone*)item)->explanations()))
		    	    		{
		    	    		if(((Telephone*)item)->explanations()[k-1] == 32)
		    	    		{
		    	    			while(((Telephone*)item)->explanations()[k] == word[m] && m < strlen(word))
		    		            {
		    		                if(m + 1 == strlen(word))
		    		                {
		    		                	((Base*)item)->Print();
		    		                	break;
		    		                }
		    		                k++;
		    		                m++;
		    		            }
		    	            }
		    	            }
		    	            else
		    	            {
		    	            	if(((Telephone*)item)->explanations()[k-1] == 32 && ((Telephone*)item)->explanations()[k + strlen(word)] == 32)
		    	    	    	{
		    	    		    	while(((Telephone*)item)->explanations()[k] == word[m] && m < strlen(word))
		    		                {
		    		                    if(m + 1 == strlen(word))
		    		                    {
		    		                    	((Base*)item)->Print();
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
		    		if(((Date*)item)->note()[i] == word[0])
		    		{
		    			k = i;
		    			m = 0;
		    			if(i == 0)
		    			{
		    		        while(((Date*)item)->note()[k] == word[m] && m < strlen(word))
		    		        {
		    		            if(m + 1 == strlen(word))
		    		            {
		    		            	((Base*)item)->Print();
		    		            	break;
		    		            }
		    		        k++;
		    		        m++;
		    		        }
		    	    	}
		    	    	else
		    	    	{
		    	    		if(k + strlen(word) >= strlen(((Date*)item)->note()))
		    	    		{
		    	    		if(((Date*)item)->note()[k-1] == 32)
		    	    		{
		    	    			while(((Date*)item)->note()[k] == word[m] && m < strlen(word))
		    		            {
		    		                if(m + 1 == strlen(word))
		    		                {
		    		                	((Base*)item)->Print();
		    		                	break;
		    		                }
		    		                k++;
		    		                m++;
		    		            }
		    	            }
		    	            }
		    	            else
		    	            {
		    	            	if(((Date*)item)->note()[k-1] == 32 && ((Date*)item)->note()[k + strlen(word)] == 32)
		    	    	    	{
		    	    		    	while(((Date*)item)->note()[k] == word[m] && m < strlen(word))
		    		                {
		    		                    if(m + 1 == strlen(word))
		    		                    {
		    		                    	((Base*)item)->Print();
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
        counter++;
    }  
}

int SubjList::DoMenu(int number)
{
    int i;
    if(number == 1)
    {
    	do
    	{
    	cout << "List with information about people:\n" <<
		        "1.  Add new item\n" <<
		     	"2.  Delete item from list\n" << 
		    	"3.  Search for an item by its number\n" << 
		     	"4.  Inserting a item into a specified position\n" <<
		     	"5.  Counting items in a list\n" <<
		     	"6.  Clearing the list\n" <<
		     	"7.  The definition of the item number by the pointer to it\n" <<
		     	"8.  Show list\n" <<
		     	"9.  Remove item\n" <<
		     	"10. Sorting items by second name\n" <<
		     	"11. Searching items by keyword\n" <<
		     	"0.  Exit\n" <<
		     	"Your choice: ";
        cin >> i;
        } while(i < 0 || i > 11);
	}
	else
	{
		do
		{
		cout << "1. FIO\n" <<
		        "2. Mail\n" <<
			    "3. Telephone\n" <<
			    "4. Date\n" <<
		        "Your choice: ";
        cin >> i;
        } while(i < 1 || i > 4);
    }
    return i;	
}

Item *SubjList::Create(int number)
{
    Base *p = NULL;
    switch (number)
    {
      case 1:
        p = new FIO;
        break;
      case 2:  
        p = new Mail;
        break;
      case 3:  
        p = new Telephone;
        break;
      case 4:  
        p = new Date;
        break;
    }
    return ((Item*)p);
}

