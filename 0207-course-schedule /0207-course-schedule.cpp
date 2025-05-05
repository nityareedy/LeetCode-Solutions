class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            for(int j=1;j<prerequisites[i].size();j++){
                adj[prerequisites[i][j]].push_back(prerequisites[i][0]);
            }
        }

        
        vector<int> indegree(numCourses,0);
        queue<int> q;
        vector<int> temp;


    


       	for (int i = 0; i < numCourses; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}
       for (int i = 0; i < numCourses; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
    while (!q.empty()) {
			int node = q.front();
			q.pop();
			temp.push_back(node);
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

        if(temp.size()!=numCourses) return false; 
        return true;
        
    }
};
