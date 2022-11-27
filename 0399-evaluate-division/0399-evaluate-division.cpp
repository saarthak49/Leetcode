class Solution {
public:
    
    
    void runDfs(int start, int end, vector<vector<bool> > graph, vector<vector<double> > weights, vector<bool> vis, bool &flag, double &ans, double value)
    {
        // cout<<"called on id = "<<start<<endl;
        
        if(flag)
            return;
        
        if(start == end)
        {
            ans = value;
            flag = true;
            return;
        }
        
        vis[start] = true;
        
        for(int i = 0; i<=graph[start].size() - 1; i++)
        {
            if(graph[start][i] && !vis[i])
            {
                runDfs(i, end, graph, weights, vis, flag, ans, value * weights[start][i]);
            }
        }
        
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        
        int n = equations.size();
        int id = 0;
        
        unordered_map<string, int> idMap;
        
        vector<bool> temp(2 * n, false);
        vector<double> temp1(2 * n, 0.0);
        
        vector<vector<bool> > graph(2 * n, temp);
        vector<vector<double> > weights(2 * n, temp1);
        
        for(int i = 0; i<=n-1; i++)
        {
            if(idMap.find(equations[i][0]) == idMap.end())
                idMap[equations[i][0]] = id++;
            
            int id1 = idMap[equations[i][0]];
                
            if(idMap.find(equations[i][1]) == idMap.end())
                idMap[equations[i][1]] = id++;
            
            int id2 = idMap[equations[i][1]];
            
            // cout<<id1<<" "<<id2<<endl;
            
            graph[id1][id2] = true;
            weights[id1][id2] = values[i];
            
            graph[id2][id1] = true;
            weights[id2][id1] = 1.0 / values[i];
        }
        
        // after this we are ready to answer queries
        
        int q = queries.size();
        vector<double> ans(q, 0.0);
        
        vector<bool> vis(2 * n, false);
        
        for(int i = 0; i<=q-1; i++)
        {
            string str1 = queries[i][0];
            string str2 = queries[i][1];
            
            if(idMap.find(str1) == idMap.end() || idMap.find(str2) == idMap.end())
            {
                ans[i] = -1;
                continue;
            }
            
            int id1 = idMap[str1];
            int id2 = idMap[str2];
            
            // cout<<id1<<" "<<id2<<endl;
            
            double an = 0.0;
            double value = 1.0;
            bool flag = false;
            
            runDfs(id1, id2, graph, weights, vis, flag, an, value);
            if(!flag)
                an = -1;
            ans[i] = an;
        }
        
        return ans;
        
        
    }
};