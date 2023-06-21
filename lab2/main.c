#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

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
	Item *node;
	unsigned int choice, number;
    do
    {
    	system("cls");
    	printf("Doubly linked list:\n"
		    	"1. Add node in the end\n"
		    	"2. Delete node from list\n"
		    	"3. Search for an node by its number\n"
		    	"4. Remove node\n"
		    	"5. Inserting a node into a specified position\n"
		    	"6. Counting nodes in a list\n"
		    	"7. Clearing the list\n"
		    	"8. The definition of the node number by the pointer to it\n"
		    	"9. Show full list\n"
		    	"0. Exit\n"
		    	"Your choice: ");
    	scanf("%d", &choice);
    	switch(choice)
    	{
		    case 1:
                system("cls");
                node = (Item*)malloc(sizeof(Item));
                if (node == NULL) 
            	{
                	printf("Sorry, adding a node is not possible.\n");
                	system("pause");
                }
                else
                {
		        	Add(list, node);
                	printf("Node successfully added to the end.\n");
	        		system("pause");
                }
		    	break;
	     	case 2:
                system("cls");
                printf("Enter the node number: ");
                scanf("%d", &number);
                if(number < Count(list))
                {
                    Delete(list, number);
                    printf("The node is deleted successfully\n");              
                }
                else
                {
                    printf("There is no such node in the list.\n");	
			    }
                system("pause");
		    	break;
	     	case 3:
		    	system("cls");
		    	printf("Enter the node number: ");
		    	scanf("%d", &number);
		    	node = GetItem(list, number);
		    	if(node != NULL)
		     	{
		     		printf("Found node: %p\n", node);
		    	}
	    		else
		    	{
                    printf("There is no such node in the list.\n");
                }
                system("pause");
		    	break;
	    	case 4:
                system("cls");
                printf("Enter the node number: ");
		    	scanf("%d", &number);
		    	node=Remove(list, number);
		    	if(node != NULL)
		    	{
                    printf("Excluded node: %p\n", node);
                } 
                else
                {
                    printf("There is no such node in the list.\n");            	
		    	}
                system("pause");
		    	break;
	    	case 5:
                system("cls");
                printf("Enter where to insert the node: ");
		    	scanf("%d", &number);   
		    	if(number <= Count(list) && number >= 0)  
		    	{
                    node = (Item*)malloc(sizeof(Item)); 
                    if (node == NULL) 
	                {
                    	printf("Sorry, adding a node is not possible.\n");
                    	system("pause");
                    }  
                    else
                    {
	            		Insert(list, node, number);
	            	}
     	        }
     	        else
         	    {
         	    	printf("Node with such number is not in the list.\n");	
		    	}
	    		system("pause");
	    		break;
	    	case 6:
                system("cls");
	    		printf("Nodes in the list: %d\n", Count(list));
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
	        	scanf("%p", &node);
	        	number = GetIndex(list, node);
	        	if(number < Count(list))
	        	{
                    printf("Found number: %d\n", number);     
	            }
	            else
	            {     
	            	printf("There is no such node in the list.\n");              
                }
	         	system("pause");
		        break;	
	    	case 9:
                system("cls");
	    		PrintList(list);
	    		system("pause");
	    		break;
	    	case 0:
	    		break;
    	}
    } 
	while(choice!=0);
	return 0;
}


