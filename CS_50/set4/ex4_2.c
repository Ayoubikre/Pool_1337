#include <stdio.h>

                    // scan data from a file and print them in another one 

int main(int c,char* argv[]) {
    FILE *file;
    FILE *file2;
    char line[10]; // Assuming each line has at most 100 characters
    int count =1;
    // Open the inpute file
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Open the outuput file
    file2 = fopen(argv[2], "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    //get and copy data
    while (fgets(line,sizeof(line),file)!=NULL){
        fprintf(file2,"Line %d: %s",count, line);
        count++;
    }

    // Close the file
    fclose(file);
    fclose(file2);

    return 0;
}


