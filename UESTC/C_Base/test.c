#include <stdio.h>
#include <string.h>

void swap(char **pa,char **pb){
    char *temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
void main(){
    char p[10]={"UESTC"};
    char q[] = {"xyz"};
    int i, j;
    i = 0;
    while (*(p+i)!='\0') i++;
    j=0;
    i++;
    while (*(q+j) != '\0'){
        *(p+i) = *(q+j);
        j++;
        i++;
    }
    printf("%s", p);
}