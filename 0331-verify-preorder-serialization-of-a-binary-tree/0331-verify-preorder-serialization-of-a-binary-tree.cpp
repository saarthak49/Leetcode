class Solution {
public:
    bool isValid(string preorder, int &i, int n)
    {
        if(preorder[i]=='#')
            return true;
        
        while(i<=n-1 && preorder[i]!=',')
            i++;
        
        if(i>n-1)
            return false;
        i++;
        
        if(i>n-1)
            return false;
        bool left = isValid(preorder, i, n);
        i += 2;
        if(i>n-1)
            return false;
        bool right = isValid(preorder, i, n);
        return left && right;
    }
    
    bool isValidSerialization(string preorder) {
        int i = 0;
        int n = preorder.size();
        bool ans = isValid(preorder, i, preorder.size());
        if(i<n-1)
            return false;
        return ans;
        
    }
};