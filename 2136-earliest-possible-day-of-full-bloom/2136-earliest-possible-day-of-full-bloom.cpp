class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        multiset<pair<int, int> , decltype(&cmp)> s(&cmp);
        
        int i = 1000000000;
        cout<<i<<endl;
        
        
        
        
        int n = plantTime.size();
        for(int i = 0; i<=n-1; i++)
        {    
            s.insert({plantTime[i], growTime[i]});
        }
        
        auto it = s.begin();
        int lastPlantTime = it->first - 1;
        int lastBlossomTime = lastPlantTime + it->second + 1;
        it++;
        for(; it!=s.end(); it++)
        {
            lastPlantTime = lastPlantTime + it->first;
            lastBlossomTime = max(lastBlossomTime, lastPlantTime + it->second + 1);
        }
        
        return lastBlossomTime;
        
    }
};