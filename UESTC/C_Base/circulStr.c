//
//寻找旋转排序数组中最小的值
//
#include <stdio.h>
#include <stdlib.h>

int main(){
    int nums[10]={3,4,5,6,7,8,9,0,1,2};
    int l=0;
    int r=9;
    int mid = 0;
    if(nums[l]<nums[r]){
        return nums[l];
    }
    while(l<r){
        mid = (l + r) / 2;
        if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    printf("%d\n", nums[mid+1]);
}

