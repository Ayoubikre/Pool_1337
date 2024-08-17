#include<stdio.h>
#include<string.h>

// creating a snack menu and calcutta the total price of the items

                          // recursive

typedef struct {
    char item[20];
    float prix;
}menu;
menu t[10];

int n=0,k=0,c_item=0 ;
float p_item=0 ,prix=0, add=0;
void creat_menu();
int ch_menu();
int cost();

int main(){
    printf("Welcome to Beach Burger Shack!\n"
            "Choose from the following menu to order. Press enter when done.\n\n"
            "\tBurger: $9.50\n"
            "\tVegan Burger: $11.00\n"
            "\tHot Dog: $5.00\n"
            "\tCheese Dog: $7.00\n"
            "\tFries: $5.00\n"
            "\tcheese Fries: $6.00\n"
            "\tCold Pressed Juice : $7.00\n"
            "\tCold Brew: $3.00\n"
            "\tWater: $2.00\n"
            "\tSoda: $2.00\n"
        );
        creat_menu();
        prix=ch_menu();
        printf("the prix of the items is : $ %f",prix);


return 0;
}
void creat_menu(){
    strcpy(t[0].item, "Burger"); t[0].prix=9.5;
    strcpy(t[1].item, "Vegan Burger"); t[1].prix=11.0;
    strcpy(t[2].item, "Hot Dog"); t[2].prix=5.0;
    strcpy(t[3].item, "Cheese Dog"); t[3].prix=7.0;
    strcpy(t[4].item, "Fries"); t[4].prix=5.0;
    strcpy(t[5].item, "cheese Fries"); t[5].prix=6.0;
    strcpy(t[6].item, "Cold Pressed Juice"); t[6].prix=7.0;
    strcpy(t[7].item, "Cold Brew"); t[7].prix=3.0;
    strcpy(t[8].item, "Water"); t[8].prix=2.0;
    strcpy(t[9].item, "Soda"); t[9].prix=2.0;
}

int ch_menu(){
    char test[20];
    printf("Enter a food item:\n");
    scanf("%19[^\n]",test);
    int s=strlen(test);
    getchar();
    int ch_items=0;
        for(int i=0;i<10;i++){
            if(!strcmp(test,t[i].item)){
                ch_items=1;
                k=i;
                break;
            }
        }
        if(s<2){
                return p_item;
        }else{
            if(ch_items==1){
                p_item=p_item+cost(k);
                ch_menu();
            }else{
                printf("the item does not exist\n");
                ch_menu();
            }
        }
}

int cost(int a){
     add=t[a].prix;
return add;
}

