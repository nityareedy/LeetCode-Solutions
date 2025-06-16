/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map <int,map<int, multiset<int>>> nodes;
        queue <pair<TreeNode*,pair<int,int>>> pending;
        pending.push({root,{0,0}});
        while(!pending.empty()){
            auto p=pending.front();
            pending.pop();
            TreeNode *current= p.first;
            int x=p.second.first;
            int y=p.second.second;
            nodes[x][y].insert(current->val);
            if(current->left){
                pending.push({current->left,{x-1,y+1}});

            }
            if(current->right){
                pending.push({current->right,{x+1,y+1}});

            }
          

        }
          vector<vector<int>> ans;
            for(auto p:nodes){
                vector<int> col;
                for(auto q:p.second){
                    col.insert(col.end(),q.second.begin(),q.second.end());
                }
            ans.push_back(col);
            }
            return ans;
        
    }
};
