class Solution {
public:
    
    
    vector<int> findList(int n)
    {
        vector<int> vec;
        while(n > 0)
        {
            vec.push_back(n);
            n/=2;
        }
        return vec;
    }
    
    
    
    int findIntersection(vector<int> a, vector<int> b)
    {
        
        int n1 = a.size();
        int n2 = b.size();
        if(n2 < n1)
            return findIntersection(b, a);
        
        
        
        // find difference in lengths;
        
        int diff = n2 - n1;
        int i = 0;
        int j = diff;
        
        while(a[i] != b[j])
        {
            i++;
            j++;
        }
        
        
        return a[i];
        
    }
    
    
    
    
    
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        
        int s = queries.size();
        for(int i = 0; i<=s-1; i++)
        {
            int a = queries[i][0];
            int b = queries[i][1];
            vector<int> vec1 = findList(a);
            vector<int> vec2 = findList(b);
            
            
            int c = findIntersection(vec1, vec2);
            a = (int)log2(a) + 1;
            b = (int)log2(b) + 1;
            c = (int)log2(c) + 1;
            ans.push_back(a + b - 2 * c + 1);
        }
        return ans;
    }
};