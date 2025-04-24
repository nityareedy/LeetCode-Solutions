class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set <int> s;
        for (int i = 0; i<nums.size(); i++){
            s.insert(nums[i]);
        }   

        int i = 1;
        while(s.count(i) != 0){
            i++;
        }
        return i;
    }
};
