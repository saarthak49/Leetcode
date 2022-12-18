class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        
        
        vector<int> vec[n + 1];
        
        vector<int> freq(n + 1, 0);
        
        for(int i = 0; i<=edges.size()-1; i++)
        {
            int src = edges[i][0];
            int dest = edges[i][1];
            
            
            vec[src].push_back(dest);
            vec[dest].push_back(src);
            
            freq[src]++;
            freq[dest]++;
        }
        
        int allowed = 2;
        
        for(int i = 1; i<=n; i++)
        {
            
            
            if(freq[i] % 2 == 1)
            {
                // cout<<i<<" has odd frequency equal to "<<freq[i]<<endl;
                if(allowed <= 0)
                    break;
                allowed--;
                int arr[n + 1];
                memset(arr, 0, sizeof(arr));
                for(auto it : vec[i])
                    arr[it] = 1;
                bool flag = false;
                for(int j = 1; j<=n; j++)
                {
                    if(j != i && arr[j] == 0 && freq[j] % 2 == 1)
                    {
                        flag = true;
                        
                        vec[i].push_back(j);
                        vec[j].push_back(i);
                        
                        
                        // cout<<i<<" was ausing problem mad edge with "<<j<<endl;
                        
                        
                        freq[i]++;
                        freq[j]++;
                        break;
                    }
                        
                }
                if(flag)
                    continue;
                
                for(int j = 1; j<=n; j++)
                {
                    if(j != i && arr[j] == 0)
                    {
                        flag = true;
                        
                        vec[i].push_back(j);
                        vec[j].push_back(i);
                        // cout<<i<<" was ausing problem mad edge with "<<j<<endl;
                        freq[i]++;
                        freq[j]++;
                        break;
                    }
                        
                }
                if(!flag)
                    return false;
            }
        }
        
        
        for(int i = 1; i<=n; i++)
        {
            if(freq[i] %2 == 1)
                return false;
        }
        
        return true;
        
        
    }
};