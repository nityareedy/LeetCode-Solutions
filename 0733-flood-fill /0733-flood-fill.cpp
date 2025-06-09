class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if(image[sr][sc]==color) return image;
        stack<pair<int,int>> s;
        s.push({sr,sc});
        int prevColor=image[sr][sc];
        while(s.size()!=0){
            int i=s.top().first;
            int j=s.top().second;
            cout<<i<<j<<endl;
            image[i][j]=color;
            s.pop();
            if(i-1>=0 && image[i-1][j]==prevColor){
                s.push({i-1,j});
                image[i-1][j]=color;

            }
            if(i+1<image.size() && image[i+1][j]==prevColor){
                s.push({i+1,j});
                        image[i+1][j]=color;

            }
            if(j+1<image[i].size()&&image[i][j+1]==prevColor){
                s.push({i,j+1});
                            image[i][j+1]=color;

            }
            if(j-1>=0 && image[i][j-1]==prevColor){
                s.push({i,j-1});
                            image[i][j-1]=color;

            }
            
        }
        return image;
        
    }
};
