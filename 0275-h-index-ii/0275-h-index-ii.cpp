class Solution {
public:
    int hIndex(vector<int>& citations) {
        //already sorted in nature
        int n = citations.size();
        int low = 0;
        int high = n;
        int lastAns = 0;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if( mid == 0)
            {
                lastAns = 0;
                low = mid + 1;
            }
            else if( citations[n-mid] >= mid)
            {
                lastAns = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return lastAns;
    }
};