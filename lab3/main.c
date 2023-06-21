#include <stdio.h>
#include <stdlib.h>
#include "subj.h"

void PrintList(List *list)
{
	unsigned int number = 0;
	Item *node;	                              
	node = list->head;
	if(node == NULL)
	{                                                                                              
		printf("There are no nodes in the list.\n");
	}
	if(node != NULL)
	{
    	printf("List: %p Head: %p Tail: %p\n", list, list->head, list->tail);
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
	    	printf("%d\t%p\t%p\t%p\n", number, node, node->prev, node->next);
	    	number++;
	    	node = node->next;
	    }
    }
}

List* CreateList() 
{
    List *list = (List*) malloc(sizeof(List));
    list->head = NULL;
	list->tail = NULL;
    return list;
}

int main()
{
	List *list = CreateList();
	Base *node;
	Item *item;
	unsigned int choice, number, help;
    do
    {
    	system("cls");
        choice = DoMenu(1);
    	switch(choice)
    	{
		    case 1:
                system("cls");
                number = DoMenu(0);  
                node = Create(number);
                Input(node);
                Add(list, (Item*)node);
                break;
            case 2:
            	system("cls");
                printf("Enter the item number: ");
                scanf("%d", &number);
                if(number < Count(list))
                {
                    Delete(list, number);
                    printf("The item is deleted successfully\n");              
                }
                else
                {
                    printf("There is no such item in the list.\n");	
			    }
                system("pause");
		    	break;
            case 3:
		    	system("cls");
		    	printf("Enter the item number: ");
		    	scanf("%d", &number);
		    	item = GetItem(list, number);
		    	if(item != NULL)
		     	{
		     		printf("Found item:\n");
		     		Print((Base*)item);
		    	}
	    		else
		    	{
                    printf("There is no such item in the list.\n");
                }
                system("pause");            	
            	break;
            case 4:
                system("cls");
                printf("Enter the item number: ");
		    	scanf("%d", &number);
		    	item = Remove(list, number);
		    	if(item != NULL)
		    	{
                    printf("Excluded item:\n");
                    Print((Base*)item);
                } 
                else
                {
                    printf("There is no such item in the list.\n");            	
		    	}
                system("pause");            	
                break;
            case 5:
                system("cls");
                number = DoMenu(0);  
                node = Create(number);
                Input(node);
                printf("Enter where to insert the item: ");
		    	scanf("%d", &number);   
		    	if(number <= Count(list) && number >= 0)  
		    	{
                    if (node == NULL) 
	                {
                    	printf("Sorry, adding a item is not possible.\n");
                    	system("pause");
                    }  
                    else
                    {
	            		Insert(list, (Item*)node, number);
	            	}
     	        }
     	        else
         	    {
         	    	printf("Item with such number is not in the list.\n");	
		    	}
	    		system("pause");            	
            	break;
            case 6:
                system("cls");
	    		printf("Items in the list: %d\n", Count(list));
	    		system("pause");          	
            	break;
            case 7:
    	    	system("cls");
	    		Clear(list);
	    		printf("The list is cleaned successfully\n");
	    		system("pause");        	
            	break;
            case 8:
     	        system("cls");
	        	printf("Enter the value of the pointer: \n");
	        	scanf("%p", &item);
	        	number = GetIndex(list, item);
	        	if(number < Count(list))
	        	{
                    printf("Found number: %d\n", number);     
	            }
	            else
	            {     
	            	printf("There is no such item in the list.\n");              
                }
	         	system("pause");       	
            	break;
            case 9:
            	system("cls");
            	printf("1. Show doubly linked list\n"
            	       "2. Show list with information about people\n"
            	       "3. Show the values of the elements on the screen\n"
					   "4. Show values of all elements of the specified type\n");
            	scanf("%d", &help);
            	switch(help)
            	{
            		case 1:
            		system("cls");
	    	    	PrintList(list);
	    	    	system("pause");
	    	    	break;
	    	    	case 2:
            		system("cls");
                    PrintListObjects(list);
	    	    	system("pause");
	    	    	break;
					case 3:
					system("cls");
					printf("Enter personnel number: ");
					scanf("%d", &number);
					for(item = list->head; item; item = item->next)
					{
						if(((Base*)item)->personnelNumber == number)
						{
							Print((Base*)item);
						}
					}
					system("pause");
					break;
					case 4:
					system("cls");
					printf("Select data type\n"
					       "1. FIO\n"
		                   "2. Mail\n" 
		            	   "3. Telephone\n"
		             	   "4. Date\n");
					scanf("%d", &number);
					for(item = list->head; item; item = item->next)
					{
						if(((Base*)item)->type == number)
						{
							Print((Base*)item);
						}
					} 
					system("pause");
					break;	    	    	
	        	}
            	break;   	
            case 10:
            	system("cls");
            	SortingItems(list);
            	system("pause");
            	break;
            case 11:
            	system("cls");
            	SearchingItems(list);
            	system("pause");
                   break;
            case 0:
            	break;
    	}
    } 
	while(choice != 0);
	return 0;
}


