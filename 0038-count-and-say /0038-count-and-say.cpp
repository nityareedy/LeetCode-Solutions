class Solution {
public:
    string rle(string ans){
        cout<<ans<<endl;
        if(ans=="1") return "11";
        string toSend;
        int count =0;
        for(int i=0;i<ans.length();i++){
            if(ans[i]==ans[i+1]){
                count++;
            }
            else{
                count++;
                cout<<count<<endl;
                char temp='0'+count;
                toSend+=temp;
                temp=ans[i];
                toSend+=temp;
                count=0;

            }

        }
        if(count>0){
            char temp='0'+count;
            toSend+=temp;
            int size=ans.length();
            temp=ans[size-1];
            toSend+=temp;
            count=0;


        }

        return toSend;

    }
    string countAndSay(int n) {
        
        string ans="1";
        if(n==1) return ans;
        else{
            while(n>1){
                n--;
                ans=rle(ans);
            }
        }
        return ans;
            
        
    }
};  
