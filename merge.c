#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node*next;
}node;

node*merge(node*l1,node*l2){
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    node*l,*p;
    if(l1->info<l2->info){
        l=p=l1;
        l1=l1->next;
    }
    else{
          l=p=l2;
        l2=l2->next;
    }
    while(l1!=NULL && l2!=NULL){
        if(l1->info<l2->info){
            p->next=l1;
            l1=l1->next;
            p=p->next;
        }
        else{
             p->next=l2;
            l2=l2->next;
            p=p->next;
        }
    }
    if(l1==NULL){
        p->next=l2;
    }
    else{
        p->next=l1;
    }
    return l;
}