class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int, bool> played;
        
        unordered_map<int, int> losses;
        
        int n = matches.size();
        
        for(int i = 0; i<=n-1; i++)
        {
            int w = matches[i][0];
            int l = matches[i][1];
            
            played[w] = true;
            played[l] = true;
            
            losses[l]++;
        }
        
        vector<int> noLoss;
        
        vector<int> oneLoss;
        
        for(auto it: played)
        {
            if(losses[it.first] == 0)
                noLoss.push_back(it.first);
            else if(losses[it.first] == 1)
                oneLoss.push_back(it.first);
        }
        sort(noLoss.begin(), noLoss.end()); 
        sort(oneLoss.begin(), oneLoss.end());
        vector<vector<int> > ans;
        ans.push_back(noLoss);
        ans.push_back(oneLoss);
        return ans;
    }
};