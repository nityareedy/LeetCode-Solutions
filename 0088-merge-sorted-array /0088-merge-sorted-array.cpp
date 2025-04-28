class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        if(m==0){
            swap(nums1,nums2);
            return;
        }

        int index1=0;
        int index2=0;
        while(index1!=m)
        {
            if(nums1[index1]>nums2[index2]){
                while(index2<n && nums1[index1]>nums2[index2] ){
                    index2++;
                }
        
                swap(nums1[index1],nums2[index2-1]);

        
            }
                if(index2==1||index2==0){
                index1++;
                }
                index2=0;

        }
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
        
        
    }
};
