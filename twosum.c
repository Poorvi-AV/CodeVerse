#include<stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j;
    int *result =(int*)malloc(2*sizeof(int));
    if(result==NULL||numsSize<2){
        *returnSize = 0;
        return  NULL;
    }
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                *returnSize=2;
                result[0] = i;
                result[1] = j;
                return result;
                free(result);
            }
        }
    }
     *returnSize= 0;
      free(result);
        return NULL;
}
