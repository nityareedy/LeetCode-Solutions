class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxLeft=0;
        int maxRight=0;
        int ans=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(maxLeft<height[left]) maxLeft=height[left];
                else{
                    ans=ans+maxLeft-height[left];


                }
                left++;
            }
            else{
                if(maxRight<height[right]) maxRight=height[right];
                else{
                    ans=ans+maxRight-height[right];
                }
                right--;
            }   
        }
        return ans;
    }
};
