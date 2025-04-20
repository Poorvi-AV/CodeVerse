#define MAX(a, b) ((a) > (b) ? (a) : (b))
int trap(int* height, int heightSize) {
    if(height==NULL) return 0;
    int l=0,r=heightSize-1,result =0;
    int leftmax=height[l];
    int rightmax=height[r];
    while(l<r){
        if(leftmax<rightmax){
            l++;
            leftmax= MAX(leftmax,height[l]);
            result +=leftmax-height[l];
        }
        else{
            r--;
            rightmax= MAX(rightmax,height[r]);
            result +=rightmax-height[r];
        }
    }
    return result;
}