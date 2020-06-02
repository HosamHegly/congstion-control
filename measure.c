/*Name : Jay Jagtap
3154037
Problem Statement: To achieve File transfer using TCP/IP Protocol
*/

/*
	Server Side
	Please pass port no as command line argument
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>
#include <time.h>
#include <netinet/tcp.h>


void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;

     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
for(int z=1;z<=2;z++)
{
          for(int j=0;j<5;j++)
{
          clock_t begin,end;
          



           size_t c=0;
               size_t h=0;
          begin=clock();
double t=0;

  
size_t k=0;
while(c<1073741824)
       	   {
        char buff[5000];
       bzero(buff,sizeof(buff));
     char ch;
                
        	 h= read(newsockfd , &buff , sizeof(buff)); 
              

                     
                c=c+h;
              char cc="a";


                 send(newsockfd,&ch,sizeof(char),0);
          
  if(z==2&&j==4&&c==k)
{
break;
}


k=c;


		 
	   }



      printf("file recieved successfully\n");
	   
}
if(z==2)
break;

    char buf[256];
     socklen_t len;
    strcpy(buf, "reno"); 
len = strlen(buf);

if (setsockopt(newsockfd, IPPROTO_TCP, TCP_CONGESTION, buf, len) != 0) {
perror("setsockopt"); 
return -1;
}
printf("\n changed congestion to reno\n");
}
     close(newsockfd);
     close(sockfd);
     return 0; 
}
