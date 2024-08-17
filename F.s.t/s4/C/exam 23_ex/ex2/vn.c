#include<stdio.h>
#include "suit.h"

int Vn(int n){
    if(n==1){
        return 1;
    }else{
        return Un(n-1)-Vn(n-1);
    }
}