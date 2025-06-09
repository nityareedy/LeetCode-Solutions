class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        for(int i=0;i<pairs.size();i++){
            for(int j=i+1;j<pairs.size();j++){
                if(pairs[i][1]>pairs[j][1]) swap(pairs[i],pairs[j]);
            }
        }
        int endTime=pairs[0][1];
        int ans=1;
        for(int i=1;i<pairs.size();i++){
            cout<<pairs[i][0]<<pairs[i][1]<<endl;
            if(pairs[i][0]>endTime){ endTime=pairs[i][1];ans++;}
        }
        return ans;
    }
};
