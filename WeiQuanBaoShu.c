//
// Created by zxuu on 2020/1/3.
//
/*
 * N 个人围成一圈顺序编号，从1 号开始按1、2、3 顺序报数，报3 者退出圈外，其余的人再从
 * 1、2、3 开始报数，报3 的人再退出圈外，依次类推。请按退出顺序输出每个退出人的原序号。
 * 要求使用环行链表编程。
 *
 * 输入描述：
 * 输入第一行为整数m表示有m组测试数据，接下来m行每行一个整数N，N不超过50。
 * 输出描述：
 * 输出m行，每行表示题目所求，用空格隔开。
 * 输入：
 * 1
 * 4
 * 输出：
 * 3 2 4 1
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SQList{
    int data;
    struct SQList *next;
} SQListNode,*SQList;
void func(int x){
    SQList p = NULL;
    SQList head = NULL;
    for (int i = 1; i <= x; i++) {
        SQList s = (SQList) malloc(sizeof(SQListNode));
        s->data = i;
        s->next = NULL;
        if (p == NULL) {
            p = s;
            head = s;
        } else{
            p->next = s;
            p = s;
        }
    }
    p->next = head;//链表建立完了

    p = head;
    SQList pre = head;
    p = p->next;
    int n = 1;

    bool y = true;
    while (y) {
        if (p==pre) {
            printf("%d ", p->data);
            free(p);
            y=false;
        }
        n++;
        if (n % 3 != 0) {
            pre = p;
            p = p->next;
        }
        if (n % 3 == 0) {
            printf("%d ", p->data);
            SQList q=p;
            pre->next = p->next;
            p = pre->next;

            free(q);
            n=0;
        }
    }
}
int main(){
    int n = 0;
    scanf("%d", &n);
    int a[n];
    for (int k = 0; k < n; k++) {
        scanf("%d", &a[k]);
    }
    for (int i = 0; i < n; i++) {
        func(a[i]);
        printf("\n");
    }
    return 0;
}
