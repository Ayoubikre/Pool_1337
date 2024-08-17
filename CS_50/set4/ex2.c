#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
                        // filter images to different mode : blur , gray , revers , .......
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t  i32;

typedef struct{
    u16   bfType;
    u32  bfSize;
    u16   bfReserved1;
    u16   bfReserved2;
    u32  bfOffBits;
} __attribute__((__packed__))
BITMAP_FILE_HEADER;

typedef struct{
    u32  biSize;
    i32   biWidth;
    i32   biHeight;
    u16   biPlanes;
    u16   biBitCount;
    u32  biCompression;
    u32  biSizeImage;
    i32   biXPelsPerMeter;
    i32   biYPelsPerMeter;
    u32  biClrUsed;
    u32  biClrImportant;
} __attribute__((__packed__))
BITMAP_INFO_HEADER;

typedef struct{
    u8  rgbtBlue;
    u8  rgbtGreen;
    u8  rgbtRed;
} __attribute__((__packed__))
RGB_TRIPLE;

void gray(int h, int w, RGB_TRIPLE t[h][w]);
void sepia(int h, int w, RGB_TRIPLE t[h][w]);
void reflect(int h, int w, RGB_TRIPLE t[h][w]);
int blur(int h, int w, RGB_TRIPLE t[h][w]);
int check(int argc ,char*argv[]);

int main(int argc,char*argv[]){
    int rs=check(argc,argv);
    if(rs==1){
        return 1;
    }else{ 
            printf("all good\n");

        FILE* f1_r=fopen(argv[2],"r");          // open the image
            if(f1_r==NULL){
                printf("the file had not been found");
                return 1;
            }
        FILE* f2_w=fopen(argv[3],"w");          // creat the modified image
            if(f2_w==NULL){
                printf("the file had not been found");
                return 1;
            }
        BITMAP_FILE_HEADER b1_f;
        fread(&b1_f,sizeof(BITMAP_FILE_HEADER),1,f1_r);   //copy headers
        BITMAP_INFO_HEADER b1_i;
        fread(&b1_i,sizeof(BITMAP_INFO_HEADER),1,f1_r);

        // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
        if (b1_f.bfType != 0x4d42 || b1_f.bfOffBits != 54 || b1_i.biSize != 40 ||
            b1_i.biBitCount != 24 || b1_i.biCompression != 0){
            fclose(f1_r);
            fclose(f2_w);
            printf("Unsupported file format.\n");
            return 6;
        }

        int h=abs(b1_i.biHeight);
        int w=abs(b1_i.biWidth);

        RGB_TRIPLE (*t)[w]=calloc(h,w * sizeof(RGB_TRIPLE));    // copy data
            if (t==NULL){
                fclose(f1_r);
                fclose(f2_w);
                printf("memory alloctaion has failed\n");
                return 1;
            }
        int padding = (4 - (w * sizeof(RGB_TRIPLE)) % 4)%4;

        for (int i = 0; i < h; i++){
            fread(t[i], sizeof(RGB_TRIPLE), w, f1_r);

            // Skip over padding " in this case =0 "
            fseek(f1_r, padding, SEEK_CUR);
        }

        if    (argv[1][1]=='g'){                                  // uplay the filters
            gray(h,w,t);
        }else if(argv[1][1]=='s'){ 
            sepia(h,w,t);
        }else if(argv[1][1]=='r'){ 
            reflect(h,w,t);
        }else if(argv[1][1]=='b'){  
            blur(h,w,t);
        }

        fwrite(&b1_f,sizeof(BITMAP_FILE_HEADER),1,f2_w);           // copy the modified data to the new image
        fwrite(&b1_i,sizeof(BITMAP_INFO_HEADER),1,f2_w);

        for (int i = 0; i < h; i++){
            fwrite(t[i],sizeof(RGB_TRIPLE),w,f2_w);
            // Skip over padding " in this case =0 "
            for (int k = 0; k < padding; k++){
                fputc(0x00, f2_w);
            }
        }

        free(t);
        fclose(f2_w);
        fclose(f1_r);               // end
    }
}


