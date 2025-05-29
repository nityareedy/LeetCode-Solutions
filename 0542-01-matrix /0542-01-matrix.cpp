class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> distance(mat.size(),vector<int>(mat[0].size()));
        vector<vector<int>> visited(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0) 
                {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        while(q.size()!=0){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            distance[i][j]=dist;
             if(i-1>=0 && visited[i-1][j]==0){
                                        visited[i-1][j]=1;

                    q.push({{i-1,j},dist+1});

                    }
                 if(i+1<mat.size() && visited[i+1][j]==0){
                                            visited[i+1][j]=1;

                                    q.push({{i+1,j},dist+1});


                    }
                    if(j-1>=0  && visited[i][j-1]==0){
                                                visited[i][j-1]=1;

                                          q.push({{i,j-1},dist+1});



                    }
                    if(j+1<mat[i].size()  && visited[i][j+1]==0){
                        visited[i][j+1]=1;
                        q.push({{i,j+1},dist+1});



                    }

        }

        
        return distance;
    }
};
