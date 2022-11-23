class Solution {
public:
    
    unordered_map<int, int> findElementAtTail(vector<int> &arr)
    {
        int count = 0;
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i<=n - 1; i++)
        {
            
            mp[i] = i + count;
            if(arr[i] == 0)
                count++;
        }
        return mp;
    }
    
    void duplicateZeros(vector<int>& arr) {
        unordered_map<int, int> mp = findElementAtTail(arr);
        int n = arr.size();
        int j = n-1;
        for(int i = n-1; i>=0; i--)
        {
            if(mp[i] <= n-1)
            {
                arr[mp[i]] = arr[i];
                if(arr[i] == 0 && mp[i] + 1 <= n-1)
                    arr[mp[i] + 1] = 0;
            }
        }
    }
};