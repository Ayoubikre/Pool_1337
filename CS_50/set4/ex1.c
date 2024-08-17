// fseek(f_r, sizeof(c), SEEK_SET);

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

                //change the sound lvl of an audio

int main(int argc, char* argv[]){
    if (argc != 4){
        printf("the usage is : ./ex1 v/input.wav i2.wav N.\n");
        return 1;
    }
    FILE* f_r=fopen(argv[1],"rb"); //open the org file
    if(f_r==NULL){
        printf("file has not ben found\n");
        return 1;
    }
    else{
        FILE* f_w=fopen(argv[2],"w"); // creat the copy 
            if(f_w==NULL){
                printf("the cpy has not been created \n");
                return 1;
            }
        uint8_t c[44]; //cpy the header
        fread(c,sizeof(uint8_t),sizeof(c),f_r);
        fwrite(c,sizeof(uint8_t),sizeof(c),f_w);
        fclose(f_w);

        // reopen the copy with difftent mode : apand
        FILE* f2_w=fopen(argv[2],"ab"); 
            if(f2_w==NULL){
                printf("the cpy has not been found \n");
                return 1;
            }
        uint16_t a[2];
        float b =atof(argv[3]);
            if(b<=0){
                printf("enter a number bigger than 0\n");
                return 1;
            }
        size_t i;
        while((i=fread(a,sizeof(uint16_t),sizeof(a),f_r))>1){
                for(int j=0;j<2;j++){  //change the volume
                    a[j]*=b;
                }
            fwrite(a,sizeof(uint16_t),i,f2_w);
        }

        fclose(f2_w);
    }
    fclose(f_r);
    return 0;
}


