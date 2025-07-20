class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int curr=0;
        int ones=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1){
                    ones++;

                }
            }
        }
        while(q.size()!=0){
            auto current=q.front();
            int i=current.first.first;
            int j=current.first.second;
            curr=current.second;
            cout<<i<<j<<curr<<endl;
            if(i-1>=0){
                if(grid[i-1][j]==1){
                    q.push({{i-1,j},curr+1});
                    grid[i-1][j]=2;
                    ones--;
                }

            }
            if(j-1>=0){
                if(grid[i][j-1]==1){
                    q.push({{i,j-1},curr+1});
                     grid[i][j-1]=2;
                    ones--;
        
                }

            }
            if(j+1<grid[0].size()){
                if(grid[i][j+1]==1){
                    q.push({{i,j+1},curr+1});
                 grid[i][j+1]=2;
                 ones--;
                }
            }
            if(i+1<grid.size()){
                if(grid[i+1][j]==1){
                    q.push({{i+1,j},curr+1});
                     grid[i+1][j]=2;
                     ones--;
                }
            }
           
            q.pop();
        }
    return ones==0?curr:-1;
        
    }
};
