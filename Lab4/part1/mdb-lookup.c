#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mdb.h"
#include <mylist.h>

int main(int argc, char **argv) {
    // STEP 1: Check the count of arguments
    if (argc != 2) {
	  fprintf(stderr, "Usage: %s\n","Usage: TODO");

	  exit(1);
    }

    // STEP 2: Open the database file
    FILE *fpointer = fopen(argv[1], "rb");

    if (fpointer == NULL) {
        perror("Error opening file");
        return 1;
    }

    // STEP 3: Create a linked list to store the information
    struct List record_list;
    initList(&record_list);

    // STEP 4: Read records from the file and populate the list
    struct MdbRec rec;
/*------------------------------------------------------------------
 NOW : in the same while loop, since its infnite:
Seach linked list for records that have the same string as our search
use addAftr() to tranverse
ISSUE: cannot access th solution for lab3

1. make varible to keep track of potion\index
2. make sure each string is truncated accuaartely ---> snprintf 6 (5 char, \0)
3.  SearchLinkedlist ---> transever using addAfter() from lab lab3, iterate through the linked list
4. strstr() ---> each record in the linkedlist needs to be checked and comapred
5. strstr() --> if retursn null ---> print the function, it is a match
6. continue searching
------------------------------------------------------------------ */
    //STEP 4: struct to hold the records, and print it 

while(fread(&rec, sizeof(struct MdbRec), 1, fpointer) == 1) {//read

        // STEP 5: Allocate memory for a new node, then check it
struct Node *node = (struct Node *)malloc(sizeof(struct Node));

        if (node == NULL) {
            perror("Memory allocation error");
            exit(1);}

        // STEP 6: Initialize the new node with malloc, and check it
node->data = malloc(sizeof(struct MdbRec));

        if (node->data == NULL) {
            perror("Memory allocation error");
            exit(1);
        }
//"STEP 7: Copies the values of num bytes from the location pointed to by source directly to the memory block pointed to by destination"
//Source: https://cplusplus.com/reference/cstring/memcpy/

        memcpy(node->data, &rec, sizeof(struct MdbRec));
        node->next = NULL;

/*STEP 8: Add the new node to the list using pointer of pointer
  add the new node to the list by using traverse
  when you find last node, link them to the new node
  its a pointer to a pointer, than derfernce it 
  */
        struct Node **current = &record_list.head;
         while (*current!= NULL) {
             current = &(*current)->next;
        }
        *current = node;
}
//------------------------------------------------------------------

    // Close the database file
    fclose(fpointer);

    // Infinite loop for user input
   char line[1000];
    char search[7]; // size = 6 , plus 1 for null 
   // int found = 0; to check if it works, comment out later so it looks like professor jae's
//------------------------------------------------------------------
// infite loop: accepts user input,searches the linked list, if no match tell, if match print
  
  
    while (1) {
     printf("lookup: ");
 //found = 0; // test
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break; // User presses Ctrl-D to exit
        }

//remove line
        line[strcspn(line, "\n")] = '\0';


// issue when i search: "lol"  it doesn't return the matching data solution search[6] ---> professor jae recommands strncpy
// okay, so the problem was that his incldued lol because it was a later data that mine didn't have because i copied it before the person made the comment

// 5 char and 1 for null terminator, set null terminator now
//source: https://www.tutorialspoint.com/c_standard_library/c_function_strncpy.htm

strncpy(search,line,6);
search[6] = '\0';

//------------------------------------------------------------------

  // Initialize a variable to keep track of the record number
        int index = 1;

        // Traverse the linked list to search for matching records
        struct Node *current = record_list.head;

        while (current != NULL) {
//         char prompt[] = "Lookup: ";
//	   printf("%s\n",prompt);
//- Don't forget to print those records that contain the given search string in  any of the two fields.  The library function strstr() may come in handy.
	   

     	  struct MdbRec *record = (struct MdbRec *)current->data;
            if (strstr(record->name, search) || strstr(record->msg, search)) {

		    /*  if (found == 0) {
                    printf("Matching records:\n");
                    found = 1;}*/
                
            printf("%d: {%s} said {%s}\n", index, record->name, record->msg);}

            current = current->next;
            index++;
        }// while loop

	/*if (found == 0) {
            printf("No matching records found.\n");}*/
// printf("Lookup:"); two double lookup --> lookup:lookup
    }


//------------------------------------------------------------------
    // Free allocated memory
    struct Node *current = record_list.head;
//ISSUE FIXED: free all data in while loop remove all node but
//source lecture 11, notes libaries 
//Source:    https://stackoverflow.com/questions/76078825/delete-all-nodes-in-a-linked-list-in-c

    while (current != NULL) {
        struct Node *next = current->next;
        free(current->data);
//        free(current);caused memory error, trid to free something and later tried to free it in removeAllNodes
        current = next;
    }
      removeAllNodes(&record_list);

}

