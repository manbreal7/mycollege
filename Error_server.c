#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 90
int parity_check(int a[])
{
	int count=0;
	for(int i=0;i<7;i++)
	{
		if(a[i]==1)
		{
			count++;
		}
	}
	if(count%2!=0)
	{
		return 0;
	}
	return 1;
	
}
int check_pos(int a[])
{
	int q1,q2,q4;
	q1=a[0]^a[2]^a[4]^a[6];
	q2=a[1]^a[2]^a[5]^a[6];
	q4=a[3]^a[4]^a[5]^a[6];
	int pos=q1*1+q2*2+q4*4;
	printf("%d",pos);
	return pos;
}
void error_correction(int a[])
{
	int position=check_pos(a);
	if(a[position-1]==0)
	{
		a[position-1]=1;
	}
	else if(a[position-1]==1)
	{
		a[position-1]=0;
	}
}
	
main()
{
int sockfd,newsockfd,retval;
socklen_t actuallen;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr,clientaddr;

int buff[MAXSIZE];
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


if(newsockfd==-1)
{
close(sockfd);
}
for(int i=0;i<7;i++)
{
	recedbytes=recv(newsockfd,&buff[i],sizeof(buff[i]),0);
}
for(int i=0;i<7;i++)
{
	printf("%d",buff[i]);
}
if(parity_check(buff))
{
	printf("\nno error\n");
}
else{
	printf("\nerror\n");
	error_correction(buff);
	printf("\nCorrected data is:");
	for(int i=0;i<7;i++)
	{
		printf("%d",buff[i]);
	}
}

close(sockfd);
close(newsockfd);
}

