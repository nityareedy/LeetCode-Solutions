class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int index=1;
       for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]){

            continue;
        }
        else {
            while(i<nums.size()-1&&nums[i]==nums[i+1]){
            i++;
        }
            swap(nums[i],nums[index]),index++;
            }
       }
       return index;
    }
};
