#include<stdio.h>
#include<stdlib.h>
#include<time.h>

            // creat a blood type family tree "les arbres"

typedef struct node{
    char alts[2];
    struct node *parent[2];
}node;

const int genr=3;        // control the outcome 

node* creat(int gen);
void print(node *p,int gen);
void freeTree(node* root);
char blood();

int main(void){
    srand(time(0));  // function that give random numbers

    node* root=creat(genr);
    if(root==NULL){
        printf("root is null");
        return 1;
    }
    print(root,0);

    freeTree(root);

return 0;
}

node *creat(int gen){
    node *n=malloc(sizeof(node));
    if(gen>1){
        n->parent[0]=creat(gen-1);          //important : recursively 
        n->parent[1]=creat(gen-1);
        n->alts[0]=n->parent[0]->alts[rand()%2];
        n->alts[1]=n->parent[1]->alts[rand()%2];
    }else{
        n->parent[0]=NULL;
        n->parent[1]=NULL;
        n->alts[0]=blood();
        n->alts[1]=blood();
    }
    return n;
}

char blood(){
    int r=rand()%3; // function extension
    if(r==2){
        return 'A';
    }else if(r==1){
        return 'B';
    }else{
        return 'O';
    }
}
void print(node* p,int gen){ //start with generation 0 aka child
    if(p==NULL){
        return;
    }
    if(gen==0){printf("child genration[%d] :%c%c \n",gen,p->alts[0],p->alts[1]);}
    else if(gen==1){printf("\tparent genration[%d] :%c%c \n",gen,p->alts[0],p->alts[1]);}
    else{
        for(int i=0;i<gen;i++){printf("\t");}
        printf("grandparent genration[%d] :%c%c \n",gen,p->alts[0],p->alts[1]);
    }
    print(p->parent[0],gen+1); //print with recursively
    print(p->parent[1],gen+1);

}

void freeTree(node* root) {      //free nodes withe recursively
    if (root == NULL) {
        return;
    }
    // Free the left and right subtrees
    freeTree(root->parent[0]);
    freeTree(root->parent[1]);
    // Free the current node
    free(root);
}








            // cs50 code : 


// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
//                                 // family tree "0 idea"
// typedef struct person
// {
//     struct person *parents[2];
//     char alleles[2];
// } node;

// const int GENERATIONS = 3;
// const int INDENT_LENGTH = 2;

// node *creat(int gen);
// void print(node *root,int gen);
// void free_family(node *p);

// int main(void){
//     srand(time(0));

//     node *root = creat(GENERATIONS);

//     print(root,0);

//     return 0;
// }

// node* creat(int gen){
//     node *n=malloc(sizeof(node));
//     if(gen>1){
//         n->parents[0]=creat(gen-1);
//         n->parents[1]=creat(gen-1);
//         n->alleles[0]=n->parents[0]->alleles[rand()%2];
//         n->alleles[1]=n->parents[1]->alleles[rand()%2];

//     }else{
//         for(int i=0;i<2;i++){
//           int r2= rand()%3;
//             if(r2==2){n->alleles[i]='A';}
//             else if(r2==1){n->alleles[i]='B';}
//             else {n->alleles[i]='O';}
//         }
//         n->parents[0]=NULL;
//         n->parents[1]=NULL;

//     }
//     return n;
// }
// void print(node *n, int generation)
// {
//     // Handle base case
//     if (n == NULL)
//     {
//         return;
//     }

//     // Print indentation
//     for (int i = 0; i < generation *INDENT_LENGTH; i++)
//     {
//         printf("  ");
//     }

//     // Print person
//     if (generation == 0)
//     {
//         printf("Child (Generation %i): blood type %c%c\n", generation, n->alleles[0], n->alleles[1]);
//     }
//     else if (generation == 1)
//     {
//         printf("Parent (Generation %i): blood type %c%c\n", generation, n->alleles[0], n->alleles[1]);
//     }
//     else
//     {
//         for (int i = 0; i < generation - 2; i++)
//         {
//             printf("Great-");
//         }
//         printf("Grandparent (Generation %i): blood type %c%c\n", generation, n->alleles[0], n->alleles[1]);
//     }

//     // Print parents of current generation
//     print(n->parents[0], generation +1);
//     print(n->parents[1], generation +1);
// }
// void free_family(node *p){
//     // Handle base case
//     if (p == NULL)
//     {
//         return;
//     }

//     // Free parents recursively
//     free_family(p->parents[0]);
//     free_family(p->parents[1]);

//     // Free child
//     free(p);
// }
