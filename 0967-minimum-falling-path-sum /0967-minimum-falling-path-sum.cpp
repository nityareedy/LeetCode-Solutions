class Solution {
public:
    // int recursiveCall(vector<vector<int>> matrix, int m,int
    // last,vector<vector<int>> &dp){
    //     if(m==0){
    //         int mini=INT_MAX;
    //        for(int i=0;i<matrix.size();i++){
    //             if(i==last || i==last-1|| i==last+1)
    //             mini=min(mini,matrix[0][i]);
    //        }
    //        return mini;

    //     }
    //     int mini=INT_MAX;
    //     for(int i=0;i<matrix.size();i++){

    //         if(i==last||i==last-1||i==last+1||last==-1){
    //             mini=min(mini,matrix[m][i]+recursiveCall(matrix,m-1,i,dp));
    //             cout<<endl;
    //         }

    //     }
    //     return mini;

    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();    
        int m = matrix[0].size(); 

        vector<int> prev(m,0); 
        vector<int> cur(m, 0); 
        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + prev[j];

                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += prev[j - 1];
                } else {
                    leftDiagonal += 1e8; 
                }

                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) {
                    rightDiagonal += prev[j + 1];
                } else {
                    rightDiagonal += 1e8; 
                }

                cur[j] = min(up, min(leftDiagonal, rightDiagonal));
            }

            
            prev = cur;
        }

        int maxi = INT_MAX;
        for (int j = 0; j < m; j++) {
            maxi = min(maxi, prev[j]);
        }

        return maxi;
    }
};
