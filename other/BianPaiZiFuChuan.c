#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char s[20];
    struct StrNode* next;
}StrNode,*StrList;
int main(){
    int n, i, k;
    scanf("%d", &n);
    StrList head, q;
    getchar();
    for (i = 0; i < n; i++) {
        StrList s = (StrList) malloc(sizeof(StrNode));
        gets(s->s);
        k = 0;
        if (i == 0) {
            head = s;
            head->next = NULL;
        } else{
            s->next = head;
            head = s;
        }
        q = head;
        while (q && k < 4) {
            k++;
            printf("%d=%s ", k, q->s);
            q = q->next;
        }
        printf("\n");
    }
}

