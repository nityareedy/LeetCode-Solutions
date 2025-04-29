class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> visited(board.size(),vector<char>(board[0].size(),'X'));

        stack<pair<int,int>> s;

       for(int i=0;i<board[0].size();i++){
        if(board[0][i]=='O'){
            s.push({0,i});
            visited[0][i]='O';
        }
       }
        for(int i=0;i<board[0].size();i++){
        if(board[board.size()-1][i]=='O'){
            s.push({board.size()-1,i});
            visited[board.size()-1][i]='O';
        }
       }
       for(int i=0;i<board.size();i++){
        if(board[i][0]=='O'){
            s.push({i,0});
            visited[i][0]='O';
        }
       }
       for(int i=0;i<board.size();i++){
        if(board[i][board[0].size()-1]=='O'){
            s.push({i,board[0].size()-1});
            visited[i][board[0].size()-1]='O';
        }
       }
       while(s.size()!=0){
            int i=s.top().first;
            int j=s.top().second;
            s.pop();
            if(i+1<board.size() && visited[i+1][j]=='X' && board[i+1][j]=='O'){
                s.push({i+1,j});
                visited[i+1][j]='O';
            }
            if(j+1<board[0].size() && visited[i][j+1]=='X' && board[i][j+1]=='O'){
                s.push({i,j+1});
                visited[i][j+1]='O';
            }
            if(i-1>=0 && visited[i-1][j]=='X' && board[i-1][j]=='O'){
                s.push({i-1,j});
                visited[i-1][j]='O';
            }
            if(j-1>=0 && visited[i][j-1]=='X' && board[i][j-1]=='O'){
                s.push({i,j-1});
                visited[i][j-1]='O';
            }

       }
       board=visited;
       return;


        
    }
};
