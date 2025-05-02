class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        k=k%nums.size();

        // while(k>0){
        //     int last=nums[nums.size()-1];
        //     for(int i=nums.size()-1;i>0;i--){
        //         nums[i]=nums[i-1];
        //     }
        //     nums[0]=last;
        //     k--;
        // }
        vector<int> temp;
        for(int i=nums.size()-k;i<nums.size();i++){
            temp.push_back(nums[i]);
            cout<<nums[i]<<endl;
        }
        for(int i=nums.size()-k-1;i>=0;i--){
            nums[i+k]=nums[i];
        }
        for(int i=0;i<temp.size();i++){
            nums[i]=temp[i];
        }
        
    }
};
