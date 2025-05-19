class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set <int> store;
        int length=0;
        for(int i =0;i<nums.size();i++){
            length=store.size();
            store.insert(nums[i]);
            if(length==store.size()){
                return nums[i];
            }
        }
        return 0;

        }
        
    
};
