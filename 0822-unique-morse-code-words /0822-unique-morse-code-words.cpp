class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        vector<string> morse = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
        set<string> ans;
        for(int i=0;i<words.size();i++){
            string s="";
            for(int j=0;j<words[i].length();j++){
                s+=morse[int(words[i][j]-'a')];
            }
            ans.insert(s);
        }
        return ans.size();
    }
};
