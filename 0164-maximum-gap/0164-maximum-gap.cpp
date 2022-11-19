class Solution {
public:
    
    //practicing again, add the same function signature append the 
    //attempt number at the end of the function, temporarily add a number
    // at the end of original function and run new
    
    int maximumGap1(vector<int> &nums)
    {
        
        int n = nums.size();
        if( n == 1 || n == 0)
            return 0;
        if( n == 2)
            return abs(nums[0] - nums[1]);
        int avg = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
        if( avg == 0)
            return 0;
        
        int sm = *min_element(nums.begin(), nums.end());
        
        avg = avg / (n - 1) + 1;
        
        vector< pair<int, int> > bucket;
        for(int i = 0; i<=n-1; i++)
        {
            bucket.push_back({INT_MAX, INT_MIN});
        }
        
        // cout<<avg<<endl;
        
        
        for(int i = 0; i<=n-1; i++)
        {
            int buck = (nums[i] - sm)/avg;
            // cout<<buck<<endl;
            if(bucket[buck].first == INT_MAX)
            {
                bucket[buck].first = nums[i];
                bucket[buck].second = nums[i];
            }
            else
            {
                bucket[buck].first = min(bucket[buck].first, nums[i]);
                bucket[buck].second = max(bucket[buck].second, nums[i]);
            }
        }
        
        int answer = avg - 1;
        int compare = bucket[0].second;
        
        for(int i = 1; i<=n-1; i++)
        {
            if(bucket[i].first != INT_MAX)
            {
                answer = max(answer, bucket[i].first - compare);
                compare = bucket[i].second;
            }
        }
        return answer;
    }
    
    
    
    int maximumGap(vector<int>& nums) {
        int ninf = INT_MIN;
        int inf  = INT_MAX;
        int n = nums.size();
        if( n==1 )
            return 0;
        int maxElement = *max_element(nums.begin(), nums.end());
        int minElement = *min_element(nums.begin(), nums.end());
        int avgGap = (maxElement - minElement)/(n-1) + 1;
        vector<pair<int,int> > hash(n+1, {inf,ninf});
        
        for(int i = 0; i<=n-1; i++)
        {
            int bucket = (nums[i] - minElement)/avgGap;
            hash[bucket].first = min(hash[bucket].first, nums[i]);
            hash[bucket].second = max(hash[bucket].second, nums[i]);
        }
        int maxDiff = hash[0].second - hash[0].first;
        int lastAns = hash[0].second;
        for(int i = 1; i<=n; i++)
        {
            if(hash[i].first != inf)
            {
                maxDiff = max(maxDiff, hash[i].first - lastAns);     
                lastAns = hash[i].second;
            }
        }
        return maxDiff;
    }
};