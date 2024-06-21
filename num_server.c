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
int temp;
int j,ele;
int flag=0;
char ans[MAXSIZE];
int sockfd,newsockfd,retval;
socklen_t actuallen;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr,clientaddr;
int sz,ch=0;
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
while(ch!=4)
{
	recedbytes=recv(newsockfd,&ch,sizeof(ch),0);
	switch(ch)
	{
		case 1:recedbytes=recv(newsockfd,&sz,sizeof(sz),0);
				for(int i=0;i<sz;i++)
				{
					recedbytes=recv(newsockfd,&buff[i],sizeof(buff[i]),0);
				}
				recedbytes=recv(newsockfd,&ele,sizeof(ele),0);
				for(j=0;j<sz;j++)
				{
					if(ele==buff[j])
					{
						flag=1;
						break;
					}
					else{
						flag=0;
					}
				}
				if(flag==1)
				{
					sprintf(ans,"Element found at %d th position",j+1);
				}
				else{
					sprintf(ans,"Element not found");
				}
				sentbytes=send(newsockfd,ans,sizeof(ans),0);
				break;
		case 2:recedbytes=recv(newsockfd,&sz,sizeof(sz),0);
			   for(int i=0;i<sz;i++){
				   recedbytes=recv(newsockfd,&buff[i],sizeof(buff[i]),0);
			   }
			   for(int i=0;i<sz-1;i++)
			   {
				   for(int j=0;j<sz-i-1;j++)
				   {
						if(buff[j]>=buff[j+1])
						{
							temp=buff[j];
							buff[j]=buff[j+1];
							buff[j+1]=temp;
						}
				   }
			   }
			   for(int i=0;i<sz;i++)
			   {
				   sentbytes=send(newsockfd,&buff[i],sizeof(buff[i]),0);
			   }
	}
}



close(sockfd);
close(newsockfd);
}

