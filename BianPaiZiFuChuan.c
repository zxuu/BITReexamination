#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char s[20];
    struct StrNode* next;
}StrNode,*StrList;
int main(){
    int n;
    scanf("%d", &n);
    StrList head;
    head = (StrList) malloc(sizeof(StrNode));
    head->next = NULL;
    for (int i = 0; i < n; i++) {
        StrList s = malloc(sizeof(StrNode));
        gets(s->s);
        s->next=head->next;
        head = s;
        StrList q=head;
        int i=0;
        while (q->next&&i<5) {
            i++;
            printf("%d=%s ", i, q->s);
            q=q->next;
        }
        printf("\n");
    }
}

