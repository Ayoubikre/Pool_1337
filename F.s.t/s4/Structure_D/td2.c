#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct date{
    int jour;
    int mois;
    int an;
}date;

typedef struct etudient{
    char nom[20];
    char cne[20];
    date date_ns;
    char fl[20];
    int s;
    float t[6];
}etu;

typedef struct node{
    etu e;
    struct node *next; 
}node;

node* ajt_D(node *r);
node* ajt_M(node *r,int *c);
node* ajt_F(node *r);

node* del_D(node *r);
node* del_M(node *r,int c);
node* del_F(node *r);

void affichage(node *r);
void affichage2(node *ls4);

int nb_elem(node *r);
int chercher(node *r);

node* s4(node *r,node *ls4);

int main(){


                    // all the bulshit cause we did root inside main 
                        // we could avoid all this if it outside


    node *root=NULL;
    node *l_s4=NULL;
    root=ajt_D(root);       

    // int count=0;
    // root=ajt_M(root,&count);
    
    // root=ajt_F(root);
    
    affichage(root);

    root=del_D(root);

    // root=del_M(root,count);
    
    // root=del_F(root);


    // int c1= nb_elem(root);
    // printf("%d",c1);

    // int c2=chercher(root);
    // printf("%d",c2);

    l_s4=s4(root,l_s4);
    del_D(l_s4);

return 0;
}


node* ajt_D(node *r){
    for(int i=0;i<3;i++){
        node *n=malloc(sizeof(node));

            printf("\ngive name : ");
            scanf("%[^\n]s",n->e.nom);
            getchar();

            // printf("\ngive cne : ");
            // scanf("%[^\n]s",n->e.cne);
            // getchar();

            // printf("\ngive birth date 'j' : ");
            // scanf("%d",&n->e.date_ns.jour);
            // printf("\ngive birth date 'm' : ");
            // scanf("%d",&n->e.date_ns.mois);
            // printf("\ngive birth date 'a' : ");
            // scanf("%d",&n->e.date_ns.an);
            // getchar();

            // printf("\ngive filier : ");
            // scanf("%[^\n]s",n->e.fl);
            // getchar();

            printf("\ngive semseter : ");
            scanf("%d",&n->e.s);
            getchar();

            // for(int j=0;j<6;j++){
            //     printf("\ngive note [%d] : ",j+1);
            //     scanf("%f",&n->e.t[j]);
            // }
            // getchar();
            n->next=NULL;
        
        if(r==NULL){
            r=n;
        }else{
            n->next=r;
            r=n;
        }
    }

    return r;
}

node* ajt_M(node *r,int *c){
    for(int i=0;i<3;i++){
        node *n=malloc(sizeof(node));

            printf("\ngive name : ");
            scanf("%[^\n]s",n->e.nom);
            getchar();

            // printf("\ngive cne : ");
            // scanf("%[^\n]s",n->e.cne);
            // getchar();

            // printf("\ngive birth date 'j' : ");
            // scanf("%d",&n->e.date_ns.jour);
            // printf("\ngive birth date 'm' : ");
            // scanf("%d",&n->e.date_ns.mois);
            // printf("\ngive birth date 'a' : ");
            // scanf("%d",&n->e.date_ns.an);
            // getchar();

            // printf("\ngive filier : ");
            // scanf("%[^\n]s",n->e.fl);
            // getchar();

            printf("\ngive semseter : ");
            scanf("%d",&n->e.s);
            getchar();

            // for(int j=0;j<6;j++){
            //     printf("\ngive note [%d] : ",j+1);
            //     scanf("%f",&n->e.t[j]);
            // }
            // getchar();
            n->next=NULL;
        
        if(r==NULL){
            r=n;
            (*c)++;
        }else{
            node *ptr=r;
            int i=0;
            while ((ptr->next!=NULL)&& i<(*c)/2){
                ptr=ptr->next;
            i++;
            }
            n->next=ptr->next;
            ptr->next=n;
        }
    }

    return r;
}

node* ajt_F(node *r){
    for(int i=0;i<3;i++){
        node *n=malloc(sizeof(node));

            printf("\ngive name : ");
            scanf("%[^\n]s",n->e.nom);
            getchar();

            // printf("\ngive cne : ");
            // scanf("%[^\n]s",n->e.cne);
            // getchar();

            // printf("\ngive birth date 'j' : ");
            // scanf("%d",&n->e.date_ns.jour);
            // printf("\ngive birth date 'm' : ");
            // scanf("%d",&n->e.date_ns.mois);
            // printf("\ngive birth date 'a' : ");
            // scanf("%d",&n->e.date_ns.an);
            // getchar();

            // printf("\ngive filier : ");
            // scanf("%[^\n]s",n->e.fl);
            // getchar();

            printf("\ngive semseter : ");
            scanf("%d",&n->e.s);
            getchar();

            // for(int j=0;j<6;j++){
            //     printf("\ngive note [%d] : ",j+1);
            //     scanf("%f",&n->e.t[j]);
            // }
            // getchar();
            n->next=NULL;
        
        if(r==NULL){
            r=n;
        }else{
            node *ptr=r;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=n;
        }
    }
    return r;
}

void affichage(node *r){
    node*ptr=r;
    while(ptr!=NULL){
        printf("%s\n",ptr->e.nom);
        ptr=ptr->next;
    }
}

void affichage2(node *ls4){
    node*ptr=ls4;
    while(ptr!=NULL){
        printf("%s\n",ptr->e.nom);
        ptr=ptr->next;
    }
}

node* del_D(node *r){
    while(r!=NULL){
        node *tmp=r;
        free(tmp);
        r=r->next;
    }
    return r;
}

node* del_M(node *r,int c){
    
    node *tmp=r;
    while ((tmp->next!=NULL)&& c<(c)/2){
        tmp=tmp->next;
    }

    node *tmp2=r;
    while (tmp2->next!=tmp){
        tmp2=tmp2->next;
    }
    tmp2->next=tmp->next;
    free(tmp);
    return r;
}


node* del_F(node *r){
    while(r!=NULL){
        node *tmp=r;
        free(tmp);
        r=r->next;
    }
    return r;
}

int nb_elem(node *r){
    int count=0;
    node *tmp=r;
    while(tmp!=NULL){
        count++;
        tmp=tmp->next;
    }
    return count;
}

int chercher(node *r){
    node*tmp=r;
    char buffer[100];
    int count=0;
    printf("give a name to search");
    scanf("%s",buffer);
    while(tmp!=NULL){
        if(strcmp(tmp->e.nom,buffer)==0){
            return count;
        }else{
            count++;
            tmp=tmp->next;
        }
    }
    if(tmp==NULL){
        return -1;
    }
}

node* s4(node *r,node *ls4){
    node*tmp=r;
    while (tmp!=NULL){
        if(tmp->e.s==4){
            node *n=malloc(sizeof(node));
            n->e=tmp->e;
            n->next=NULL;
            if(ls4==NULL){
                ls4=n;
            }else{
                n->next=ls4;
                ls4=n;
            }
        }
     tmp=tmp->next;
    }
    return ls4;
}