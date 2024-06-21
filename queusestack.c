#include <stdio.h>
#include <stdlib.h>
#define max 80

struct stack{
    int arr[max];
    int top;
}s1,s2;

void push1(int n){
    if(s1.top==max-1){
        printf("Overflow");
        return;
    }
    s1.arr[++s1.top]=n;
}

void push2(int n){
    if(s2.top==max-1){
        printf("Overflow");
        return;
    }
    s2.arr[++s2.top]=n;
}

int pop1(){
    if(s1.top==-1){
        printf("Underflow");
        return -999;
    }
    return s1.arr[s1.top--];
}

int pop2(){
    if(s2.top==-1){
        printf("Underflow");
        return -999;
    }
    return s2.arr[s2.top--];
}

void display(){
    for(int i=s1.top;i>=0;i--)
        printf("%d ",s1.arr[i]);
    printf("\n");
}

int main()
{
    s1.top=s2.top=-1;
    int i,ele,ch,x;
    do{
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter no.: ");
                scanf("%d",&ele);
                while(s1.top!=-1){
                    x=pop1();
                    push2(x);
                }
                push1(ele);
                while(s2.top!=-1){
                    x=pop2();
                    push1(x);
                }
                break;
            case 2:
                x=pop1();
                printf("Element %d removed\n",x);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting now!!");
                break;
            default: printf("Invalid input");
        }
    } while(ch!=4);
    return 0;
}
