class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> first = nums1.size()<nums2.size()?nums1:nums2;
        vector<int> second = nums2.size()>nums1.size()?nums2:nums1;
        
        
        int low = 0;
        int high = first.size();
        int m = first.size();
        int n = second.size();
        int n1 = 0;
        int n2 = 0;
        if(m==0 && n==0)
            return 0;
        
        if(m==0)
        {
            if(n%2 == 1)
                return second[(n-1)/2];
            return (second[n/2] + second[(n-1)/2])/2.0;
        }
        
        while(low <= high)
        {
            int i = low + (high - low)/2;
            int j = (m + n + 1)/2 - i;
            
            if(i<=m-1 && j-1>=0 && first[i] < second[j-1])
                low = i + 1;
            else if(i-1>=0 && j<=n-1 && first[i-1] > second[j])
                high = i - 1;
            else
            {
                if(i==0)
                    n1 = second[j-1];
                else if(j==0)
                    n1 = first[i-1];
                else
                    n1 = max(first[i-1] , second[j-1]);
                
                if(i==m)
                    n2 = second[j];
                else if(j==n)
                    n2 = first[i];
                else
                    n2 = min(first[i], second[j]);
                break;
            }
        }
        
        if( (m+n) %2 == 1 )
            return n1;
        return (n1 + n2)/2.0;
        
    }
};