int majorityElement(int* nums, int numsSize) {
    int a=nums[0],count=0;
    for(int i=0;i<numsSize;i++){
         if(count==0){
            a=nums[i];
        }
        if(nums[i]==a){
            count++;
        }
        else{
            count--;
        }
       
    }
    return a;
}