#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

struct stack{
    int arr[max][20];
    int top;
}s;
char pre[max];

void push(char c[]){
    if(s.top==max-1){
       printf("Overflow") ;
       return;
    }
    strcpy(s.arr[++s.top],c);
}

char* pop(){
    if(s.top==-1){
        printf("Underflow");
        return "#";
    }
    return s.arr[s.top--];
}

void reverse(char c[]){
    char temp;
    int i,len=strlen(c);
    for(i=0;i<len/2;i++){
        temp=c[i];
        c[i]=c[len-1-i];
        c[len-1-i]=temp;
    }
}

void Convert(){
    int i;
    char op1[20],op2[20],temp[2],res[20];
    for(i=0;pre[i]!='\0';i++){
        temp[0]=pre[i];
        temp[1]='\0';
        switch(pre[i]){
            case '+':
            case '-':
            case '*':
            case '/':
                strcpy(op1,pop());
                strcpy(op2,pop());
                strcpy(res,"(");
                strcat(res,op1);
                strcat(res,temp);
                strcat(res,op2);
                strcat(res,")");
                push(res);
                break;
            default:
                push(temp);
        }
    }
    if(s.top!=0)
        printf("Invalid expression");
    else
        printf("Infix expression: %s",pop());
}

int main()
{
    s.top=-1;
    printf("Enter Prefix expression: ");
    scanf("%s",&pre);
    reverse(pre);
    Convert();
    return 0;
}
