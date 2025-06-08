class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int normalsum=0;
        int sum=0;
       
        vector <int> answer;

        for(int i=0;i<nums.size();i++){
            normalsum=normalsum+(i+1);
            sum=sum+nums[i];
        }
         int difference=normalsum-sum;
        
        set <int> store;
        int length=0;
        for(int i =0;i<nums.size();i++){
            length=store.size();
            store.insert(nums[i]);
            if(length==store.size()){
                answer.push_back(nums[i]);
                answer.push_back(nums[i]+difference);
                return answer;
              
            }
        }
        return answer;
        }
        
    
};
