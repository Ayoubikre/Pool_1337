#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* p(char *t);

int main(){
    printf("give a sentence: ");
    char t1[100];
    scanf("%[^\n]",t1);
    getchar();
        printf(":: %s\n",t1);

    char *t2=p(t1);

    if(t2==NULL){
        printf("their is no palindrom in : %s",t1);
    }else{
    printf("palindrom of %s : %s",t1,t2);
    }

    free(t2);
return 0;
}
char *p(char *t){
    int s=strlen(t);
    int count=0;
    char b[100]= {0};
    int s1=0,s2=0;

    for(int i=0;i<s;i++){
        for(int j=s-1;j>i;j--){

            if(t[i]==t[j]){
                int check=1;
                for(int k1=i,k2=j;k1<=(k1+k2)/2;k1++,k2--){
                    if(t[k1]!=t[k2]){
                        check=0;

                        break;
                    }


                }
                if(check == 1){
                    s1=j-i+1;
                    if(s1>s2){
                        s2=s1;
                        count++;
                        for(int k3=i,k4=0;k3<j+1;k3++,k4++){
                            b[k4]=t[k3];
                            
                        }
                         b[s1] = '\0';  

                    }
                }
            }
        }
    }
    if(count==0){
        return NULL;
    }else{
        char*t2=malloc((s2+1)*sizeof(char));
        strcpy(t2,b);
        return t2;
    }
    
}