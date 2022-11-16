//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int getBeauty(vector<int> vec)
    {
        int maxFreq = INT_MIN;
        int minFreq = INT_MAX;
        for(int i = 0; i<=25; i++)
        {
            if(vec[i] != 0)
                maxFreq = max(maxFreq, vec[i]);
            if(vec[i] != 0)
                minFreq = min(minFreq, vec[i]);
        }
        return maxFreq - minFreq;
    }
  
    int beautySum(string s) {
        
        int n = s.size();
        int sum = 0;
        
        for(int i = 0; i<=n-1; i++)
        {
            vector<int> vec(26, 0);
            for(int j = i; j<=n-1; j++)
            {
                vec[s[j] - 'a']++;
                sum += getBeauty(vec);
            }
        }
        
        
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends