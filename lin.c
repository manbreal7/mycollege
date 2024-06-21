#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node*next;
}node;
node*insend(node*start){
    int ele;
    node*temp=(node*)malloc(sizeof(node));
    printf("enter element to insert\n");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(start==NULL){
        start=temp;
        return start;
    }
    node*t=start;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=temp;
    return start;
    
}
node*insbeg(node*start){
     
    node*temp=(node*)malloc(sizeof(node*));
    printf("enter element to insert\n");
    scanf("%d",&temp->info);
    if(start==NULL){
        start=temp;
        return start;
    }
  //  node*t=start;
     temp->next=start;
    start=temp;
  return start;
}
void display(node* start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* t = start;
    while (t != NULL) {
        printf("%d->", t->info);
        t = t->next;
    }
    printf("NULL\n");
}
node* delbeg(node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }
    node* t = start;
    start = t->next; 
    free(t); 
    return start;
}
node* delend(node*start){
     if (start == NULL) {
        printf("List is empty\n");
        return start;
    }
    node*pre;
    node*cur=start;
    while(cur->next!=NULL){
       pre=cur;
      cur=cur->next;
    }
    free(cur);
    pre->next=NULL;
    return start;
    
}
node* after(node*start){
    int ele;
     
    if(start==NULL){
        printf("List is empty");
        return start;
    }
    printf("enter element to be inserted after");
    scanf("%d",&ele);
        node*cur=start;
    //node*prev;
    while(cur!=NULL && cur->info!=ele ){
      //  prev=cur;
        cur=cur->next;
    }
    if(cur==NULL){
        printf("ELEMENT NOT FOUND\n");
        return start;
        
    }
     node*temp=(node*)malloc(sizeof(node));
     printf("element to be inserted\n");
     scanf("%d",&temp->info);
     
   temp->next=cur->next;
   cur->next=temp;
     return start;
    
}
node* before(node* start) {
    int ele;

    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }

    printf("Enter element to be inserted before: ");
    scanf("%d", &ele);

    node* cur = start;
    node* prev = NULL;

    // Special case: Insert at the beginning
    if (cur->info == ele) {
        node* temp = (node*)malloc(sizeof(node));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            return start;
        }

        printf("Enter element to be inserted: ");
        scanf("%d", &temp->info);

        temp->next = start;
        start = temp;
        return start;
    }

    while (cur != NULL && cur->info != ele) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("ELEMENT NOT FOUND\n");
        return start;
    }

    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return start;
    }

    printf("Enter element to be inserted: ");
    scanf("%d", &temp->info);

    temp->next = cur;
    prev->next = temp;

    return start;
}
node* reverse(node* start) {
    node* p = start;
    node* q = NULL;
    node* r = NULL;

    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }

    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    start = q;
    return start;
}
void sort(node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    
    node *i, *j;
    int temp;
    
    for (i = start; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}



int main(){
    int op;
    node*start=NULL;
    while(1){
        printf("enter choice\n");
        printf("1-Insert end 2-insert beg 3-Display 4-DELETE START :5-DELETE -END 6-ENTER AF 7-BEF 8-reverse 9-sort 10-exit\n ");
        scanf("%d",&op);
        if(op==10){
            break;
        }
        switch(op){
            case 1:start=insend(start);
            break;
            case 2:start=insbeg(start);
            break;
            case 3:display(start);
            break;
            case 4:start=delbeg(start);
            break;
            case 5:start=delend(start);
            break;
            case 6:start=after(start);
            break;
            case 7:start=before(start);
            break;
            case 8:start=reverse(start);
            break;
            case 9:sort(start);
            
        }
        
    }
    return 0;
}