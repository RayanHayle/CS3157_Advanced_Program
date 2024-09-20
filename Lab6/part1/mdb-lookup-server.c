/*
 * mdb-lookup-server.c
 */
#include "mylist.h"
#include "mdb.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define KeyMax 5 //for lab4

/* the API stocket will be same to tcp-echo-server.c only differnce will be:

1. arugmnt count to 3
2. add the line from lab6 to the top of main
3. port number will be arumgent 2

   */
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

// FUNCTIONS: 
int loadmdb(FILE *fp, struct List *dest)
{
    /*
     * read all records into memory
     */

    struct MdbRec r;
    struct Node *node = NULL;
    int count = 0;

    while (fread(&r, sizeof(r), 1, fp) == 1) {

        // allocate memory for a new record and copy into it the one
        // that was just read from the database.
        struct MdbRec *rec = (struct MdbRec *)malloc(sizeof(r));
        if (!rec)
            return -1;
        memcpy(rec, &r, sizeof(r));

        // add the record to the linked list.
        node = addAfter(dest, node, rec);
        if (node == NULL)
            return -1;

        count++;
    }

    // see if fread() produced error
    if (ferror(fp))
        return -1;

    return count;
}

void freemdb(struct List *list)
{
    // free all the records
    traverseList(list, &free);
   removeAllNodes(list); //i had memory leaks because i forgot to include this line 
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

// FROM  tcp-echo-server.c

static void die(const char *s) { perror(s); exit(1); }

int main(int argc, char **argv){

	
// ignore SIGPIPE so that we don't terminate when we call
    // send() on a disconnected socket.
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) 
	die("signal() failed");

    if (argc != 3) {
        fprintf(stderr, "usage: %s <server-port> <filebase>\n", argv[0]);
	exit(1);}

    unsigned short port = atoi(argv[2]);// port number will be third arugment

    // Create a listening socket (also called server socket)

    int servsock;
    if ((servsock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        die("socket failed");

      // Construct local address structure

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // any network interface
    servaddr.sin_port = htons(port);

    // Bind to the local address

    if (bind(servsock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
        die("bind failed");

    // Start listening for incoming connections

    if (listen(servsock, 5 /* queue size for connection requests */ ) < 0)
        die("listen failed");

    int r;
    int clntsock;
    socklen_t clntlen;
    struct sockaddr_in clntaddr;


    while(1){

// Accept an incoming connection

        fprintf(stderr, "waiting for client ... ");

        clntlen = sizeof(clntaddr); // initialize the in-out parameter

        if ((clntsock = accept(servsock,(struct sockaddr *) &clntaddr, &clntlen)) < 0)
            die("accept failed");

        // accept() returned a connected socket (also called client socket)
        // and filled in the client's address into clntaddr

        fprintf(stderr, "connection intialited from: %s\n", inet_ntoa(clntaddr.sin_addr));



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
// SOLUTIONS  from lab 4 so that this can perform the searching

    char *filename = argv[1];
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
        die(filename);

    /*
     * read all records into memory
     */

    struct List list;
    initList(&list);

    int loaded = loadmdb(fp, &list);
    if (loaded < 0)
        die("loadmdb");

    fclose(fp);

    /*
     * lookup loop
     */

    char line[1000];
    char key[KeyMax + 1];

   /* printf("lookup: ");standard I/O streams
    fflush(stdout);standard I/O streams*/

// FILE *input = fdopen(socket_descriptor, "r");
    FILE *input = fdopen(clntsock,"r");

    while (fgets(line, sizeof(line),input) != NULL) {

      // must null-terminate the string manually after strncpy().
        strncpy(key, line, sizeof(key) - 1);
        key[sizeof(key) - 1] = '\0';

        // if newline is there, remove it.
        size_t last = strlen(key) - 1;
        if (key[last] == '\n')
            key[last] = '\0';

        // traverse the list, printing out the matching records
        struct Node *node = list.head;
        int recNo = 1;

	//need a buffer -->snprintf will store contented into buffer therefore won't use I/O stream throgh print


	char buffer[1000];//size of buffer to read content into using snprintf

	while (node) {
		
	struct MdbRec *rec = (struct MdbRec *)node->data;
            if (strstr(rec->name, key) || strstr(rec->msg, key)) {
      	   // printf("%4d: {%s} said {%s}\n", recNo, rec->name, rec->msg);
           
	    r = snprintf(buffer,sizeof(buffer),"%4d: {%s} said {%s}\n", recNo, rec->name, rec->msg);

	//if (send(clntsock, buf, r, 0) != r)
	
	   send(clntsock,buffer,r,0);
	   
	    }
            node = node->next;
            recNo++;

        }//while node

        //printf("\nlookup: ");
        //fflush(stdout);
    }


//end of lab 4 solution
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

	// continuing  tcp-echo-server.c

	if (r < 0) {
		fprintf(stderr, "ERR: recv failed\n");
	}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ISSUE: how to free the nodes 
//free addFront and 	


    //freemdb(&list);
   
   fclose(input);//file closed
    close(clntsock);//socket closed

    freemdb(&list);
}//while 1

}//main
