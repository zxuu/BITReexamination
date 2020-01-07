//
// Created by zxuu on 2020/1/4.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag[51];
void xk(int n)
{
    int k=n;
    int j=1,i=1;
    while(k>1)
    {
        if(flag[i]==1)
        {
            if(i==n)
                i=1;
            else
                i++;
            continue;
        }
        if(flag[i]==0&&j==3)
        {
            flag[i]=1;
            printf("%d ",i);
            k--;
        }
        if(i==n)
            i=1;
        else
            i++;
        if(j==3)
            j=1;
        else
            j++;
    }
    for(i=1;i<=n;i++)
        if(flag[i]==0)
            printf("%d\n",i);
}
int main()
{
    int m,n;
    scanf("%d",&m);
    while(m--)
    {
        memset(flag,0,sizeof(flag));
        scanf("%d",&n);
        xk(n);
    }
}