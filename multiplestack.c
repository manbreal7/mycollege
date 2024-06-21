#include <stdio.h>
#include <stdlib.h>
#define max 100

struct mstack{
    int top[max];
    int arr[max];
    int b[max];
}s;

void push(){
    int no,ele;
    printf("Enter stack no: ");
    scanf("%d",&no);
    if(s.top[no-1]==s.b[no]){
        printf("Overflow");
        return;
    }
    printf("Enter element: ");
    scanf("%d",&ele);
    s.arr[++s.top[no-1]]=ele;
}

void pop(){
    int no,ele;
    printf("Enter stack no: ");
    scanf("%d",&no);
    if(s.top[no-1]==s.b[no-1]){
        printf("Underflow");
        return;
    }
    ele=s.arr[s.top[no-1]--];
    printf("Popped element: %d\n",ele);
}

void CreateStack(int n){
    int i;
    for(i=0;i<n;i++)
        s.top[i]=s.b[i]=(max/n)*i-1;
    s.b[i]=max-1;
}

void display(){
    int no;
    printf("Enter stack no: ");
    scanf("%d",&no);
    if(s.top[no-1]==s.b[no-1]){
        printf("Underflow");
        return;
    }
    for(int i=s.top[no-1];i>s.b[no-1];i--)
        printf("%d ",s.arr[i]);
    printf("\n");
}

int main()
{
    int nst,ch;
    printf("How many stacks required: ");
    scanf("%d",&nst);
    CreateStack(nst);
    do{
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting now!!");
                break;
            default: printf("Invalid option");

        }
    } while(ch!=4);
    return 0;
}
