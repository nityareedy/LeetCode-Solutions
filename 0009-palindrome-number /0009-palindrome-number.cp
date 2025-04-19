class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else{
            int dup=x;
            int rem=0;
            long palin=0;
            while(dup>0){
                rem=dup%10;
                palin=palin*10+rem;
                dup=dup/10;
            }
            if(palin==x){
                return true;
            }
            else{
                return false;
            }
        }
        
    }
};
