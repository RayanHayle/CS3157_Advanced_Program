#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// SOURCE: https://www.javatpoint.com/quick-sort
// TA: SOURCE https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
// Comparison function for qsort (ascending order) function defintion 

int compare_asc(const void *a, const void *b) {
    /* const void accepts any tyope od data
    pointer int type a
    pointer int type b
    */
    return (*(int *)a - *(int *)b);
    
    /*
    step 1: TYPE CASTE a to be (int *a) now a is pointer to an adress
    step 2: DERFERNCE to get the value a is point to, derfenerce 
    * *int a --> pointer a adress access its value
    then use qsort to sort it out
    */
  
}
// Comparison function for qsort (descending order)
int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
//__________________________________________

//function defintion : it is a requiment: void sort_integer_array(int *begin, int *end, int ascending)

void sort_integer_array(int *begin, int *end, int ascending){
    if (ascending){ // comparing function return value, this funtion will evalute them futher 
        qsort(begin, end-begin, sizeof(int),compare_asc); // comparing

    }
    else{ qsort(begin, end-begin, sizeof(int),compare_desc);
}
    
}
//__________________________________________

int main() {
    int size;

    // Step 1: Prompt the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Step 2: random number generator
    srand(time(NULL)); // email, had issue, added time, fixed

    // Step 3: Allocate memory for the array
    // amount * type od data 
    int *array = (int *)malloc(size * sizeof(int));
    //malloc is type casted because by default its void

    // Step 4: Check if memory allocation was successful
    if (array == NULL) {
         perror("malloc returned NULL"); 
        return 1;
    }

    // Step 5: populate the array random num range 0-99
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; 
    }
    
    // Step 6: print my oringal randomly created array
    printf("original: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
//___________________________________________________________________

    // Step 7: Make a copy of the original array for ascending sorting

    int *ascending_copy = (int *)malloc(size * sizeof(int));
    
    // Step 8:Check  memory allocation 
    if (ascending_copy == NULL) {
         perror("malloc returned NULL"); 
        return 1;
    }
    
    // Step 9: Quick Sort the ascending copy 
    qsort(array, size, sizeof(int), compare_asc);

    // Step 10: Ascending_copy idnex is filed with info copyied from array[i]
    for (int i = 0; i < size; i++) {
        ascending_copy[i] = array[i];
    }
    
    //STEP 10: print ascending order
    
    printf("ascending: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", ascending_copy[i]);
    }
    printf("\n");

//__________________________________________

    // Step 11: Make a copy of the original array for ascending sorting

    int *descending_copy = (int *)malloc(size * sizeof(int));
    
    // Step 12:Check  memory allocation 
    if (descending_copy == NULL) {
        perror("malloc returned NULL");
        return 1;
    }
        // Step 9: Quick Sort the ascending copy 

    qsort(array, size, sizeof(int), compare_desc); 

    
    for (int i = 0; i < size; i++) {
        descending_copy[i] = array[i];
    }
    
    //STEP 10: print descending
     
    printf("descending: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", descending_copy[i]);
    }
    printf("\n");

//__________________________________________

    // free memory for the arrays
    free(array);
   free(ascending_copy);
   free(descending_copy);

    return 0;
} 
 
