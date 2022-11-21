class Solution {
public:
    
    
    
    
    
    
    bool getBobPath(vector<int> graph[], int bob, bool vis[], vector<int> &bobPath)
    {
        if (bob == 0) {
            bobPath.push_back(bob);
            return 1;
        }
        
        vis[bob] = 1;
        bool flag = 0;
        for (auto it: graph[bob]) {
            if (!vis[it])
                flag = getBobPath(graph, it, vis, bobPath);
            
            if (flag) {
                bobPath.push_back(bob);
                return 1;
            }
        }
        return 0;
    }
    
    
    int findOptimal(vector<int> graph[], int source, vector<int> &amount, bool vis[])
    {
        int res = INT_MIN;
        vis[source] = true;
        // cout<<"Called for : "<<source<<endl;
        for(auto it: graph[source])
        {
            
            if(!vis[it])
                res = max(res, findOptimal(graph, it, amount, vis));
        }
        if(res == INT_MIN)
            return amount[source];
        return amount[source] + res;
    }
    
    
    
    
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        // prepare adjacency
        int n = edges.size();
        vector<int> temp;
        vector<int> graph[n+2];
        
        for(int i = 0; i<=n-1; i++)
        {
            int src = edges[i][0];
            int dst = edges[i][1];
            graph[src].push_back(dst);
            graph[dst].push_back(src);
        }
        
        
        // find the path of bob
        bool vis[n+2];
        memset(vis, false, sizeof(vis));
        
        vector<int> bobPath;
        getBobPath(graph, bob, vis, bobPath);
        
        
        
        
        // then update the values of amount based on bob's path
        int bobPathLength = bobPath.size();
        reverse(bobPath.begin(), bobPath.end());
        for(int i = 0; i<=bobPathLength / 2 - 1; i++)
            amount[bobPath[i]] = 0;
        
        if(bobPathLength % 2 == 1)
        {
            amount[bobPath[(bobPathLength - 1)/2]] /= 2;
        }
        
        
        
        memset(vis, false, sizeof(vis));
        
        // find the optimal for alice
        
        int optimal = findOptimal(graph, 0, amount, vis);
        return optimal;
        // return 0;
        
    }
};