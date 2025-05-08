int search(int* nums, int numsSize, int target) {
    int s=0,l=numsSize-1;
    int mid;
    while(s<=l){
        mid = (s+l)/2;
        if(nums[mid]==target){
         return mid;
        } 
        else if(nums[mid]>target) l=mid-1;
        else s=mid+1;
    }
    return -1;
}