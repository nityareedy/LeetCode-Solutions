class Solution {
public:
    int recursiveCall(int &ans,int m,int n,vector<vector<int>> &dp){
        if(m==0 && n==0){
            return 1;
        }
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int x=recursiveCall(ans,m-1,n,dp);
        int y=recursiveCall(ans,m,n-1,dp);
        return dp[m][n]=x+y;
        

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        // dp[0][0]=1;
        // dp[0][1]=1;
        // dp[1][0]=1;
        for(int i=0;i<n;i++){
            dp[0][i]=1;

        }
        for(int j=0;j<m;j++){
            dp[j][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        // int ans=0;
        // recursiveCall(ans,m-1,n-1,dp);
        // return dp[m-1][n-1];

        
    }
};
