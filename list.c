//Sidney Robinson
//CMPS12B/M
//simrobin 1643731
//List.c file that contains the fleshed out functions of list.h

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Creates a new node of NodeObj type
NodeObj *create_new_node(int newValue)
{
	
	NodeObj * newNode = malloc(sizeof(NodeObj));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->value = newValue;
	if(newNode == NULL)
	{
		fprintf(stderr, "newNode was not properly allocated and still exists in a NULL state");
		return NULL;
	}
	return newNode;
}

//Inserts a new node at the end of the list
void insert(NodeObj **list_head, NodeObj *to_be_inserted)
{
	if (list_head == NULL)
	{
		fprintf(stderr, "Empty list inserted or improper pointer to head");
		return;
	}
	NodeObj * ptr; 
	ptr = *list_head;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = to_be_inserted;
	to_be_inserted->prev = ptr;
}

//inserts a new node in order assuming that the list is presorted
void ordered_insert(NodeObj **list_head, NodeObj *to_be_inserted)
{
		if (list_head == NULL)
	{
		fprintf(stderr, "Empty list inserted or improper pointer to head");
		return;
	}
	NodeObj * ptr;
	ptr = *list_head;
	while(ptr->next != NULL)
	{
		if( ptr->value >= to_be_inserted->value)
		{
			printf("Check");
			if(ptr->prev != NULL)
			{
				to_be_inserted->prev = ptr->prev;
				to_be_inserted->next = ptr;
				ptr->prev = to_be_inserted;
				ptr = to_be_inserted->prev;
				ptr->next = to_be_inserted;
				break;
			}
			if(ptr->prev == NULL)
			{
				ptr->prev = to_be_inserted;
				to_be_inserted->next = ptr;
				to_be_inserted->prev = NULL;
				list_head = &to_be_inserted;
			}
			break;
		}
		ptr = ptr->next;
	}
	if(ptr->next == NULL)
	{
		if( ptr->value >= to_be_inserted->value)
		{
				to_be_inserted->next = ptr;
				to_be_inserted->prev = ptr->prev;
				ptr->prev = to_be_inserted;
				ptr = to_be_inserted->prev;
				ptr->next = to_be_inserted;
		}else
		{
				insert(list_head, to_be_inserted);
		}
	}
}

//free all the nodes in an array list given the head is passed as the parameter
void delete_all(NodeObj *list_head)
{
		if (list_head == NULL)
	{
		fprintf(stderr, "Empty list inserted or improper pointer to head");
		return;
	}
	NodeObj * temp;
	while(list_head->next != NULL)
	{
		temp = list_head->next;
		list_head->next = NULL;
		free(list_head);
		list_head = temp;
		list_head->prev = NULL;
	}
	free(list_head);
}

//delete a specific node in the linked list
void delete(NodeObj **list_head, NodeObj *to_be_deleted)
{
	if(list_head == NULL)
	{
		fprintf(stderr, "Empty list inserted or improper pointer to head");
		return;
	}
	NodeObj * ptr;
	ptr = *list_head;
	NodeObj * temp;
	if(ptr == to_be_deleted)
	{
		free(to_be_deleted);
		ptr = ptr->next;
		ptr->prev = NULL;
	}
	while(ptr->next->next != NULL)
	{
		if(ptr->next == to_be_deleted)
		{
			temp = ptr;
			ptr->next = to_be_deleted->next;
			free(to_be_deleted);
			ptr = ptr->next;
			ptr->prev = temp;
			break;
		}
		ptr = ptr->next;
	}
	ptr= ptr->next;
	if(ptr == to_be_deleted)
	{
		ptr = ptr->prev;
		ptr->next = NULL;
		free(to_be_deleted);
	}
}

