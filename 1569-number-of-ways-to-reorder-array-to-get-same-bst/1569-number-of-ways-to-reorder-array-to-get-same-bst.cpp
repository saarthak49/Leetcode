#define ll long long int
int mod = 1e9+7;
class Solution {
public:
    ll power(ll a, ll p)
    {
        if(a == 1 || a == 0 || p == 0)
            return 1;
        if(p == 1)
            return a%mod;
        ll answer = power(a, p/2);
        answer = (answer % mod * answer % mod ) % mod;
        if(p % 2 == 1)
            answer = (answer % mod * a % mod ) % mod;
        return answer;
    }
    ll moduloDiv(ll a, ll b)
    {
        ll binverse = power(b, mod - 2);
        return ( a %mod * binverse % mod ) % mod;
    }
    ll ncr(ll n, ll r)
    {
        ll product = 1;
        if(n == 0)
            return 0;
        for(ll i = 1; i<=r; i++)
        {
            product = (product%mod * (n - r + i)%mod ) % mod;
            product = moduloDiv(product, i);
        }
        return product;
    }
    ll countWays(vector<int> nums)
    {
        ll n = nums.size();
        if(n == 0 || n == 1)
            return 1;
        int root = nums[0];
        vector<int> left;
        vector<int> right;
        for(int i=1; i<=n-1; i++)
        {
            if(nums[i]<root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        int l = left.size();
        int r = right.size();
        int leftCount = countWays(left);
        int rightCount = countWays(right);
        return (ncr(l+r, r)% mod * leftCount % mod * rightCount % mod ) % mod;
        
        
    }
    int numOfWays(vector<int>& nums) {
        return countWays(nums) - 1;
    }
};