class Solution {
public:
    int recursion(int index, vector<int> &coins, int amount,vector<vector<int>>& dp){
        if(index==0){
            if(amount % (coins[0])==0) return amount/coins[0];
            return 1e9;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int noTake=0+recursion(index-1,coins,amount,dp);
        int take=1e9;
        if(coins[index]<=amount) take=1+recursion(index,coins,amount-coins[index],dp);



        return dp[index][amount]=min(take,noTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        // if(amount==0) return amount;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        for(int target=0;target<=amount;target++){

            if(target%coins[0]==0) dp[0][target]=target/coins[0];
            else dp[0][target]=1e9;

        }
        for(int index=1;index<coins.size();index++){
            for(int target=1;target<=amount;target++){
                int noTake=0+dp[index-1][target];
                int take=1e9;
                if(coins[index]<=target) take=1+dp[index][target-coins[index]];
                dp[index][target]=min(take,noTake);
            }
        }

        // int ans= recursion(coins.size()-1,coins,amount,dp);
        // return ans<1e9?ans:-1;
        return dp[coins.size()-1][amount]<1e9?dp[coins.size()-1][amount]:-1;

        
    }
};
