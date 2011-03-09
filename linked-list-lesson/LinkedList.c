#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void add_item(primary_type data) {
    list_node new_node;
    if (NULL== (new_node=malloc(sizeof(list_node)))) {
        printf("add_item: node allocation failed");
        exit(-1);
    }
    new_node->item=data;
    new_node->next=NULL;
    add_node(new_node);

}

void add_node(list_node new_node) {
    list_node end=tail();
     printf("add_node: adding node (%p)\n",new_node);
    if (new_node==NULL) {
        printf("add_node: cannot insert empty node\n");
        return;
    }
    if (head==NULL) {
        printf("add_node: [info] first element in list\n");
        new_node->next=NULL;
        head=new_node;
        return;
    }
    end->next=NULL;
    end->next=new_node;

}

void show_list() {
    list_node node=head;
    printf("-----\n");
    printf("show_list:\n");
    if (head==NULL) printf("show_list: list empty\n");
    while (node!=NULL) {
        show_node(node);
        node=node->next;
    }
    printf("-----\n");
}

void show_node(list_node node){
        if(node==NULL){
            printf("show_node: empty node\n");
            return;
        }
        printf("%d (node@%p)\n",node->item,node);
}




list_node tail() {
    list_node cur=head;
    if(NULL==head) return NULL;
    while (cur->next != NULL ) {
        cur=cur->next;
    }

    return cur;
}
void insert_node(list_node node, list_node new_node) {
    if (new_node==NULL) {
        printf("insert_node: cannot insert empty node\n");
        return;
    }
    if (head==NULL) {
        printf("insert_node: inserting in empty list\n");
        new_node->next=NULL;
        head=new_node;
        return;
    }  else if (node==NULL) {
        printf("insert_node: empty node\n");
        return;
    }


    new_node->next=node->next;
    node->next=new_node;

}
void insert_item(list_node node, primary_type item) {
    list_node new_node=malloc(sizeof(list_node));
    if (NULL==new_node) {
        printf("insert_item: node allocation failed");
        exit(-1);
    }
    new_node->item=item;
    new_node->next=NULL;
    insert_node(node, new_node);
}
void remove_node(list_node obsolete){
    list_node cur=head;
    printf("remove_node:  removing node (%p)\n",obsolete);
    if (obsolete==NULL) {
        printf("remove_node: empty node\n");
        return;
    }
    if (head==NULL) {
        printf("remove_node: [info] empty list\n");
        return; /*empty list*/
    }
    if(obsolete==head){
        printf("remove_node: [info] node is  head (%p)\n",obsolete);
        head=obsolete->next;
        return;
    }

    while (cur->next!=NULL && cur->next!=obsolete) {
        cur=cur->next;
    }
    if(cur->next==NULL){
         printf("remove_node: [info] not in list (%p)\n",obsolete);
        return;
    }

    cur->next=cur->next->next;
    obsolete->next=NULL;


}
void delete_node(list_node obsolete) {
    printf("delete_node: deleting node (%p)\n",obsolete);
    remove_node(obsolete);
    free(obsolete);
}

void delete_list(){
    printf("delete_list:\n");
    while(head!=NULL) delete_node(head);

}
int size(){
    list_node aktuell = head;
    int size = 0;

    while(aktuell != NULL) {
        size++;
        aktuell = aktuell->next;
    }

    return size;
}

int index_of(primary_type data){
    list_node aktuell = head;
    int aktuellerIndex = 0;
    if(head == NULL) {
        return -1;
    }

    while(aktuell != NULL) {
        if(aktuell->item == data) {
            return aktuellerIndex;
        }

        aktuellerIndex++;
    }

    return -1;
}
list_node node_at(int n) {
    int curPos = 0;
    list_node aktuell = head;

    if(head == NULL) {
        (void)fprintf(stderr, "Die liste ist null!");
        return NULL;
    }

    if(n < 0) {
        (void)fprintf(stderr, "Der Index muss größer gleich 0 sein!");
        return NULL;
    }

    while(aktuell != NULL) {
        if(curPos == n) {
            return aktuell;
        }

        curPos++;
        aktuell = aktuell->next;
    }

    (void)fprintf(stderr, "Der Index ist nicht innerhalb der Listengröße!");
    return NULL;
}

/** function is_empty
 * Prüft ob die Liste Elemente enthält.
 * Annahme:
 *  - Die Datenstruktur wurde ordentlich verwendet
 */
int is_empty(){
    /*returns 1, if list has no elements, 0 otherwise*/
    return (head == NULL) ? 1 : 0;
 return 0;
}


void to_front(list_node node){
    /*makes node the head of the list*/
    if(node == NULL) {
        (void)fprintf(stderr, "to_front akzeptiert keine NULL nodes!");
        return;
    }

    if(head == NULL) { // das erste element
        head = node;
    }
    else {
        node->next = head;
        head = node;
    }

    return;
}

list_node select(primary_type a){
    /*returns a list of all elements < a*/
    list_node start = (list_node)malloc(sizeof(list_node));
    list_node aktuellInWerteListe = start;
    list_node aktuellInListe = head;
    start->next = NULL; // nötig damit am Ende klar ist ob Elemente gefunden wurden oder nicht.

    if(aktuellInListe == NULL) {
        return (list_node)NULL; // Keine Elemente da
    }

    while(aktuellInListe != NULL) {
        if(aktuellInListe->item < a) {
                aktuellInWerteListe->item = aktuellInListe->item;
                aktuellInWerteListe->next =(list_node)malloc(sizeof(list_node));
                aktuellInWerteListe = aktuellInWerteListe->next;
        }

        aktuellInListe = aktuellInListe->next;
    }

    /**
     * Es wird immer eine node zuviel an Speicher reserviert. So spare ich mir ein if in der Schleife
     * und der Code wird lesbarer. Dafür muss ich am Ende diese hässliche Überprüfung machen.
     * Wenn kein Element gefunden wird, wird das eine das am Anfang zu viel reserviert wurde freigegeben
     * und wenn eins oder mehr Elemente gefunden wurden, wird das im Voraus reservierte Element freigegeben.
     */
    if(start->next == NULL) { // es wurden keine Werte gefunden.
        free(start);
        return NULL;
    }
    else {
        free(aktuellInWerteListe->next);
        return start;
    }
}

