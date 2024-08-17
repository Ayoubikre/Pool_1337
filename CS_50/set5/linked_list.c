#include <stdio.h>
#include <stdlib.h>
#include <string.h>

            // creat 3 linked list :
                    // 1: new data are first
                    // 2: new data are last 
                    // 3: sort list and delete data
                    // 4: the same as 3 but with function + string


typedef struct node {       //list 1/2/3
    int x;
    struct node *next;
} node;

typedef struct node2{         // list 4
    char* phrase;
    struct node2 *next;
} node2;
#define list4_SIZE 2
void visualizer(node2 *list4);


int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Incorrect number of arguments.\n");
        return 1;
    }

                         // list 1:

    node *list=NULL;  // set pointers
    node *ptr=NULL;

    for(int i=1;i<argc;i++){
        if(list==NULL){      // creat the first node
            node *n=malloc(sizeof(node));
            n->x=atoi(argv[i]);
            n->next=NULL;
            list=n;
        }else{               // creat other nodes
            node *n=malloc(sizeof(node));
            n->x=atoi(argv[i]);
            n->next=list;
            list=n;
        }
        ptr=list;
    }
    while(ptr!=NULL){        // print nodes
        printf("%d\n",ptr->x);
        ptr=ptr->next;
    }
    while(list!=NULL){        // free nodes
        node*tmp=list;
        list=list->next;
        free(tmp);
    }

printf("\n");

                         //list 2 :

printf("\n");

    node* list2=NULL; // set pointers
    node* ptr2=NULL;

    for(int i=1;i<argc;i++){
        if(list2==NULL){        // creat the first node
            node*n=malloc(sizeof(node));
            n->x=atoi(argv[i]);
            n->next=NULL;
            list2=n;
            ptr2=list2;
        }else{                  //creat the other nodes
            node*n=malloc(sizeof(node));
            n->x=atoi(argv[i]);
            n->next=NULL;
                while(ptr2->next!=NULL){ //chek the end of the chaine
                    ptr2=ptr2->next;
                }
            ptr2->next=n;
        }
        ptr2=list2;     // reset pointer to the top of the list
    }
    while(ptr2!=NULL){         // print the list
        printf("%d\n",ptr2->x);
        ptr2=ptr2->next;
    }
    while(list2!=NULL){        // free the list
        node*tmp=list2;
        list2=list2->next;
        free(tmp);
    }

printf("\n");

                         //list 3 :

printf("\n");

    node* list3=NULL;           //set pointers
    node* ptr3=NULL;

    for(int i=1;i<argc;i++){
        if(list3==NULL){        //creat the first node
            node*n=malloc(sizeof(node));
            n->x=atoi(argv[i]);
            n->next=NULL;
            list3=n;
        }else{                  //creat the other nodes
            node*n=malloc(sizeof(node));
            n->x=atoi(argv[i]);
            n->next=NULL;
                while((ptr3->next!=NULL)&&((ptr3->next->x)<=(n->x))){
                    // Imp : check the null cond. always befor the comparison to not get a core dump 
                    ptr3=ptr3->next;
                }
            n->next=ptr3->next;
            ptr3->next=n;
        }
        ptr3=list3;            //rest poniter
    }

    while(ptr3!=NULL){        //print list
        printf("%d\n",ptr3->x);
        ptr3=ptr3->next;
    }
    
                            //delete a node from the list
    int num;
    printf("give a number to delet : ");
    scanf(" %d",&num); 
    getchar();
    ptr3=list3;

    if(list3==NULL){               //check if the list empty
        printf("list is empty");
    }
    else if(ptr3->x==num){       //check the head of the list
        node*tmp=list3;
        list3=list3->next;
        free(tmp);
    }else{                  //check the other nodes 
        while(ptr3->next!=NULL && ptr3->next->x!=num){
            ptr3=ptr3->next;
        }
        if(ptr3->next==NULL){
            printf("the number you give do not exist in the list \n");
        }else{
            node*tmpp=ptr3->next;
            ptr3->next=tmpp->next;
            free(tmpp);
        }
    }

    while(list3!=NULL){       //free list
        node*tmp=list3;
        list3=list3->next;
        free(tmp);
    }

printf("\n");

                         //list 4 :

printf("\n");

    node2*list4=NULL;
    char t[100];

    for(int i=0;i<list4_SIZE;i++){      //creat list
        node2*n=malloc(sizeof(node2));

            printf("give a name : ");
            scanf("%99[^\n]",t);
            getchar();
            int s=strlen(t)+1;

        n->phrase=malloc(s*sizeof(char)); //creat string mem
        strcpy(n->phrase,t);  //cpy

            if(list4==NULL){               
                n->next=NULL;
                list4=n;
            }else{
                n->next=list4;
                list4=n;
            }
    }
    visualizer(list4);

    while(list4!=NULL){
        node2*tmp=list4;
        list4=list4->next;
        free(tmp->phrase);
        free(tmp);
    }

    return 0;
}

void visualizer(node2*list4){
    printf("\n<......... list4 .........>\n");
        node2*ptr4=list4;
        while(ptr4!=NULL){
            printf(" %s",ptr4->phrase);
            ptr4=ptr4->next;
        }
    printf("\n<.........,..............>\n");
}



