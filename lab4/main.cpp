#include <conio.h>
#include <stdio.h>
#include <iostream>
#include "dll.h"

using namespace std;

class DebugList : public List 
{
public:
  void Print();
  void Run();
};

void DebugList::Print()
{
    unsigned int number = 0;
	Item *node;	                              
	node = Head();
	
	if(node == NULL)
	{                                                                                              
		printf("There are no nodes in the list.\n");
	}
	if(node != NULL)
	{
    	printf("List: %p Head: %p Tail: %p\n", this, Head(), Tail());
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

void DebugList::Run()
{
    char c;
    int i;
    Item *p;
    do
    {
        system("cls");
    	cout << "Doubly linked list:\n" <<
		        "1. Add node in the end\n" <<
		     	"2. Delete node from list\n" << 
		    	"3. Search for an node by its number\n" << 
		     	"4. Inserting a node into a specified position\n" <<
		     	"5. Counting nodes in a list\n" <<
		     	"6. Clearing the list\n" <<
		     	"7. The definition of the node number by the pointer to it\n" <<
		     	"8. Show full list\n" <<
		     	"9. Remove node\n" <<
		     	"0. Exit\n" <<
		     	"Your choice: ";
        c = getche();
        cout << '\n';
        switch (c)
        {
        case '1':
            Add(new Item);
            break;
        case '2':
         	system("cls");
            cout << "Enter position: ";
            cin >> i;
            if(i >= 0 && i < Count())
            {
                Delete(i);
            }
            else
            {
                system("cls");
                cout << "Input Error\n";
            }   
            getch();
            break;
        case '3':
         	system("cls");
            cout << "Enter position: ";
            cin >> i;
            if(i >= 0 && i < Count())
            {
                cout << '\n' << "Pointer: " << GetItem(i) << '\n';
            }
            else
            {
                system("cls");
                cout << "Input Error\n";
            } 
            getch();
            break;
        case '4':
        	system("cls");
            cout << "Enter position: ";
            cin >> i;
            Insert(new Item, i);
            break;
        case '5':
        	system("cls");
        	cout << "Count: " << Count() << '\n';
            getch();
            break;
        case '6':
            Clear();
            break;
        case '7':
         	system("cls");
            cout << "Enter pointer: ";
            fflush(stdin);
            scanf("%p", &p); 
            if(Count() != GetIndex(p))
            {
                cout << '\n' << "Position: " << GetIndex(p) << '\n';
            }
            else
            {
                system("cls");
                cout << "Input Error\n";    
            }
            getch();
            break;
        case '8':
        	system("cls");
         	Print();
            getch();
         	break;
        case '9':
         	system("cls");
            cout << "Enter position: ";
            cin >> i;
            if(i >= 0 && i < Count())
            {
            	system("cls");
            	p = Remove(i);
            	cout << "Enter position where you want to insert the node: ";
            	cin >> i;
                Insert(p, i);
            }
            else
            {
                system("cls");
                cout << "Input Error\n";
            } 
            getch();
            break;
        case '0':
        	break; 	
        }
    }
    while (c != '0');
}

int main()
{
  DebugList L;
  L.Run();
  return 0;
}

