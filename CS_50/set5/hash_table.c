#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

                // creat a hash table  " dictionary ": 
                         // array of id and each one has an array of linked list

  typedef struct node{          //nodes of linked lists
    char* phrase;
    int number;
    struct node *next;
} node;

typedef struct arr{             // array of id "first letter ascii"
    int id;
    struct node *next;
} arr;

void visual(arr* t,char* buffer);
void store(node *n,arr *t,char c);
int hash(char c);

int main(void){
    arr t[26];
    int s=0;
    char ans;
    char buffer[100];

    for(int i=0;i<26;i++){          //set array
        t[i].id=i;
        t[i].next=NULL;
    }
    do{
        printf("\ngive a phrase : ");
        scanf("%99[^\n]",buffer);
        getchar();
        s=strlen(buffer)+1;

        node *n=malloc(sizeof(node));  // creat a node
            if(n==NULL){
                printf("error to creat a node for %s",buffer);
                return 1;
            }
        n->phrase=malloc(s*sizeof(char));  
            if(n->phrase==NULL){
                printf("error to creat a phrase for %s",buffer);
                return 1;
            }
        strcpy(n->phrase,buffer);

        int num=0;
        printf("give a number : ");
        scanf("%d",&num);
        getchar();
        n->number=num;

        n->next=NULL;

        store(n,t,buffer[0]);  // stor the node in the array

        printf("add a new element ? \'y /n\': ");
        scanf("%c",&ans);
        getchar();
    }while(ans=='y'||ans=='Y');

    do{
        printf("\ngive a key name : ");     // search the dict
        scanf("%99[^\n]",buffer);
        getchar();
        visual(t,buffer);
        printf("search for another key ? \'y /n\': ");
        scanf("%c",&ans);
        getchar();
    }while(ans=='y'||ans=='Y');
    
    for(int i=0;i<26;i++){          // free all allocated mem.
        if(t[i].next==NULL){
            continue;
        }else{
            node*ptr=t[i].next;
            while(ptr!=NULL){
                node*tmp=ptr;
                ptr=ptr->next;
                free(tmp->phrase);
                free(tmp);
            }
        }
    }
    return 0;
}

void store(node *n,arr *t,char c){
    int h=hash(c);              // get the id
    if(t[h].next==NULL){    // if its the first node for the id
        t[h].next=n;
    }else{
        node *tmp=t[h].next;        // if not store it last
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=n;
    }
}

int hash(char c){
    int h=tolower(c)-97;     // get ascci of the letter
    return  h;
}

void visual(arr* t,char* buffer){
    int h=hash(buffer[0]);              // get the id
        if(t[h].next==NULL){           //if the id have no nodes
            printf("no data has been found\n");
            return;
        }
        else{           
            node*tmp=t[h].next;
            if(tmp==NULL){
                printf("error happens");
                return;
            }
            while(tmp->next!=NULL&&(strcmp(tmp->phrase,buffer))){
                tmp=tmp->next;
            }
            if(!strcmp(tmp->phrase,buffer)){
                printf("............................\n");              
                printf("location in array : %d\n",h);
                printf("Pointer of the array : %p\n",t[h]);
                printf("Pointer of the list : %p\n",tmp);
                printf("name : %s\n",tmp->phrase);
                printf("number : %d\n",tmp->number);
                printf("next : %p\n",tmp->next);
                printf("............................\n");              
                return;
            }else{
                printf("no data has been found\n");
                return;
            }
        }
}
