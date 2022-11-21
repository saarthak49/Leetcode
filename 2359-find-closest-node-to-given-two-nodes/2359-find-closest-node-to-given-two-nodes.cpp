class Solution {
public:
    
    void getDfsWithMap(int source, vector<int> &edges, bool vis[], int mp2[], int i, int &minDist, int &returnPoint)
    {
        vis[source] = true;
        if(mp2[source] != -1 )
        {
            int dist = max(i, mp2[source]);
            if(dist < minDist)
            {
                minDist = dist;
                returnPoint = source;
            }
            else if(dist == minDist && source < returnPoint)
                returnPoint = source;
        }
        if(edges[source] != -1 && !vis[edges[source]])
        {
            getDfsWithMap(edges[source], edges, vis, mp2, i+1, minDist, returnPoint);
        }
    }
    
    void justDfs(int source, vector<int> &edges, int mp1[], int i)
    {
        mp1[source] = i;
        if(edges[source] != -1 && mp1[edges[source]] == -1)
        {
            justDfs(edges[source], edges, mp1, i+1);
        }
    }
    
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        int mp1[n];
        bool vis[n];
        memset(mp1, -1, sizeof(mp1));
        memset(vis, false, sizeof(vis));
        
        
        int i = 0;
        int returnPoint = -1;
        
        
        int minDist = INT_MAX;
        justDfs(node1, edges, mp1, i);
        
        getDfsWithMap(node2, edges, vis, mp1, i, minDist, returnPoint);
        
        return returnPoint;
        
    }
};