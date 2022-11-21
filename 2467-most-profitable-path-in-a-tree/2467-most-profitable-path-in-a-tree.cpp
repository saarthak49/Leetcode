class Solution {
public:
    
    
    
    
    
    
    bool getBobPath(vector<int> graph[], int bob, int p, vector<int> &bobPath)
    {
        if (bob == 0) {
            bobPath.push_back(bob);
            return true;
        }
        
        bool flag = flag;
        for (auto it: graph[bob]) {
            if (it != p)
                flag = getBobPath(graph, it, bob, bobPath);
            
            if (flag) {
                bobPath.push_back(bob);
                return true;
            }
        }
        return false;
    }
    
    
    int findOptimal(vector<int> graph[], int source, vector<int> &amount, int p)
    {
        int res = INT_MIN;
        for(auto it: graph[source])
        {
            
            if(it != p)
                res = max(res, findOptimal(graph, it, amount, source));
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
        
        
        
        vector<int> bobPath;
        getBobPath(graph, bob, -1, bobPath);
        
        
        
        
        // then update the values of amount based on bob's path
        int bobPathLength = bobPath.size();
        reverse(bobPath.begin(), bobPath.end());
        for(int i = 0; i<=bobPathLength / 2 - 1; i++)
            amount[bobPath[i]] = 0;
        
        if(bobPathLength % 2 == 1)
        {
            amount[bobPath[(bobPathLength - 1)/2]] /= 2;
        }
        
        int optimal = findOptimal(graph, 0, amount, -1);
        return optimal;
        // return 0;
        
    }
};