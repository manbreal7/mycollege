 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 90

main()
{
	int sum=0;
int sockfd,newsockfd,retval;
socklen_t actuallen;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr,clientaddr;

char buff[MAXSIZE];
int a=0;
sockfd=socket(AF_INET,SOCK_STREAM,0);

if(sockfd==-1)
{
printf("\nSocket creation error");
}

serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3388);
serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==1)
{
printf("Binding error");
close(sockfd);
}

retval=listen(sockfd,1);
if(retval==-1)
{
close(sockfd);
}

actuallen=sizeof(clientaddr);
newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);

recedbytes=recv(newsockfd,buff,sizeof(buff),0);
char fil[MAXSIZE];
if(access(buff,F_OK)!=-1)
{
	strcpy(fil,buff);
	strcpy(buff,"File exists");
}
else{
	strcpy(buff,"File does not exist");
}
char content[1000];
FILE* fptr;
fptr=fopen(fil,"r");
while(fgets(content,1000,fptr))
{
	printf("%s",content);
}
sentbytes=send(newsockfd,buff,sizeof(buff),0);
for(int i=0;i<strlen(content);i++)
{
	if(content[i]>=48&&content[i]<=57)
	{
		sum+=content[i]-'0';
	}
	else if(content[i]>=65&&content[i]<=90)
	{
		sum+=content[i]-64;
	}
	else if(content[i]>=97&&content[i]<=122)
	{
		sum+=content[i]-96;
	}
	else{
		sum+=0;
	}
}
char ans[100];
sprintf(ans,"%d",sum);
printf("\n%s",ans);
FILE* fptr2;
fptr2=fopen("Answer.txt","w");
fputs(ans,fptr2);
char answer[MAXSIZE];
recedbytes=recv(newsockfd,answer,sizeof(answer),0);
FILE* fptr3;
fptr3=fopen(answer,"r");
char content2[1000];
while(fgets(content2,1000,fptr3))
{
	printf("%s",content2);
}
		
close(sockfd);
close(newsockfd);
}

