#include <netinet/in.h>    
#include <sys/types.h>    
#include <sys/socket.h>    
#include <stdio.h>        
#include <stdlib.h>       
#include <string.h>
#include "managestr.c"       

#define HELLO_WORLD_SERVER_PORT    1234
#define LENGTH_OF_LISTEN_QUEUE 2
#define BUFFER_SIZE 1000 

int main(int argc, char **argv)
{
    struct sockaddr_in server_addr;
		int server_socket;
		int opt = 1;
    FILE *fp;
    fp=fopen("temp.txt","w+");
    bzero(&server_addr,sizeof(server_addr)); 
	
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(HELLO_WORLD_SERVER_PORT);

	/* create a socket */
    server_socket = socket(PF_INET,SOCK_STREAM,0);
    if( server_socket < 0)
    {
        printf("Create Socket Failed!");
        exit(1);
    }
 
    /* bind socket to a specified address*/
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if( bind(server_socket,(struct sockaddr*)&server_addr,sizeof(server_addr)))
    {
        printf("Server Bind Port : %d Failed!", HELLO_WORLD_SERVER_PORT); 
        exit(1);
    }

    /* listen a socket */
    if(listen(server_socket, LENGTH_OF_LISTEN_QUEUE))
    {
        printf("Server Listen Failed!"); 
        exit(1);
    }
	
	/* run server */
    struct sockaddr_in client_addr;
		int client_socket;		
    socklen_t length;
		char buffer[BUFFER_SIZE];
		char *p=buffer;
		int sendfer[5]={8,8,8,8};

		/* accept socket from client */
		length = sizeof(client_addr);
  //  while(1)
  //  {
    		client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &length);
    		if( client_socket < 0)
    		{
        		printf("Server Accept Failed!\n");
    		}
    		/* receive data from client */
    		bzero(buffer, BUFFER_SIZE);
    
    		length = recv(client_socket, buffer, BUFFER_SIZE, 0);
    		if (length < 0)
    		{
	      		printf("Server Recieve Data Failed!\n");
    		}
    	    printf("%s\n", buffer);					
            fprintf(fp,"%s",buffer);
    		close(client_socket);
  // }
    fclose(fp);
    adddou();
    rmnull();
    close(server_socket);
    system("./inmysql.sh");
    return 0;
}
