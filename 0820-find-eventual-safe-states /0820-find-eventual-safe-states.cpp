class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> reversed(graph.size());
        vector<int> indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(int it=0;it<graph[i].size();it++){
                reversed[graph[i][it]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        while(q.size()!=0){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:reversed[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
