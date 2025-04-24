class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       
        int len=0;
        for(int i=0;i<board.size();i++){
             set<char> row;
            set <char> column;
            for(int j=0;j<board.size();j++){
                len=row.size();
                if(isdigit(board[i][j])){

                row.insert(board[i][j]);
                if(row.size()==len){
                    cout<<j<<i<<endl;

                    return false;
                }
                }
                len=column.size();
                if(isdigit(board[j][i])){
                    column.insert(board[j][i]);
                    if(column.size()==len){
                        cout<<j<<i<<endl;
                        return false;
                    }

                }
                
                

            }
          
        }
        for (int i = 0; i < 9; i++) {
    set<char> temp;
    cout << "Iteration" << i << endl;
    int row_start = (i / 3) * 3; 
    int col_start = (i % 3) * 3; 
    
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            cout << col_start + k << " " << row_start + j << endl;
            len = temp.size();
            
            if (isdigit(board[col_start + k][row_start + j])) {
                temp.insert(board[col_start + k][row_start + j]);
                if (len == temp.size()) {
                    return false;
                }
            }
        }
    }
}

        // for(int i=0;i<board.size();i=i+3){
        //     set<char> temp;
        //     cout<<"Iteration"<<i<<endl;
        //     for(int j=0;j<3;j++){
                
        //         for(int k=0;k<3;k++){
        //             cout<<k<<" "<<j+i<<endl;
        //             len=temp.size();

        //             if(isdigit(board[k][j+i])){

        //             temp.insert(board[k][j+i]);
        //             if(len==temp.size()){
        //                 return false;
        //             }
        //             }
                    
        //         }



        //     }
        // }
        //   for(int i=0;i<board.size();i=i+3){
        //     set<char> temp;
        //     cout<<"Iteration"<<i<<endl;
        //     for(int j=0;j<3;j++){
                
        //         for(int k=3;k<6;k++){
        //             cout<<k<<" "<<j+i<<endl;
        //             len=temp.size();

        //             if(isdigit(board[k][j+i])){

        //             temp.insert(board[k][j+i]);
        //             if(len==temp.size()){
        //                 return false;
        //             }
        //             }
                    
        //         }



        //     }
        // }
        //  for(int i=0;i<board.size();i=i+3){
        //     set<char> temp;
        //     cout<<"Iteration"<<i<<endl;
        //     for(int j=0;j<3;j++){
                
        //         for(int k=6;k<9;k++){
        //             cout<<k<<" "<<j+i<<endl;
        //             len=temp.size();

        //             if(isdigit(board[k][j+i])){

        //             temp.insert(board[k][j+i]);
        //             if(len==temp.size()){
        //                 return false;
        //             }
        //             }
                    
        //         }



        //     }
        // }
        //   for(int i=0;i<board.size();i=i+3){
        //     set<char> temp;
        //     for(int j=3;j<6;j++){
                
        //         for(int k=3;k<6;k++){
        //             len=temp.size();
        //             temp.insert(board[k][j]);
        //             if(len==temp.size()){
        //                 return false;
        //             }
                    
        //         }



        //     }
        // }
        //   for(int i=0;i<board.size();i=i+3){
        //     set<char> temp;
        //     for(int j=6;j<9;j++){
                
        //         for(int k=6;k<9;k++){
        //             len=temp.size();
        //             temp.insert(board[k][j]);
        //             if(len==temp.size()){
        //                 return false;
        //             }
                    
        //         }



        //     }
        // }
        return true;
        
    }
};
