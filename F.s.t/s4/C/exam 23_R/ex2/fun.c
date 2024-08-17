#include<stdio.h>
#include"fun.h"

int u(int n){
    if(n==0){
        int rs=1;
        return rs;
    }else{
        return u(n-1)+v(n-1);
    }

}


int v(int n){
    if(n==0){
        int rs=0;
        return rs;
    }else{
        return 2*u(n-1)+v(n-1);
    }
}
