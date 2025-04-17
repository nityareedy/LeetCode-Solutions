class Solution {
public:
    int reverse(int x) {
        unsigned long long int rev=0;
        unsigned long long rem=0;
        if(x<0){
            if(x==INT_MIN){
                return 0;
            }
           x=-x;
            while(x>0){
            rem=x%10;
            // cout << rem ;
            if(rev<=INT_MAX/10){

            rev=rev*10+rem;
            x=x/10;
            }
            else{
                return 0;
            }
        }
        rev=-rev;

        }
        else{
             while(x>0){
            rem=x%10;
            // cout << rem ;
            if(rev<=INT_MAX/10){

            rev=rev*10+rem;
            x=x/10;
            }
            else{
                return 0;
            }
        }
        }
       
        return rev;
        
    }
};
