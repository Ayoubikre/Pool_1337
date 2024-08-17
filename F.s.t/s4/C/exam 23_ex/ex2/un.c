#include<stdio.h>
#include"suit.h"

int Un(int n){
    if(n==1){
        return 2;
    }else{
        return Un(n-1)+Vn(n-1);
    }
}