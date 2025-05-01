class Solution {
public:
    string reverseWords(string s) {


        int j=0;
        while(s[j]==' ') j++;


        vector<string> words;
        string temp="";
        for(int i=j;i<s.length();i++){

            if(s[i]==' '){
                if(temp!="") words.push_back(temp);
          
                temp="";
            }
            else{
                temp+=s[i];
            }

        }
        if(temp!="") words.push_back(temp);
        string ans="";
        for(int i=words.size()-1;i>=0;i--){
            cout<<words[i]<<endl;

            if(i!=0){

            ans+=words[i]+" ";
            }
            else{
                ans+=words[i];
            }
        }
        return ans;
        
    }
};
