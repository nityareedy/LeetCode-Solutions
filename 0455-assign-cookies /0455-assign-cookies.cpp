class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0;
        int currentIndex=0;
        for(int i=0;i<s.size();i++){
            for(int j=currentIndex;j<g.size();j++){
                if(s[i]>=g[j]) {
                    currentIndex=j+1;
                    count++;
                     break;  
                }
            }
        }
        return count;
    }
};