int check(int argc ,char*argv[]){   // check ipute
    if(argc!=4){
        printf("usage : ./t [flag : - g/s/r/b/n] i1.bmb i2.bmb\n");
        return 1;
    }
    if(strlen(argv[1])==2){
        if(argv[1][0]!='-' || (argv[1][1]!='n' && argv[1][1]!='g' && argv[1][1]!='s' && argv[1][1]!='r' && argv[1][1]!='b' )){
            printf("enter the correct flag to select the themes\n");
            return 1;
        }
    }else{
        printf("inter the correct format of the flage : -s/g/r/b/n \n");
        return 1;
    }

    int s1=strlen(argv[2])+1;
    for(int i=0;i<s1;i++){
        if(argv[2][i]=='.'){
            int s=s1-i;
            char a[s1-i];
            for(int j=i+1, k=0 ;j<s1&&k<s;j++,k++){
                a[k]=argv[2][j];
            }
            a[s]='\0';
            if(!strcmp(a,"bmp")){
                break;
            }else{
                printf("pls give a .bmp type for the 1 image\n");
                return 1;
            }
        }
    }
    int s2=strlen(argv[3])+1;
    for(int i=0;i<s2;i++){
        if(argv[3][i]=='.'){
            int s=s2-i;
            char a[s2-i];
            for(int j=i+1, k=0 ;j<s2&&k<s;j++,k++){
                a[k]=argv[3][j];
            }
            a[s]='\0';
            if(!strcmp(a,"bmp")){
                break;
            }else{
                printf("pls give a .bmp type for the 2 image\n");
                return 1;
            }
        }
    }
}                                           
                                 // filters : 
        
