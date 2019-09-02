//Sidney Robinson
//CMPS12B/M
//simrobin 1643731
//listUtil.c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "listUtil.h"


//Prints the value of a singular node in the list
void
print_node(node)
	NodeObj *node;
{
       if (node == NULL ) //  quietly return if no list passed
	   {	
			fprintf(stderr, "Node is NULL");
			return;
	   }
        printf("-------Print-------\n Node Value = %d\n",
                node->value);
}
//Walks through the linked list and prints out the links using the next pointer
void
traverse_print(list_head)
        NodeObj *list_head;

{

        NodeObj *ptr=NULL;     //ptr to current node in the list

        if (list_head == NULL) //quietly return if no list passed
		{
			fprintf(stderr, "Empty list inserted or improper pointer to head");
			return;
		}
        ptr = list_head;        //start at the head of the list

        printf("\n----List traversal printing all elements of the list----\n");
        /* walk down the list printing until we have no more elements */

        while (ptr != NULL) {
                print_node(ptr);
                ptr = ptr->next;
        }
        printf("List printing done, end. \n");
}

//Walks through the linked list and prints out the links using the previous pointer
void
reverse_print(list_tail)
        NodeObj *list_tail;

{

        NodeObj *ptr=NULL;     //ptr to current node in the list

        if (list_tail == NULL) //quietly return if no list passed
		{
			fprintf(stderr, "Empty list_tail inserted or improper input");
			return;
		}

        ptr = list_tail;        //start at the head of the list

        printf("\n----List Reversal printing all elements of the list----\n");
        /* walk down the list printing until we have no more elements */

        while (ptr != NULL) {
                print_node(ptr);
                ptr = ptr->prev;
        }
        printf("List printing done, end. \n");
}
