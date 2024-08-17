#include <stdio.h>
#include <stdbool.h>

// desing a tringle


int main(void){

	int x=0;
	do{
		printf("give the hight");
		scanf("%d",&x);
		while(getchar()!= '\n');
	}while(x<1 || x>8 );

	for(int i=0 ;i<x;i++){

		//creat the first tringle
		for(int j=x;j>i;j-- ){
			printf(" ");
		}
		for(int j=0;j<=i;j++){
			printf("#");
		}

		// space
		printf(" ");

		// creat te second tringle 
		for (int j=0;j<=i;j++){
			printf("#");
		}

		// new line
		printf("\n");
	}

}



