#include <stdio.h>
#include <stdlib.h>

            // creat  double linked list :

typedef struct node {
    struct node *prev;
    int x;
    struct node *next;
} node;

node*list=NULL;
node*ptr=NULL;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Incorrect number of arguments.\n");
        return 1;
    }
    for(int i=1;i<argc;i++){
        if(list==NULL){
            node*n =malloc(sizeof(node));
            n->prev=NULL;
            n->x=atoi(argv[i]);
            n->next=NULL;
            list=n;
            ptr=list;
        }else{
            node*n =malloc(sizeof(node));
            n->prev=NULL;
            n->x=atoi(argv[i]);
            n->next=list;
            list->prev=n;
            list=n;
        }
     }

     while(ptr!=NULL){
        printf("%d\n",ptr->x);
        ptr=ptr->prev;
     }
     
     while(list!=NULL){
        node*tmp=list;
        list=list->next;
        free(tmp);
     }
}
    