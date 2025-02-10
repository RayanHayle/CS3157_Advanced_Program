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
#define BUF_SIZE 4096

static void die(const char *s){perror(s);exit(1);}

int main (int argc, char  **argv){
 
	//./http-server <server_port> <web_root> <mdb-lookup-host> <mdb-lookup-port> 
	// majority of this is from lab6 solutions http-client.c file
	char buf[BUF_SIZE];

	if(argc != 5){
	fprintf("Usage: %s ./http-server <server_port> <web_root> <mdb-lookup-host> <mdb-lookup-port>\n ",argv[0]);
	exit(1);
	}

	char* server_port = argv[1];		
	unsigned short port = atoi(argv[2]);//<server_port> 

	// Create a socket for TCP connection
    int servsock;
    if ((servsock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        die("socket failed");

    // Construct a server address structure
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr)); // must zero out the structure
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // any network interface
    servaddr.sin_port        = htons(port); // must be in network byte order

	// Bind to the local address
    prtinf("about to bind");
    if (bind(servsock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
        die("bind failed");

    // Start listening for incoming connection
    if (listen(servsock, 5 /* queue size for connection requests */ ) < 0)
        die("listen failed");

    int clntsock;
    socklen_t clntlen;
    struct sockaddr_in clntaddr;
 
   while (1){
	// Accept an incoming connection
        clntlen = sizeof(clntaddr); // initialize the in-out parameter

        if ((clntsock = accept(servsock,
                        (struct sockaddr *) &clntaddr, &clntlen)) < 0)
            die("accept failed");	

	//char buf[BUF_SIZE];
	
	fgets(buf,sizeof(buf),clntsock);

   	 if (fgets(buf, sizeof(buf),clntsock ) == NULL) {
        	die("fgets returned NULL");
    		}
    	
	 /* a blank line to inicate the requeest is over over, and fgets stops when it locates /n
	  1.  in order to use fgets we need a file, treat the socket as a file
	   jae code --> if condtions to check them 
	  2.check that it only support the GET method
	  3. The server will accept GET requests that are either HTTP/1.0 or HTTP/1.1
	  responding with 501 status code. 
	  4.The server should also check that the request URI (the part that comes after  GET) starts with "/".
		If not, it should respond with "400 Bad Request".
	5. The server should make sure that the request URI does not contain "/../" and  it does not end with "/.."		
		128.59.22.109 "GET /cs3157/tng/images/ship.jpg HTTP/1.1" 200 OK 
       	7.  - The server must log each request to stdout like this:
         8. It should show the client IP address, the entire request line, and the status  code and reason phrase that it just sent to the browser.      
	''           
	*/
	
	FILE* input = fdopen(clntsock,"rb");//step 1, can be images as well so read binary 

        while(fgets(buf,sizeof(buf),input)){

	char requestLine[4096];
	char *token_separators = "\t \r\n"; // tab, space, new line  char 
	char *method = strtok(requestLine, token_separators);
      	char *requestURI = strtok(NULL, token_separators);
 	char *httpVersion = strtok(NULL, token_separators);
	
	 fprintf(stderr, "\nconnection started from: %s\n",
                inet_ntoa(clntaddr.sin_addr));

	//----------------------------
	// use strcmpy functions to compare strings
	//condition checkings
		 
		if(strcmp(method,"GET") != NULL ){//step 2: only support the GET method
			send(clntsock,"HTTP/1.0 501 Not Implemented\r\n\r\n<html><body><h1>501 Not Implemented</h1></body></html>");
                	close(clntsock):
			continue;}
	
		if(strcmp(httpVersion,"HTTP/1.0") == NULL  && strcmp(httpVersion,"HTTP/1.1") == NULL){//step 3: accept only HTTP/1.0 or HTTP/1.1

			send(clntsock,"HTTP/1.0 501 Not Implemented\r\n\r\n<html><body><h1>501 Not Implemented</h1></body></html>");		
			close(clntsock);
                	continue;}
	
		if(requestURI[0] != '/' || requestURI[0] == '/..' ){//step 4: request URI starts with "/"
			send(clntsock,"HTTP/1.0 400 Bad Request\r\n\r\n<html><body><h1>501 Not Implemented</h1></body></html>");
			close(clntsock);
                	continue;}

		if(strcmp(requestURI,"/../")!=0){//step 5: request URI does not contain "/../" and  it does not end with "/.."
	
			send(clntsock,"HTTP/1.0 400 Bad Request\r\n\r\n<html><body><h1>501 Not Implemented</h1></body></html>");
			close(clntsock);
               		continue;}       

		//step 6: request URI does not end with "/.."

                int i = strlen(requestURI);// to check last 3 char / . .
		int last = i -3;

		if(strstr(&requestURI[last],"/..")!= NULL){
			fprintf(input,"HTTP/1.0 400 Bad Request\r\n\r\n<html><body><h1>501 Not Implemented</h1></body></html>");
                     	close(clntsock);
                       	continue;
			}	
			
		//step 7
		fprintf(stderr, "%s  %s %s %s 200 OK\n",inet_ntoa(clntaddr.sin_addr),method,requestURI,httpVersion);
			
	//------------------------------------------------------------
	}//while fgets
	
	// solutions http-client.c lab6
	unsigned int n;
    while ((n = fread(buf, 1, sizeof(buf), input)) > 0) {

       // send(clntsock,sizeof(buf),buf,n);
  	//write(clntsock,buf,n); 
  
  	if(write(clntsock,buf,n)<0){
		flclose(input);
		die("write failed");}
    }

    fclose(input);
    close(clntsock);


   }//while 1 

}//main
 
