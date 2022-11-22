//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long int maxSumLCM(int n) 
    {
        
        long long int sum = 0;
        // cout<<sqrt(n)<<endl;
        for(int i = 1; i<=sqrt(n); i++)
        {
            if(n % i == 0)
            {
                long long int a = n/i;
                long long int b = i;
                if(a != b)
                    sum += a, sum += b;
                else
                    sum += a;
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
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.maxSumLCM(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends