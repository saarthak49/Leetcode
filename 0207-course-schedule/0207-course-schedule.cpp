class Solution {
public:
    
    void dfs(vector<vector<int> > &graph, vector<bool> &vis, int u, bool &isCyclePresent, unordered_map<int, int> &mp)
    {
        vis[u] = true;
        mp[u] = 1;
        int n = graph[u].size();
        for(int i = 0; i<=n-1; i++)
        {
            if(vis[graph[u][i]] && mp.find(graph[u][i]) != mp.end() )
            {
                isCyclePresent = true;
                return;
            }
            else if(!vis[graph[u][i]])
            {
                dfs(graph, vis, graph[u][i], isCyclePresent, mp);
            }
        }
        // vis[u] = false;
        mp.erase(mp.find(u));
    }
    
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int> > graph;
        for(int i = 0; i<=numCourses - 1; i++)
        {
            vector<int> temp;
            graph.push_back(temp);
        }
        
        int n = prerequisites.size();
        for(int i = 0; i<=n-1; i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            graph[u].push_back(v);
        }
        
        bool isCyclePresent = false;
        unordered_map<int, int> mp;
        
        
        vector<bool> vis(numCourses, false);
        
        for(int i = 0; i<=numCourses - 1; i++)
        {
            if(!vis[i])
            {
                dfs(graph, vis, i, isCyclePresent, mp);
                if(isCyclePresent)
                    return false;
            }
        }
        
        return true;
    }
};









    
    
    