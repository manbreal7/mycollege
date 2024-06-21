#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 30

struct stack{
    char arr[max][25];
    int top;
}s;

void push(char c[]){
    if(s.top==max-1){
        printf("Stack Overflow");
        return;
    }
    strcpy(s.arr[++s.top],c);
}

char* pop(){
    if(s.top==-1){
        printf("Stack Underflow");
        return "#";
    }
    return s.arr[s.top--];
}

char pfix[max];

int main()
{
    s.top=-1;
    int i;
    char v1[25],v2[25],res[25];
    printf("Enter a postfix expression: ");
    scanf("%s",&pfix);
    //conversion into infix form
    for(i=0;pfix[i]!='\0';i++){
        char temp[2];
        temp[0]=pfix[i];
        temp[1]='\0';
        if(pfix[i]=='+'||pfix[i]=='-'||pfix[i]=='*'||pfix[i]=='/'){
            strcpy(v2,pop());
            strcpy(v1,pop());
            //res="(";
            strcpy(res,"(");
            strcat(res,v1);
            strcat(res,temp);
            strcat(res,v2);
            strcat(res,")");
            push(res);

        }
        else
            push(temp);
    }
    //displaying result
    if(s.top!=0)
        printf("Invalid Input");
    else
        printf("Result= %s",pop());
    return 0;
}
