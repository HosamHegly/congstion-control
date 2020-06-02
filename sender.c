/*Name : Jay Jagtap
3154037
Problem Statement: To achieve File transfer using TCP/IP Protocol
*/

/*
	Client Side
	Please pass ip address and port no as command line arguments in the same sequence
	glad.txt file should be already created before you run the program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <arpa/inet.h>
#include<ctype.h>
#include <netinet/tcp.h>

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{    char ack;
int optval;
    int sockfd, portno, n;
 struct timeval start,end;
    struct sockaddr_in serv_addr;
    struct hostent *server;


    if (argc < 3)
    {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
  
for(int z=1;z<=2;z++)
{
      for(int j=0;j<5;j++)
{  
    FILE *f;
    
    int words = 0;
    char c;
     f=fopen("1gb.txt","r");
    double t1=0.0;
    double t2=0.0;
	
       
    char ch=" " ;
    size_t count=0;
   int i=0;
       while(ch != EOF)
      {
          
        char buff[5000];
        bzero(buff,sizeof(buff));
        if(i>0)
         buff[count++]=ch;
            ch= fgetc(f);
              
 

         while(count<5000&&ch!=EOF)
{
             buff[count++]=ch;
            ch= fgetc(f);


                        
}
  i++;
 if(gettimeofday(&start,NULL)) {
   printf("time failed\n");
   exit(1);
  }

size_t h,l;
		h=write(sockfd,&buff,count);
          



       
         optval=recv(sockfd,&ack,sizeof(char),0);



  if(optval==-1) {
   perror("Receive error");
   exit(1);
}


 
   if(gettimeofday(&end,NULL)) {
    printf("time failed\n");
    exit(1);
   }
             t1+=(end.tv_sec-start.tv_sec)*1000;
           
  
                
                count=0;
                

      }

	printf("The file was sent successfully RTT = %lf ms\n",t1);
}
 
    char buf[256];
     socklen_t len;
    strcpy(buf, "reno"); 
len = strlen(buf);

if (setsockopt(sockfd, IPPROTO_TCP, TCP_CONGESTION, buf, len) != 0) {
perror("setsockopt"); 
return -1;
}
if(z==2)
break;
printf("\n changed congestion to reno\n");
} 
    close(sockfd);
    return 0;
}
