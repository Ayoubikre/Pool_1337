#include <stdio.h>
#include <stdint.h>
#include<string.h>

                // recovery file.  { befor running creat a folder named "ti" to store results}

int main(int argc,char*argv[]){
    if(argc!=2){
        printf("the usage : ./t recovery_card");
        return 0;
    }
    FILE* f1_r=fopen(argv[1],"rb");
    if(f1_r==NULL){
        printf("error in opening the card");
        return 1;
    }

    uint8_t t[512];
    int count = 0;
    FILE* f2_w = NULL;

    while (fread(t, 1, 512, f1_r) == 512){// recover
        if (t[0] == 0xff && t[1] == 0xd8 && t[2] == 0xff && (t[3] & 0xf0) == 0xe0) {
                if (f2_w != NULL) {
                    fclose(f2_w);
                }
            char name[15];
            sprintf(name,"ti/%03d.jpg",count++);
            f2_w=fopen(name,"wb");
                if (f2_w == NULL) {
                    printf("Error opening file for writing.\n");
                    return 1;
                }
        }
        if (f2_w != NULL) {
            fwrite(t,1,512,f2_w);
        } 
    }

    fclose(f2_w);
    fclose(f1_r);
    printf("all data has been sucsufly recoverd");
    return 0;
}



