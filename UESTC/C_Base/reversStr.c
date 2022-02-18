//
// Created by z1825 on 2-10 0010.
//翻转链表
//
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node *revers(node *l,int m,int n){
    node *pre, *p, *q, *t;
    int i=1;
    p=l->next;
    pre = l;
    while(i<m){
        pre = p;
        p = p->next;
        ++i;
    }
    t=p;
    if(m<n){
        p = p->next;
        ++i;
    }
    while (i<=n){
        q=p;
        p = p->next;
        ++i;
        q->next = pre->next;    //翻转链表
        pre->next = q;
    }
    t->next = p;    //后面连接上
    return l;
}
void main(){
    node *p, *l, *q;
    int i;
    p = (node *) malloc(sizeof(node));
    p->data = 0;
    l=p;
    q=p;
    for(i=1;i<=5;i++){
        p = (node *) malloc(sizeof(node));
        p->data = i;
        q->next = p;
        q = q->next;
    }
    p->next = NULL;
    revers(l, 2, 4);
    for(i=1;i<=6;i++){
        printf("%d_", l->data);
        l = l->next;
    }
}