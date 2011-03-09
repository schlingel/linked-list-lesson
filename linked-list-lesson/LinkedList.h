#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdlib.h>
typedef int primary_type; /* in this example, int is primary type*/

struct node {
    primary_type item;
    struct node *next;
};

typedef struct node *list_node; /*a type for node-pointers*/

list_node head ; /*pointer to first element in list*/

list_node tail();
void show_node();
void show_list();

void add_node();
void add_item(primary_type);
void insert_node(list_node,list_node);
void insert_item(list_node, primary_type);
void remove_node(list_node);
void delete_node(list_node);

void delete_list();

list_node node_at(int);
int is_empty();
int size();
int index_of(primary_type);

void to_front(list_node);
list_node select(primary_type);

#endif /* LINKEDLIST_H_INCLUDED*/
