class Solution {
public:
    
    
    int findIntersection(int mp1[], int mp2[], int n)    
    {
        int minDist = INT_MAX;
        int returnPoint = -1;
        
        for(int i = 0; i<=n - 1; i++)
        {
            if(mp1[i] != -1 && mp2[i] != -1)
            {
                int dist = max(mp1[i], mp2[i]);
                if(dist < minDist)
                {
                    minDist = dist;
                    returnPoint = i;
                }
                else if(dist == minDist && i < returnPoint)
                    returnPoint = i;
            }
        }
        
        return returnPoint;
        
    }
    void getDfsPath(int source, vector<int> &edges, int mp1[], int i)
    {
        mp1[source] = i;
        if(edges[source] != -1 && mp1[edges[source]] == -1)
        {
            getDfsPath(edges[source], edges, mp1, i+1);
        }
    }
    
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        int mp1[n];
        memset(mp1, -1, sizeof(mp1));
        
        vector<int> firstNodeDfs;
        getDfsPath(node1, edges, mp1, 0);
        
        int mp2[n];
        memset(mp2, -1, sizeof(mp2));
        
        vector<int> secondNodeDfs;
        int i = 0;
        getDfsPath(node2, edges, mp2, i);
        
        
        
        
        int point = findIntersection(mp1, mp2, n);
        
        return point;
        
    }
};