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
        printf("Overflow");
        return;
    }
    strcpy(s.arr[++s.top],c);
}

char* pop(){
    if(s.top==-1){
        printf("Underrflow");
        return "#";
    }
    return s.arr[s.top--];
}

void read(){
    printf("Enter prefix expression: ");
    scanf("%s",&pre);
}

void reverse(char str[]){
    int len=strlen(str),i;
    for(i=0;i<len/2;i++){
        char temp=str[i];
        str[i]=str[len-1-i];
        str[len-i-1]=temp;
    }
}

void PreToPost(){
    int i;
    char op1[20],op2[20],temp[2];
    for(i=0;pre[i]!='\0';i++){
        switch(pre[i]){
            case '+':
            case '-':
            case '*':
            case '/':
                temp[2];
                temp[0]=pre[i];
                temp[1]='\0';
                strcpy(op1,pop());
                strcpy(op2,pop());
                strcat(op1,op2);
                strcat(op1,temp);
                push(op1);
                break;
            default:
                temp[2];
                temp[0]=pre[i];
                temp[1]='\0';
                push(temp);
        }
    }
    if(s.top==0)
        printf("Postfix expression: %s",pop());
    else
        printf("Invalid expression");
}

int main()
{
    s.top=-1;
    read();
    reverse(pre);
    PreToPost();
    return 0;
}
