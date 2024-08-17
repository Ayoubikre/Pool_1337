#include <stdio.h>
#include <string.h>
#include <stdlib.h>

                    // scan data from a file and print them  using 
                                     // MALLOC

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];
    char* plates[8];
    // Allocate memory for each plate number
    for (int i = 0; i < 8; i++) {
        plates[i] = malloc(7 * sizeof(char));
            if (plates[i] == NULL) {
                printf("Memory allocation failed.\n");

                // Free allocated memory before returning
                for (int j = 0; j < i; j++) {
                    free(plates[j]);
                }
                return 1;
            }
    }

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7) // cpy data
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // Save plate number in array
        strcpy(plates[idx], buffer);
        idx++;
    }

    for (int i = 0; i < 8; i++)     // print data
    {
        printf("%s\n", plates[i]);
    }

for (int i = 0; i < 8; i++) {
    free(plates[i]);
}
fclose(infile);
return 0;
}
