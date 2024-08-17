#include<stdio.h>
#include<math.h>

// bank card check

int main(void){    
    //check the number from any other charcter 
    long long x=0,t=0;
        do{
        t=0;
        printf("give a card number : ");
        scanf("%lld",&x);
        while(getchar() != '\n'){
            t=1;
        }
        }while(x<=0 || t==1);
    long long x1=x;

    //check the formula to validate the bank-card 
    int r1=0,r2=0,r3=0;
    int add=0, mult=0;
    while(x>1){

        r1=x%10; x=x/10;
        r2=x%10; x=x/10;

        if((r2*2)>10){
            r3=((r2*2)%10)+(r2*2/10);
            add+=r1; mult+=r3;          
        }else{
            add+=r1; mult+=r2*2;
        }
    }
    int result=add+mult;
    if(result%10==0){
        printf(" the card is valid\n");
    }else{
        printf("the card is invalide\n");
    }

    //check the card mark
    if(x1>=5100000000000000 && x1<5600000000000000){
        printf("your card is a mastercard");

    }else if((x1>=4000000000000000 && x1<5000000000000000)||(x1>=4000000000000 && x1<5000000000000)){
        printf("your card is a visa");

    }else if((x1>=340000000000000 && x1<350000000000000)||(x1>=370000000000000 && x1<380000000000000)){
        printf("your card is a American express");
    }else {
        printf("your card is a unkowne");
    }
return 0;

}