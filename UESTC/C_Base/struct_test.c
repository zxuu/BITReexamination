#include <stdio.h>
#include <stdlib.h>

struct Node{
    char num[10];
    int score;
};

int main(){
    struct Node node[3];
    struct Node *p;
    for (int i=0;i<3;i++) {
        scanf("%s %d", node[i].num, &node[i].score);
    }
    p = node;
    for (p = node; p < p + 3; p++) {
        printf("%s  %d\n", (*p).num, (*p).score);
    }
    free(p);
    return 0;
}