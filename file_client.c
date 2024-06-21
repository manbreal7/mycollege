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
char buff[MAXSIZE];
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
printf("Enter alpha numeric:");
char arr[100];
gets(arr);
FILE* fptr;
fptr=fopen("note.txt","w");
fputs(arr,fptr);
printf("\nEnter the file name:");
gets(buff);
sentbytes=send(sockfd,buff,sizeof(buff),0);
recedbytes=recv(sockfd,buff,sizeof(buff),0);
if(strcmp(buff,"File does not exist")==0)
{
	printf("File does not exist");
}
else{
	printf("File exists");
}
char answer[MAXSIZE];
printf("\nEnter the file name of answer file:");
gets(answer);
sentbytes=send(sockfd,answer,sizeof(answer),0);

close(sockfd);
}
