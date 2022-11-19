class Solution {
public:
    
    
    // sliding window maxima can be used to complete it in O(1) time
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {

        int i = 0;
        int j = 0;

        int n = chargeTimes.size();
        
        cout<<n<<endl<<endl<<endl;

        int maxima = 0;

        multiset<long long int> s;
        int maxLen = 0;
        long long int cumulativeSum = 0L;
        // s.insert(chargeTimes[0]);

        while(j <= n - 1)
        {
            cumulativeSum += runningCosts[j];
            s.insert((long long int)chargeTimes[j]);
            while(*(s.rbegin()) + cumulativeSum * (long long int)(j - i + 1) > budget && i < j)
            {
                s.erase(s.find(chargeTimes[i]));
                cumulativeSum -= runningCosts[i];
                i++;
            }

            if(*(s.rbegin()) + cumulativeSum * (long long int)(j - i + 1) <= budget)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
        return maxLen;
    
    
    }
};