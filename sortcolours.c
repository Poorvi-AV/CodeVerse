void swap(int *a,int*b){
    int temp= *a;
    *a=*b;
    *b=temp;
}
void sortColors(int* nums, int numsSize) {
  int low=0, mid=0, high= (numsSize-1);
  while (mid<=high){
    if(nums[mid]==0){
        swap(&nums[low],&nums[mid]);
        mid++;
        low++;
    }
    else if(nums[mid]==1) mid++;
    else {
        swap(&nums[high],&nums[mid]);
        high--;
    }
  }
}