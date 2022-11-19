class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> hash(n+1, 0);
        for(int i = 0; i<=n-1; i++)
        {
            if(citations[i]>=n)
                hash[n]++;
            else
                hash[citations[i]]++;
        }
        int cumulativeTotal = 0;
        // running i from n to 0 because h-index can lie in that range
        for(int i = n; i>=0; i--)
        {
            cumulativeTotal += hash[i];
            if(cumulativeTotal >= i) // condition for i to be my h-index
                return i;
        }
        return 0;  // 0 is always a valid h-index
    }
};