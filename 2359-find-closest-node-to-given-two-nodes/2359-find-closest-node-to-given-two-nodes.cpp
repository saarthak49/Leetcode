class Solution {
public:
    
    
    int findIntersection(vector<int> vec1, vector<int> vec2)    
    {
        unordered_map<int, int> mp1;
        int minDist = INT_MAX;
        int returnPoint = -1;
        
        for(int i = 0; i<=vec1.size() - 1; i++)
        {
            mp1[vec1[i]] = i;
        }
        
        for(int i = 0; i<=vec2.size() - 1; i++)
        {
            if(mp1.find(vec2[i]) != mp1.end())
            {
                int dist = max(i, mp1[vec2[i]]);
                if(dist < minDist)
                {
                    minDist = dist;
                    returnPoint = vec2[i];
                }
                else if(dist == minDist && vec2[i] < returnPoint)
                    returnPoint = vec2[i];
            }
        }
        
        return returnPoint;
        
    }
    void getDfsPath(int source, vector<int> &edges, bool vis[], vector<int> &vec)
    {
        vis[source] = true;
        vec.push_back(source);
        if(edges[source] != -1 && !vis[edges[source]])
            getDfsPath(edges[source], edges, vis, vec);
    }
    
    void printVector(vector<int> vec)
    {
        for(auto it: vec)
            cout<<it<<" ";
        cout<<endl;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        bool vis[n];
        memset(vis, false, sizeof(vis));
        
        vector<int> firstNodeDfs;
        getDfsPath(node1, edges, vis, firstNodeDfs);
        
        memset(vis, false, sizeof(vis));
        
        vector<int> secondNodeDfs;
        getDfsPath(node2, edges, vis, secondNodeDfs);
        
        
        
        
        int point = findIntersection(firstNodeDfs, secondNodeDfs);
        
        return point;
        
    }
};