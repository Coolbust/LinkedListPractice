//Sidney Robinson
//List.h(Header file for list.c)

#include <stdio.h>
#include <stdlib.h>

//Defining the node
typedef struct NodeObj {
	int		value;
	struct 	NodeObj *prev;
	struct	NodeObj *next;
} NodeObj;

//Contains the function prototypes/shell and requirements for list.c files
NodeObj *create_new_node(int id);

void insert(NodeObj **list_head, NodeObj *to_be_inserted);

void ordered_insert(NodeObj **list_head, NodeObj *to_be_inserted);

void delete_all(NodeObj *list_head);

void delete(NodeObj **list_head, NodeObj *to_be_deleted);
