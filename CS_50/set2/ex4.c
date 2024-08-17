#include <stdio.h>
#include <string.h>

// replace all the voyel to a number


char* replace(int size, char t[size]);

int main(int argc, char* argv[]){
    if (argc!=2){
        printf("the usage : ./t key ");
    }else{
        char* rs;
        int s=strlen(argv[1]);
        rs=replace(s,argv[1]);
        printf("the result are : %s",rs);
    }
return 0;
}

// replace all the voyel to another cahr and return it to main 

char* replace(int size , char t[size]){
    for(int i=0;i<size;i++){
             if(t[i]=='a'){t[i]='6';}
        else if(t[i]=='e'){t[i]='3';}
        else if(t[i]=='i'){t[i]='1';}
        else if(t[i]=='o'){t[i]='0';}
    }
    
return t;
}