void gray(int h,int w,RGB_TRIPLE t[h][w]){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            float r=t[i][j].rgbtRed;
            float b=t[i][j].rgbtBlue;
            float g=t[i][j].rgbtGreen;
            int average=(r+g+b)/3;
            t[i][j].rgbtRed  =average;
            t[i][j].rgbtBlue =average;
            t[i][j].rgbtGreen=average;
        }
    }
}
void sepia(int h,int w,RGB_TRIPLE t[h][w]){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            float r=t[i][j].rgbtRed;
            float b=t[i][j].rgbtBlue;
            float g=t[i][j].rgbtGreen;

            int sr = .393*r + .769*b + .189*g;
            int sb = .272*r + .534*b + .131*g;
            int sg = .393*r + .686*b + .168*g;

                if(sr>255){sr=255;}
                if(sb>255){sb=255;}
                if(sg>255){sg=255;}

            t[i][j].rgbtRed  =sr;
            t[i][j].rgbtBlue =sb;
            t[i][j].rgbtGreen=sg;
        }
    }
}
void reflect(int h,int w,RGB_TRIPLE t[h][w]){
    RGB_TRIPLE tmp;
    for(int i=0;i<h;i++){
        for(int j=0;j<w/2;j++){
            for(int k=w-j-1;k>w/2;k--){
                tmp=t[i][k];
                t[i][k]=t[i][j];
                t[i][j]=tmp;
                break;
            }
        }
    }
}
int blur(int h,int w,RGB_TRIPLE t[h][w]){
    RGB_TRIPLE (*t2)[w]=calloc(h,w*sizeof(RGB_TRIPLE));
    if(t2==NULL){
        printf("the blur filter cant start");
        return 1;
    }
    
    for(int i=1;i<h-1;i++){
        for(int j=1;j<w-1;j++){
            int row1_r=( t[i-1][j-1].rgbtRed + t[i-1][j].rgbtRed+ t[i-1][j+1].rgbtRed )/3;
            int row2_r=(  t[i][j-1].rgbtRed  +  t[i][j].rgbtRed + t[i][j+1].rgbtRed  )/3;
            int row3_r=( t[i+1][j-1].rgbtRed + t[i+1][j].rgbtRed+ t[i+1][j+1].rgbtRed )/3;

            int row1_b=( t[i-1][j-1].rgbtBlue + t[i-1][j].rgbtBlue+ t[i-1][j+1].rgbtBlue )/3;
            int row2_b=(  t[i][j-1].rgbtBlue  +  t[i][j].rgbtBlue + t[i][j+1].rgbtBlue   )/3;
            int row3_b=( t[i+1][j-1].rgbtBlue + t[i+1][j].rgbtBlue+ t[i+1][j+1].rgbtBlue )/3;

            int row1_g=( t[i-1][j-1].rgbtGreen + t[i-1][j].rgbtGreen+ t[i-1][j+1].rgbtGreen )/3;
            int row2_g=(  t[i][j-1].rgbtGreen  +  t[i][j].rgbtGreen + t[i][j+1].rgbtGreen   )/3;
            int row3_g=( t[i+1][j-1].rgbtGreen + t[i+1][j].rgbtGreen+ t[i+1][j+1].rgbtGreen )/3;

            int average_r =(row1_r+row2_r+row3_r)/3;
            int average_b =(row1_b+row2_b+row3_b)/3;
            int average_g =(row1_g+row2_g+row3_g)/3;

            t2[i][j].rgbtRed=average_r;
            t2[i][j].rgbtBlue=average_b;
            t2[i][j].rgbtGreen=average_g;
        }
    }

    for(int i=0;i<h;i++){
        for(int j=1;j<w-1;j++){
            int top_row1_r=(  t[i][j-1].rgbtRed  +  t[i][j].rgbtRed + t[i][j+1].rgbtRed   )/3;
            int top_row2_r=( t[i+1][j-1].rgbtRed + t[i+1][j].rgbtRed+ t[i+1][j+1].rgbtRed)/3;

            int top_row1_b=(  t[i][j-1].rgbtRed  +  t[i][j].rgbtRed + t[i][j+1].rgbtRed   )/3;
            int top_row2_b=( t[i+1][j-1].rgbtRed + t[i+1][j].rgbtRed+ t[i+1][j+1].rgbtRed)/3;

            int top_row1_g=(  t[i][j-1].rgbtRed  +  t[i][j].rgbtRed + t[i][j+1].rgbtRed   )/3;
            int top_row2_g=( t[i+1][j-1].rgbtRed + t[i+1][j].rgbtRed+ t[i+1][j+1].rgbtRed)/3;

            int bot_row1_r=( t[h-2][j-1].rgbtRed + t[h-2][j].rgbtRed + t[h-2][j+1].rgbtRed )/3;
            int bot_row2_r=( t[h-1][j-1].rgbtRed + t[h-1][j].rgbtRed + t[h-1][j+1].rgbtRed )/3;

            int bot_row1_b=( t[h-2][j-1].rgbtRed + t[h-2][j].rgbtRed + t[h-2][j+1].rgbtRed )/3;
            int bot_row2_b=( t[h-1][j-1].rgbtRed + t[h-1][j].rgbtRed + t[h-1][j+1].rgbtRed )/3;

            int bot_row1_g=( t[h-2][j-1].rgbtRed + t[h-2][j].rgbtRed + t[h-2][j+1].rgbtRed )/3;
            int bot_row2_g=( t[h-1][j-1].rgbtRed + t[h-1][j].rgbtRed + t[h-1][j+1].rgbtRed )/3;

            int average1_r =(top_row1_r+top_row2_r)/2;
            int average1_b =(top_row1_b+top_row2_b)/2;
            int average1_g =(top_row1_g+top_row2_g)/2;

            int average2_r =(bot_row1_r+bot_row1_r)/2;
            int average2_b =(bot_row1_b+bot_row2_b)/2;
            int average2_g =(bot_row1_g+bot_row2_g)/2;

            t2[i][j].rgbtRed=average1_r;
            t2[i][j].rgbtBlue=average1_b;
            t2[i][j].rgbtGreen=average1_g;

            t2[h-1][j].rgbtRed=average2_r;
            t2[h-1][j].rgbtBlue=average2_b;
            t2[h-1][j].rgbtGreen=average2_g;
        }
        break;
    }
    for(int i=1;i<h-1;i++){
        for(int j=0;j<w;j++){
            int left_row1_r=(  t[i-1][j].rgbtRed  +  t[i][j].rgbtRed  +  t[i+1][j].rgbtRed  )/3;
            int left_row2_r=( t[i-1][j+1].rgbtRed + t[i][j+1].rgbtRed + t[i+1][j+1].rgbtRed )/3;

            int left_row1_b=(  t[i-1][j].rgbtBlue  +  t[i][j].rgbtBlue  +  t[i+1][j].rgbtBlue  )/3;
            int left_row2_b=( t[i-1][j+1].rgbtBlue + t[i][j+1].rgbtBlue + t[i+1][j+1].rgbtBlue )/3;

            int left_row1_g=(  t[i-1][j].rgbtGreen + t[i][j].rgbtGreen  +  t[i+1][j].rgbtGreen )/3;
            int left_row2_g=( t[i-1][j+1].rgbtGreen+ t[i][j+1].rgbtGreen + t[i+1][j+1].rgbtGreen)/3;

            int right_row1_r=(t[i-1][w-1].rgbtRed + t[i][w-1].rgbtRed + t[i+1][w-1].rgbtRed )/3;
            int right_row2_r=(t[i-1][w-2].rgbtRed + t[i][w-2].rgbtRed + t[i+1][w-2].rgbtRed )/3;

            int right_row1_b=(t[i-1][w-1].rgbtBlue + t[i][w-1].rgbtBlue + t[i+1][w-1].rgbtBlue )/3;
            int right_row2_b=(t[i-1][w-2].rgbtBlue + t[i][w-2].rgbtBlue + t[i+1][w-2].rgbtBlue )/3;

            int right_row1_g=(t[i-1][w-1].rgbtGreen +t[i][w-1].rgbtGreen +t[i+1][w-1].rgbtGreen )/3;
            int right_row2_g=(t[i-1][w-2].rgbtGreen +t[i][w-2].rgbtGreen +t[i+1][w-2].rgbtGreen )/3;
            
            int average1_r =(left_row1_r+left_row2_r)/2;
            int average1_b =(left_row1_b+left_row2_b)/2;
            int average1_g =(left_row1_g+left_row2_g)/2;

            int average2_r =(right_row1_r+right_row1_r)/2;
            int average2_b =(right_row1_b+right_row2_b)/2;
            int average2_g =(right_row1_g+right_row2_g)/2;

            t2[i][j].rgbtRed=average1_r;
            t2[i][j].rgbtBlue=average1_b;
            t2[i][j].rgbtGreen=average1_g;

            t2[i][w-1].rgbtRed=average1_r;
            t2[i][w-1].rgbtBlue=average1_b;
            t2[i][w-1].rgbtGreen=average1_g;

        break;
        }
    }
    //
    t2[0][0].rgbtRed=(t[0][0].rgbtRed+t[0][1].rgbtRed+t[1][0].rgbtRed+t[1][1].rgbtRed)/4;
    t2[0][0].rgbtBlue=(t[0][0].rgbtBlue+t[0][1].rgbtBlue+t[1][0].rgbtBlue+t[1][1].rgbtBlue)/4;
    t2[0][0].rgbtGreen=(t[0][0].rgbtGreen+t[0][1].rgbtGreen+t[1][0].rgbtGreen+t[1][1].rgbtGreen)/4;

    t2[0][w-1].rgbtRed=(t[0][w-1].rgbtRed+t[0][w-2].rgbtRed+t[1][w-1].rgbtRed+t[1][w-2].rgbtRed)/4;
    t2[0][w-1].rgbtBlue=(t[0][w-1].rgbtBlue+t[0][w-2].rgbtBlue+t[1][w-1].rgbtBlue+t[1][w-2].rgbtBlue)/4;
    t2[0][w-1].rgbtGreen=(t[0][w-1].rgbtGreen+t[0][w-2].rgbtGreen+t[1][w-1].rgbtGreen+t[1][w-2].rgbtGreen)/4;

    t2[h-1][0].rgbtRed=(t[h-1][0].rgbtRed+t[h-1][1].rgbtRed+t[h-2][0].rgbtRed+t[h-2][1].rgbtRed)/4;
    t2[h-1][0].rgbtBlue=(t[h-1][0].rgbtBlue+t[h-1][1].rgbtBlue+t[h-2][0].rgbtBlue+t[h-2][1].rgbtBlue)/4;
    t2[h-1][0].rgbtGreen=(t[h-1][0].rgbtGreen+t[h-1][1].rgbtGreen+t[h-2][0].rgbtGreen+t[h-2][1].rgbtGreen)/4;

    t2[h-1][w-1].rgbtRed=(t2[h-1][w-1].rgbtRed+t[h-1][w-2].rgbtRed+t[h-2][w-1].rgbtRed+t[h-2][w-2].rgbtRed)/4;
    t2[h-1][w-1].rgbtBlue=(t2[h-1][w-1].rgbtBlue+t[h-1][w-2].rgbtBlue+t[h-2][w-1].rgbtBlue+t[h-2][w-2].rgbtBlue)/4;
    t2[h-1][w-1].rgbtGreen=(t2[h-1][w-1].rgbtGreen+t[h-1][w-2].rgbtGreen+t[h-2][w-1].rgbtGreen+t[h-2][w-2].rgbtGreen)/4;

    for (int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            t[i][j].rgbtRed=t2[i][j].rgbtRed;
            t[i][j].rgbtBlue=t2[i][j].rgbtBlue;
            t[i][j].rgbtGreen=t2[i][j].rgbtGreen;
        }
    }


    
}
