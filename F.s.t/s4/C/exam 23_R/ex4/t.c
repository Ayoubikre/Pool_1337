#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
char * jour();

int main(){
    char t[20];
    strcpy(t,jour());
    printf("the day is : %s",t);

return 0;
}
char * jour(){
   srand(time(0));

   int x=rand()%7;

   switch (x){
    case 0:
        return "lundi";
        break;
    case 1:
        return "mardi";
        break;
    case 2:
        return "mercredi";
        break;
    case 3:
        return "jeudi";
        break;
    case 4:
        return "vendredi";
        break;
    case 5:
        return "samdi";
        break;
    case 6:
        return "dimanech";
        break;
   }
}
