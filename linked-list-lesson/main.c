#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


list_node head=NULL;

int main() {


    show_list(); /*show empty list*/
    delete_list(); /*trying to delete empty list*/

    add_item(1);
    add_item(2);
    add_item(3);
    add_item(4);
    /* insert_item(node_at(0),5); */ /* not implemented */
    show_list();

    printf("tail=%d\n",tail()->item); /*which is the last entry?*/

    /*remove_node(node_at(2));*/ /* node_at not implemented*/
   /* delete_list();*/ /* node_at not implemented*/
   /*delete_node(node_at(99));
   show_list();
   delete_node(node_at(0));
   delete_node(node_at(0));
   delete_node(node_at(0));
   delete_node(node_at(0));
   show_list();*/ /* node_at not implemented*/

    while(tail()!=NULL) {delete_node(tail()); show_list();};
    show_list();

    return 0;
}
