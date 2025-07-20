class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
         vector<vector<int>> visited=grid;

        queue<pair<int,int>> s;

       for(int i=0;i<grid[0].size();i++){
        if(grid[0][i]==1){
            s.push({0,i});
            visited[0][i]=0;
        }
       }
        for(int i=0;i<grid[0].size();i++){
        if(grid[grid.size()-1][i]==1){
            s.push({grid.size()-1,i});
            visited[grid.size()-1][i]=0;
        }
       }
       for(int i=0;i<grid.size();i++){
        if(grid[i][0]==1){
            s.push({i,0});
            visited[i][0]=0;
        }
       }
       for(int i=0;i<grid.size();i++){
        if(grid[i][grid[0].size()-1]==1){
            s.push({i,grid[0].size()-1});
            visited[i][grid[0].size()-1]=0;
        }
       }
       while(s.size()!=0){
            int i=s.front().first;
            int j=s.front().second;
            s.pop();
            if(i+1<grid.size() && visited[i+1][j]!=0&&grid[i+1][j]==1){
                s.push({i+1,j});
                visited[i+1][j]=0;
            }
            if(j+1<grid[0].size()&&visited[i][j+1]!=0&&grid[i][j+1]==1){
                s.push({i,j+1});
                visited[i][j+1]=0;
            }
            if(i-1>=0&&visited[i-1][j]!=0&&grid[i-1][j]==1){
                s.push({i-1,j});
                visited[i-1][j]=0;
            }
            if(j-1>=0 &&visited[i][j-1]!=0&&grid[i][j-1]==1){
                s.push({i,j-1});
                visited[i][j-1]=0;
            }

       }
       int count=0;
       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(visited[i][j]==1) count++;
        }
       }
        return count;
    }
};
