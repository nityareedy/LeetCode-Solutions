// class Solution {
// public:
//     int strongPasswordChecker(string password) {
//         int len=password.length();
//         int lower=0;
//         int upper=0;
//         int digit=0;
//         vector<int> why;
//         int consecutive=0;
//         int ans=0;
//           if(password[0]>='a' && password[0]<='z'){
//                 lower++;
//             }
//             else if(password[0]>='A' && password[0]<='B'){
//                 upper++;
//             }
//             else if(isdigit(password[0])){
//                 digit++;
//             }
//         for(int i=1;i<password.size();i++){
//             if(password[i]>='a' && password[i]<='z'){
//                 lower++;
//             }
//             else if(password[i]>='A' && password[i]<='Z'){
//                 upper++;
//             }
//             else if(isdigit(password[i])){
//                 digit++;
//             }

//             if(password[i]==password[i-1]){
//                 consecutive++;
//             }
//             else{
//                 if(consecutive>=2){

//                 cout<<consecutive<<endl;
//                 why.push_back(consecutive);
//                 }
                
//                 consecutive=0;
//             }
            
           
            
//         }
//         if(consecutive>=2){

//                 cout<<consecutive<<endl;
//                 why.push_back(consecutive);
//         }
//         cout<<upper<<" "<<lower<<" "<<digit<<endl;
//         cout<<why.size()<<endl;
       
//         if(upper==0){

//           if(why.size()==0){

//               if(len>19){

                
//             ans+=1;
//               }
//               else{
//                   len+=1;
//             ans+=1;

//               }
//             }else{
//                      if(len>19){

                
//             ans+=1;
//               }
//               else{
//                   len+=1;
//             ans+=1;

//               }

               
                    
//                 why[0]=why[0]-3;
//                 if(why[0]<=0){

//                 why.erase(why.begin()+0);
//                 }
//             }
//         }
//         if(lower==0){
//             if(why.size()==0){
                
//             if(len>19){

                
//             ans+=1;
//               }
//               else{
//                   len+=1;
//             ans+=1;

//               }
//             }else{
//                    if(len>19){

                
//             ans+=1;
//               }
//               else{
//                   len+=1;
//             ans+=1;

//               }
               
                    
//                 why[0]=why[0]-3;
//                 if(why[0]<=0){

//                 why.erase(why.begin()+0);
//                 }
//             }
//         }
//         if(digit==0){
//             if(why.size()==0){

//             if(len>19){

                
//             ans+=1;
//               }
//               else{
//                   len+=1;
//             ans+=1;

//               }
//             }
//             else{
//                     if(len>19){

                
//             ans+=1;
//               }
//               else{
//                   len+=1;
//             ans+=1;

//               }

               
                    
//                 why[0]=why[0]-3;
//                 if(why[0]<=0){

//                 why.erase(why.begin()+0);
//                 }
//             }
//         }
//         cout<<len<<ans<<endl;
//         for(int i=0;i<why.size();i++){
//             cout<<"here"<<endl;
//                 if(len<6){
                    
//                     if(why[i]%3!=0){


//                     ans+=why[i]/3+1;
//                      len+=why[i]/3+1;
//                     }
//                     else{
//                         ans+=why[i]/3;
//                      len+=why[i]/3;

//                     }
//                 }
//                 else{
//                      if(why[i]%3!=0){


//                     ans+=why[i]/3+1;
//                      len-=why[i]/3+1;
//                     }
//                     else{
//                         ans+=why[i]/3;
//                      len-=why[i]/3;

//                     }

//                 }


//             }

//         if(len<6){
            

//             ans+=6-len;
            
//         }
//         if(len>20){
//             ans+=len-20;
//         }
//         return ans;
        
//     }
// };
class Solution {
public:
    
    bool islower(char &c)
    {
        return c>='a' && c<='z';
    }
    bool isupper(char &c)
    {
        return c>='A' && c<='Z';
    }
    bool isdigit(char &c)
    {
        return c>='0' && c<='9';
    }
    
    int strongPasswordChecker(string s ) {
        int n=s.length();
        
        bool lo,up,di;
        lo=up=di=false;
        
        if(n<=20)
        {
            int need_replaces=0,can_be_replaced=0;
            int need_add=(6-n)<0 ? 0:6-n;
            for(int i=0;i<n;)
            {
                if(!lo && islower(s[i]))
                    lo=true;
                if(!up && isupper(s[i]))
                    up=true;
                if(!di && isdigit(s[i]))
                    di=true;
                
                int tmp=1;
                int j=i+1;
                while(j<n && s[i]==s[j])
                {
                    j++;
                }
                tmp=(j-i);
                can_be_replaced+=tmp/3;
                
                i=j;
            }
            
            if(!lo) need_replaces+=1;
            if(!up) need_replaces+=1;
            if(!di) need_replaces+=1;
            
            int replaces=max(can_be_replaced,need_replaces);
            return max(need_add,replaces);
        }
        else
        {
            int min_deletion=n-20,need_replaces=0;
            int curr_length=0;
            priority_queue<int>pq;
            
            for(int i=0;i<n;)
            {
                if(!lo && islower(s[i]))
                    lo=true;
                if(!up && isupper(s[i]))
                    up=true;
                if(!di && isdigit(s[i]))
                    di=true;
                
                int temp=1;
                int j=i+1;
                while(j<n && s[i]==s[j])
                {
                    j++;
                }
                temp=(j-i);
                if(temp>=2)
                {
                    curr_length+=2;
                    pq.push(temp-2);
                }
                else
                    curr_length+=1;
                
                i=j;
            }
            
            if(!lo) need_replaces+=1;
            if(!up) need_replaces+=1;
            if(!di) need_replaces+=1;
            
            if(curr_length>=20)
                return min_deletion+need_replaces;
            else
            {
                int min_replacement=0;
                while(curr_length<20)
                {
                    int x=pq.top();
                    curr_length+=min(3,x);
                    min_replacement+=1;
                }
                
                min_replacement=max(min_replacement,need_replaces);
                return min_deletion+min_replacement;
            }
            
        }
            
        return 0;
    }
};
