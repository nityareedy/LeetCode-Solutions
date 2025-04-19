class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> solution;
         sort(nums.begin(),nums.end());
         for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    solution.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;

                }



            }
         }
        //  set<vector<int>> check;
        // for(int i=0;i<nums.size()-2;i++){
        //     for(int j=i+1;j<nums.size()-1;j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 int size=check.size();
        //                  vector<int> temp;
        //                 temp.push_back(nums[i]);
        //                 temp.push_back(nums[j]);
        //                 temp.push_back(nums[k]);
        //                 sort(temp.begin(),temp.end());
        //                 check.insert(temp);
                        
        //                 if(size!=check.size()){

                       
        //                 solution.push_back(temp);
        //                 }
                        
                        
        //             }

        //         }

        //     }

        // }
        return solution;
    }
};
