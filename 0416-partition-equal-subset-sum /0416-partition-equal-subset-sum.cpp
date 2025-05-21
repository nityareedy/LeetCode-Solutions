class Solution {
public:
 
    bool canPartition(vector<int>& nums) {
        long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        sum/=2;
   

        vector<vector<bool>> dp(nums.size(),vector<bool>(sum+1,false));
        for(int i=0;i<nums.size();i++){
            dp[i][0]=true;
        }
        if(nums[0]<=sum) dp[0][nums[0]]=true;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=sum;j++){
                bool notTake=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j) 
                take=dp[i-1][j-nums[i]];
                dp[i][j]=take|notTake;

            }
        }

        return dp[nums.size()-1][sum];

        
    }
};
