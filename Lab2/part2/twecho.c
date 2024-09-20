/*
 * twecho
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 
static char **duplicateArgs(int argc, char **argv);

// Function to duplicate command-line arguments
// PART2

char **duplicateArgs(int argc, char **argv) {
  
    /* TA:  a pointer is pointing to another pointer or when it's dereferndicing  
    pointer have their own memory, and what the store inside the box is an ADRESSS of what they're pointing to
    
   think value stored insize box, and adress
    int x = 5; ---> lets say the adress of x is 201
    
    int *p;
    p = &x;
    int *p = &x; --->  p  has its own adress (202). but p is storing the adress of x inside. what matters is the infromated stored: 201 
   
   int *q; 
   *q = &p;  pointer p is store adress of p
   int *(*q) = &p --->  q is a pointer with its own adress 2023, q is point to the adress of (203) and sotring its adress
   
    *p has stored 201:  x adress
    *(*q) has stored 203: 
    
    */
    
// STEP 1. Declare a pointer to a pointer to char
    // a pointer named copy and its own adress
    //  is storing the adress of another pointer inside its box
    
    char *(*copy);
    
// Step 2:  copy is empty pointer that will be copying the adress from our argv
    // 'argc  1' is used to account for the NULL pointer at the end. 
    // sizeof() allocated for null but strlen does not
    // when i copy using strcpy it copies all charachters including '0\'
    // if i don't unclude the count by 1 there will be memory spill
    // final, type cast malloc
    // allocate  memory for an array of pointers to characters
     //The sizeof(char *) gives us the size of a pointer to char, which is  6 bytes.

    copy = (char **)malloc((argc + 1) * sizeof(char *)); 

 // STEP 3: check memory allocation everytime malloc is set up

//printf("%zu\n",sizeof(copy)); //---> 8 bytes memort takes

    if (copy == NULL) {
        perror("malloc returned NULL");
        exit(1);
    }

// STEP 4. Get the length of the original word using argc because c is for count.
    for (int i = 0; i < argc; i++) { // big for loop
        int len = strlen(argv[i]);


//STEP 5. Allocate memory for array char[i] is empty and will be filled with char[j]
    // 'copy[i]' is a pointer  ---> the the array which is char.
    // strlen does not allocated for null
    // when i copy using strcpy it copies all charachters including '0\'

        copy[i] = (char *)malloc((len + 1) * sizeof(char));
        //printf("%zu\n",sizeof(copy[i]));

// STEP 6: check memory allocation everytime malloc is set up
        if (copy[i] == NULL) {
            perror("malloc returned NULL");
            exit(1);
        }

//STEP 7. Copy the original word into the new memory using strcpy(x,x).
        strcpy(copy[i], argv[i]); // empty, copy from

// STEP 8. Convert the word to uppercase letter by letter.
        for (int j = 0; j < len; j++) {
            copy[i][j] = toupper(copy[i][j]);
        }
    }

  // 9. Set the last element of the 'copy' array to NULL to mark the end.
    copy[argc] = NULL;

// 10. Return 'copy,' which is a pointer to a pointer to char.
    return copy;
 }

static void freeDuplicatedArgs(char **copy);

// Function to free duplicated arguments
void freeDuplicatedArgs(char **freeorginal) {
    int i = 0;
    while (freeorginal[i] != NULL){
        free(freeorginal[i]); // free every single char 
        i++;
    }
    free(freeorginal);
 }

//}
 /*
  * DO NOT MODIFY main().
  */
int main(int argc, char **argv)
{
	if (argc <= 1)
		return 1;
	char **copy = duplicateArgs(argc, argv);
	char **p = copy;
	argv++;
	p++;
while (*argv) {	
	printf("%s %s\n", *argv++, *p++);
	}
	freeDuplicatedArgs(copy);
	return 0;
}
