class Solution {
public:
    string convertToTitle(int columNumber) {
        string ans="";
        while(columNumber>0){
            columNumber--;
            ans= (char(columNumber%26+int('A')))+ans;
            columNumber/=26;

        }
        return ans;
        
    }
};
