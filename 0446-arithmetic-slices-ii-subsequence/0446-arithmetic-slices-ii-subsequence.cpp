#define ll long long int
class Solution {
    
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        unordered_map<ll, ll> temp;
        
        int n = nums.size();
        vector<unordered_map<ll, ll> > vec(n, temp);
        vec[0][0] = 0;
        ll sum = 0;
        
        
        for(int i = 1; i<=n-1; i++)
        {
            for(int j = 0; j<=i-1; j++)
            {
                ll cd = (ll)nums[i] - nums[j];
                vec[i][cd] += vec[j][cd] + 1;
                // cout<<j<<" "<<i<<" "<<vec[i][cd]<<endl;
            }
        }
        
        for(int i = 1; i<=n-1; i++)
        {
            for(auto it: vec[i])
                sum += it.second;
        }
        return sum - n * (n-1)/2;
    }
};