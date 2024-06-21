//EVALUATE PREFIX
#include<stdio.h>
#include<string.h>
#define max 50
int top;
int a[max],infix[max];
char s[max];
void push( int ele){
    if(top==max-1){
        printf("overflow");
        return;
    }
    a[++top]=ele;
    
}
int pop(){
    if(top==-1){
        printf("underflow");
        return -1;
    }
    return a[top--];
}
int operate(int x,int y,char op){
    switch(op){
        case '+':return x+y;
         case '-':return x-y;
          case '/':return x/y;
           case '*':return x*y;
    }
}
void evaluate(){
    printf("enter prefix expression");
    gets(s);
  int op1,op2,result;
   for(int i=strlen(s)-1;i>=0;i--){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            op1=pop();
            op2=pop();
            result=operate(op1,op2,s[i]);
            push(result);
        }
        else{
            push(s[i]-'0');
        }
    }
    if(top== 0) {
        printf("Result is %d\n", pop());
    } else {
        printf("Invalid postfix expression\n");
    }
   
}
int main(){
    top=-1;
    evaluate();
}
