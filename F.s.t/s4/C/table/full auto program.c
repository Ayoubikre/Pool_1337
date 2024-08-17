// Online C compiler to run C program online
#include <stdio.h>
    int s,n ,temp,nd;
    char ch1,ch2,ch3,ch4;


/*int size(int s){

    do{
        printf("\n1/ Give the size of the table : ");
        scanf(" %d",&s);
    }while(s<=0);
           
           return s;
}*/

int main() {

    size(s);
    
do{         

        do{
            printf("\n1/ Give the size of the table : ");
            scanf("%d",&s);
        }while(s<=0);

            
int t[s];
        for(int i=0;i<s;i++){
            printf("\n\t\t remplir cas number %d :\t",i+1);
            scanf("%d",&n);
            t[i]=n;
        }
     do{
            do{ ch1='x';
                printf("\n\n 2/ Do you want to add a new number, if Yes type \"Y\" if No type \"N\" :\t");
                scanf(" %c",&ch1);
            }while(ch1!='y'&&ch1!='n');
            
            if(ch1=='y'){
                printf("\n\t\t remplire the new cas :\t");
                s=s+1;
                scanf("%d",&t[s-1]);
            }
            printf(" \n\t\t here the new table data : ");
            for(int i=0;i<s;i++){
                    printf("%d| ",t[i]);
            }

    }while(ch1=='y');
        
    do{
            do{
                     printf("\n\n 3/ Do you want to delet a number from the table, if Yes type \"Y\" if No type \"N\" :\t");
                     scanf(" %c",&ch2);
            }while(ch2!='y'&&ch2!='n');
            
            if(ch2=='y'){
                printf("\n\t\there is the curent table data : ");
                         for(int i=0;i<s;i++){
                                  printf(" %d ",t[i]);
                         }
                printf("\n\t\tchoose the number you want to delet : ");
                scanf("%d",&nd);
                    for(int i=0;i<s;i++){
                        if(nd==t[i]){
                            t[i]=t[s-1];
                            s-=1;
                        }
                    }
                printf(" \n\t\t here the new table data : ");
                         for(int i=0;i<s;i++){
                                  printf("%d| ",t[i]);
                         }

            }
    }while(ch2=='y');
        
    do{
                printf("\n 4/ do you want the tabel to be sorted in ascending or descending order ");
                printf("\n\n\t\ttype \"A\" or \"D\" to select the sort type : ");
                scanf(" %c",&ch3);
    }while(ch3!='a'&&ch3!='d');
        
                if(ch3=='a'){
                    for(int i=0;i<s;i++){
                        for(int j=1;j<s-i;j++){
                            if(t[j]<t[j-1]){
                                 temp=t[j-1];
                                 t[j-1]=t[j];
                                 t[j]=temp;
                             }
                         }
                     }
                }else{
                    for(int i=0;i<s;i++){
                        for(int j=0;j<s-i;j++){
                            if(t[j]>t[j-1]){
                                temp=t[j-1];
                                t[j-1]=t[j];
                                t[j]=temp;
                            }
                        }
                     }
                 }
                 
         printf("\n\t\t full sorted table data : \t");
         for(int i=0;i<s;i++){
                  printf("%d| ",t[i]);
         }

    do{ 
        printf("\n5/ Do you wnat to creat a new table ?");
        printf("\n\n\t\t if Yes type \"Y\" , if No than type \"N\"");
        scanf(" %c",&ch4);
    }while(ch4!='y'&&ch4!='n');

}while(ch4=='y'); 
        return 0;
}