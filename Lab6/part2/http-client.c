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
#include <netdb.h>
#include <string.h>

/* STEPS:
1. pick apart the CLA 
	domain name var
	port number var
	path var
2. convert the domain name to IP --> Jae gave code to this
	ip = coversion of domain name
3. create socket and connection --> from tcp-sender.c
4. use snprint to put togther the CLA into a GET request to send to the server 
5. send to the socket the request 
6. use fdopen with socket
7. check how file looks like
*/


static void die(const char *s){
        perror(s);
        exit(1);}

 int main (int argc, char **argv){

//STEP 1:	
	
	 if (argc !=4){
        fprintf(stderr, "usage: %s <server-ip> <server-port> <file-path> \n", argv[0]);
        exit(1);}

        char* serverName = argv[1];
        unsigned short port = atoi(argv[2]);
        char *path = argv[3];

//STEP 2 --> professor jae's 
	struct hostent *he;
	// get server ip from server name
	if ((he = gethostbyname(serverName)) == NULL) {
	    die("gethostbyname failed");
	}
	char *serverIP = inet_ntoa(*(struct in_addr *)he->h_addr);

//STEP 3 ---> SOURCE: tcp-sender.c
	int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        die("socket failed");

    // Construct a server address structure

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr)); // must zero out the structure
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(serverIP);
    servaddr.sin_port        = htons(port); // must be in network byte order

    // Establish a TCP connection to the server

    if (connect(sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
        die("connect failed");
	
    printf("Connecting to %s on port %d\n",serverName,port);

//-------------------------------------------------------------------
//TESTING: will comment out later
	printf("Host: %s\n",serverName);//argv 1
	printf("IP: %s\n",serverIP);
	printf("Port: %d\n",port);//argv 2
	printf("Path: %s\n",path);//argv 3
//-------------------------------------------------------------------
//STEP 4: using snprintf Build HTTP get request
	
	// now use snprintf to put togother the CLA into a GET request
	// breaking up the sprintf so its more clear and readable
	//Use "\r\n" rather than "\n" as newline when you send your request.
	
	char buffer[4091];
	
	int wrriten = snprintf(//GET request
		buffer,sizeof(buffer),
		"GET %s HTTP/1.0\r\n"   //this is the HTTP method and path and the verison it is
		"Host: %s:%hu\r\n"      // this is host/serverName and the port number
		"\r\n",                  //end of the headers
		//argv[3],argv[1],argv[2]
		path,serverName,port 
		);



	printf(" %s",buffer);// checking if request is good
			    
// STEP 5: send that request with send to the socket
	
	send(sock, buffer,wrriten,0);
	

	//check if error occrued when sending 
	
	/*
	if(check_send < 0 || check_send != int(wrriten)){
	fprintf(stderr, "Error occured sending request.\n");
	exit(1);
	}*/

//------------------------------------------------------------------	

/*1 ---open file stream fdope
 *2 --- read status line
 *3 ---strs to exctract file name
 4. open/create file
 5. check success status 
 */		

	// step 6.1 open the file stream for reading
	FILE *input = fdopen(sock, "r");
        if(input == NULL){
                die("Fdopen has failed");
        }
	
	//6.2 read stauts line
	char read_buffer[2000];

	fgets(read_buffer,sizeof(read_buffer),input);//tcp-echo-client.c

	printf("%s\n", read_buffer);//prints status 

	//6.3 extract the name --> last / 
	//find the last / in the URL path
	
	char *extract_file = argv[3];
	char *extFile_name  = NULL;

	for(int i = strlen(extract_file) - 1; i >= 0; i--){
		if (extract_file[i] =='/'){ 
			extFile_name = &extract_file[i + 1];// / move 1 /hmt.c h
			
			printf("File: %s\n",extFile_name);
			
			break;}}
	

	// 6.4 open the file to append to 
	FILE *file_output = fopen(extFile_name, "a");

//------------------------------------------------------------------ 
	//step 7 reading lines 
	char buffer_req[5000];
 	
	while(fgets(buffer_req,sizeof(buffer_req),input) !=NULL){
		// look for empty line, when you reach it 
		// read lines from input stream until it reaches new line
	
	 fprintf(stderr, "%s", buffer_req);

	 if( strcmp(buffer_req,"\r\n") == 0){
	 break;
	// fprintf(stderr, "%s", buffer_req);
	 }
	// fprintf(stderr, "%s", buffer_req);
	}



//------------------------------------------------------------------  
/* STEP 8
 Read the data to the usiing fread, and write into it using fwrite 
from: tcp-sender.c
*/
    char buf[4096];
    unsigned int n;

    while ((n = fread(buf, 1, sizeof(buf), input)) > 0) {

	fwrite(buf,1,n,file_output);
    }


	
    fclose(input);
    fclose(file_output);
    close(sock);
 }//main
