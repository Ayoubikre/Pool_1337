#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ft_rrange(int start, int end)
{
    int i;
    int k;
    int e = end;

    if(start >= end)
        k = start -end +1;
    else   
        k = end - start +1;

    int *t=malloc(k * sizeof(int));
    if (t == NULL)
        return 0;

    if(start >= end)
    {
        i =0;
        while(i<k)
        {
            t[i]=e;
            e++;
            i++;
        }
    }else{
        i =0;
        while(i<k)
        {
            t[i]=e;
            e--;
            i++;
        }
    }
    return t;
}


int *ft_rrange(int start, int end) {
    int i;
    int k;
    int *t;
    
    // Calculate the number of elements needed
    if (start >= end) {
        k = start - end + 1;
    } else {
        k = end - start + 1;
    }

    // Handle edge case where k is zero or negative
    if (k <= 0) {
        return NULL;  // No valid range
    }

    // Allocate memory for the array
    t = (int *)malloc(k * sizeof(int));
    if (t == NULL) {
        return NULL;  // Return NULL on allocation failure
    }

    // Populate the array
    if (start >= end) {
        // Fill the array in descending order
        for (i = 0; i < k; i++) {
            t[i] = start - i;
        }
    } else {
        // Fill the array in ascending order
        for (i = 0; i < k; i++) {
            t[i] = end - i;
        }
    }

    return t;
}






void run_test(int start, int end, int *expected_output, int expected_size) {
    int *result = ft_rrange(start, end);
    int pass = 1;

    for (int i = 0; i < expected_size; i++) {
        if (result[i] != expected_output[i]) {
            pass = 0;
            break;
        }
    }

    if (pass) {
        printf("Test passed: start = %d, end = %d -> [", start, end);
        for (int i = 0; i < expected_size; i++) {
            printf("%d", result[i]);
            if (i < expected_size - 1) printf(", ");
        }
        printf("]\n");
    } else {
        printf("Test failed: start = %d, end = %d -> [", start, end);
        for (int i = 0; i < expected_size; i++) {
            printf("%d", result[i]);
            if (i < expected_size - 1) printf(", ");
        }
        printf("] (expected: [");
        for (int i = 0; i < expected_size; i++) {
            printf("%d", expected_output[i]);
            if (i < expected_size - 1) printf(", ");
        }
        printf("])\n");
    }

    free(result);
}

// int main() {
//     // Test Case 1: Normal Range (Positive)
//     int expected1[] = {5, 4, 3, 2, 1};
//     run_test(1, 5, expected1, 5);

//     // Test Case 2: Normal Range (Negative)
//     int expected2[] = {-1, -2, -3};
//     run_test(-3, -1, expected2, 3);

//     // Test Case 3: Mixed Positive and Negative Range
//     int expected3[] = {2, 1, 0, -1, -2};
//     run_test(-2, 2, expected3, 5);

//     // Test Case 4: Single Element Range
//     int expected4[] = {4};
//     run_test(4, 4, expected4, 1);

//     // Test Case 5: Reverse Range
//     int expected5[] = {3, 4, 5, 6, 7};
//     run_test(7, 3, expected5, 5);
// }
int main() {
    // Test Case 1: Small Range from Positive to Negative
    int expected1[] = {2, 1, 0, -1, -2};
    run_test(-2, 2, expected1, 5);

    // Test Case 2: Small Range with Negative Numbers Only
    int expected2[] = {-1, -2, -3};
    run_test(-3, -1, expected2, 3);

    // Test Case 3: Large Range (Small Positive Numbers)
    int expected3[] = {100, 99, 98, 97, 96};
    run_test(96, 100, expected3, 5);

    // Test Case 4: Large Range (Small Negative Numbers)
    int expected4[] = {-95, -96, -97, -98, -99, -100};
    run_test(-100, -95, expected4, 6);

    // Test Case 5: Large Range (Zero Crossing)
    int expected5[] = {2, 1, 0, -1, -2};
    run_test(-2, 2, expected5, 5);

    // Test Case 6: Zero Range
    int expected6[] = {0};
    run_test(0, 0, expected6, 1);

    // Test Case 7: Large Positive to Large Negative
    int expected7[] = {2147483647, 2147483646, 2147483645};
    run_test(2147483645, 2147483647, expected7, 3);

    // Test Case 8: Large Negative to Large Positive
    int expected8[] = {-2147483646, -2147483647, -2147483648};
    run_test(-2147483648, -2147483646, expected8, 3);

    // Test Case 9: Single Element (Positive)
    int expected9[] = {5};
    run_test(5, 5, expected9, 1);

    // Test Case 10: Single Element (Negative)
    int expected10[] = {-5};
    run_test(-5, -5, expected10, 1);
}




// int *bb(int start, int end)
// {

//     long int k;
//     long int _end = (long int)end;
//     long int _start = (long int)start;

//     if(_start >=  _end)
//         k = _start - _end + 1;
//     else   
//         k =  _end - _start + 1;

//     printf("%ld \n",k);
//     int *t = (int *)malloc(k * sizeof(int));

//     if (t == NULL)
//         return 0;

//     int i = 0;
//     if(_start >= _end)
//     {
//         while(_end <= _start)
//         {
//             t[i]= _end;
//             _end++;
//             i++;
//         }
//     }else{
//         while(_end >= _start)
//         {
//             t[i]=_end;
//             _end--;
//             i++;
//         }
//     }

//     return t;
// }