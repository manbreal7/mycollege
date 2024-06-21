//Implement stacks using queues

#include<stdio.h>
#define max 10
typedef struct{
    int f,r;
    int a[max];
}queue;
queue q1,q2;
void enque1(int ele){
    if(q1.r==max-1){
        printf("overflow");
        return;
    }
    q1.a[++q1.r]=ele;
}
int deque1(){
    if(q1.f==q1.r){
        printf("underflow");
        return ;
    }
    else
    //printf("%d is deleted",&s1.a[s1.top--]);
    return q1.a[++q1.f];
}
void enque2(int ele){
    if(q2.r==max-1){
        printf("overflow");
        return;
    }
    q2.a[++q2.r]=ele;
}
int deque2(){
    if(q2.f==q2.r){
        printf("underflow");
        return ;
    }
    else
    //printf("%d is deleted",&s2.a[s2.top--]);
    return q2.a[++q2.f];
}
int main(){
   q1.f=q1.r=q2.f=q2.r=-1;
    int op,x;
    while(1){
        printf("1-add 2-del 3-display 4-exit\n");
        scanf("%d",&op);
        if(op==4){
            break;
        }
        switch(op){
            case 1:
            int ele;printf("enter element to be added");
            scanf("%d",&ele);
            while(q1.f!=q1.r){
                x=deque1();
                enque2(x);
            }
            enque1(ele);
            while(q2.f!=q2.r){
                x=deque2();
               enque1(x);
            }
            break;
            case 2:x=deque1();
            printf("%d is deleted",x);
            break;
            case 3:for(int i=q1.r-1;i>=q1.f;i--){
                printf("%d\t",q1.a[i]);
            }
                
            }
            
        }
        
    
    
    return 0;
}

/*ultiple queues
#include <stdio.h>
#define max 20

typedef struct {
    int f[max],r[max], b[max];
    int a[max];
} queue;

queue s;

void create(int num) {
    for (int i = 0; i < num; i++) {
        s.f[i] =s.r[i] =s.b[i] = (max / num) * i - 1;
    }
    s.b[num - 1] = max - 1;
}

void push() {
    int n, ele;
    printf("Enter the queue no:\t");
    scanf("%d", &n);

    // Check for queue overflow (minimal error handling)
    if (s.r[n - 1] == s.b[n]) {
        printf("Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &ele);
    s.a[++s.r[n - 1]] = ele;
}

void pop() {
    int n;
    printf("Enter the queue no:\t");
    scanf("%d", &n);

    // Check for queue underflow (minimal error handling)
    if (s.f[n - 1] == s.r[n - 1]) {
        printf("Underflow\n");
        return;
    }

    printf("%d is deleted\n", s.a[++s.f[n - 1]]);
}

void display() {
    int n;
    printf("Enter the queue no:\t");
    scanf("%d", &n);

    // Check for queue underflow (minimal error handling)
    if (s.f[n - 1] == s.r[n - 1]) {
        printf("Underflow\n");
        return;
    }

    for (int i = s.f[n - 1]+1; i <= s.r[n - 1]; i++) {
        printf("%d\n", s.a[i]);
    }
}

int main() {
    int num, op;
    printf("Enter the number of queues: ");
    scanf("%d", &num);
    create(num);

    while (1) {
        printf("1-ADD 2-DELETE 3-DISPLAY 4-EXIT\n");
        scanf("%d", &op);

        if (op == 4) {
            break;
        }

        switch (op) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}*/