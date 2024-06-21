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
int sz,ch=0;
int ele;
char ans[MAXSIZE];
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
//
while(ch!=4){
    printf("\nDo you want to: \n1-Search\n2-sort\n3-odd/even\n4exit\nEnter your choice:");
	scanf("%d",&ch);
	sentbytes=send(sockfd,&ch,sizeof(ch),0);
	switch(ch)
	{
		case 1:printf("\nEnter the size of the array:");
			   scanf("%d",&sz);
			   sentbytes=send(sockfd,&sz,sizeof(sz),0);
			   printf("\nEnter the array elements:");
			   for(int i=0;i<sz;i++)
			   {
				   scanf("%d",&buff[i]);
			   }
			   for(int i=0;i<sz;i++)
			   {
				   sentbytes=send(sockfd,&buff[i],sizeof(buff[i]),0);
			   }
			   printf("\nEnter the element to be searched:");
			   scanf("%d",&ele);
			   sentbytes=send(sockfd,&ele,sizeof(ele),0);
			   recedbytes=recv(sockfd,ans,sizeof(ans),0);
			   printf("%s",ans);
			   fflush(stdin);
			   break;
			   
		case 2:printf("\nEnter the size of the array:");
			   scanf("%d",&sz);
			   sentbytes=send(sockfd,&sz,sizeof(sz),0);
			   printf("\nEnter the array elements:");
			   for(int i=0;i<sz;i++)
			   {
				   scanf("%d",&buff[i]);
			   }
			   for(int i=0;i<sz;i++)
			   {
				   sentbytes=send(sockfd,&buff[i],sizeof(buff[i]),0);
			   }
			   for(int i=0;i<sz;i++)
			   {
				   recedbytes=recv(sockfd,&buff[i],sizeof(buff[i]),0);
			   }
			   printf("Sorted array:\n");
			   for(int i=0;i<sz;i++)
			   {
				   printf("%d ",buff[i]);
			   }
		
	}

}



printf("\n");
close(sockfd);
}
