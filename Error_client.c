#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define MAXSIZE 50

main()
{
int sockfd,retval;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr;
int buff[MAXSIZE];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
printf("\nSocket Creation Error");

}
printf("%i",sockfd);
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3388);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==-1)
{
printf("Connection error");

}
printf("enter 7 bit code:\n");

for(int i=0;i<7;i++)
{
	scanf("%d",&buff[i]);
}
for(int i=0;i<7;i++)
{
	sentbytes=send(sockfd,&buff[i],sizeof(buff[i]),0);
}

close(sockfd);
}