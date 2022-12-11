class Allocator {
public:
    
    
    
    string str;
    unordered_map<int, vector<int> > mp;
    
    
    int patternMatch(string str, string pat)
    {
        
        int i = 0; 
        int j = 0;
        
        int n = str.size();
        int m = pat.size();
        
        if(m > n)
            return -1;
    
        
        while(i <= n-1 && j <= m-1)
        {
            
            if(str[i] == pat[j])
            {
                i++;
                j++;
            }
            else if(str[i]!=pat[j])
            {
                if(j == 0)
                    i++;
                else
                    j = j - 1;
            }
            
            if(j == m)
            {
                return i - j;
            }
            
            
        }
        
        return -1;
    }
    
    
    Allocator(int n) {
        str = "";
        for(int i = 0; i<=n-1; i++)
        {
            str = str + "_";
        }
        // cout<<str<<endl;
    }
    
    int allocate(int size, int mID) {
        cout<<"running allocation\n";
        string pat = "";
        // lps[j] = j;
        
        for(int i = 0; i<=size-1; i++)
            pat += "_";
        
        int index = patternMatch(str, pat);
        
        if(index == -1)
            return -1;
        
        
        for(int i = index; i<=index + size - 1; i++)
            str[i] = 'O';
        
        
        
        
        if(mp.find(mID) == mp.end())
        {
            vector<int> vec;
            vec.push_back(index);
            vec.push_back(size);
            mp[mID] = vec;
        }
        else
        {
            mp[mID].push_back(index);
            mp[mID].push_back(size);
        }
        
        // cout<<str<<endl;
        return index;
        
    }
    
    int free(int mID) {
        cout<<"running free\n";
        
        
        if(mp.find(mID) == mp.end())
            return 0;
        
        
        vector<int> vec = mp[mID];
        
        int n = vec.size();
        
        if(!n)
            return 0;
        
        
        
        int sum = 0;
        for(int i = 0; i<= n- 1; i+=2)
        {
            sum += vec[i + 1];
            
            
            int startIndex = vec[i];
            int size = vec[i + 1];
            for(int j = startIndex; j<=startIndex + size - 1; j++)
                str[j] = '_';
            
            mp[mID].clear();
            
        }
        // cout<<str<<endl;
        return sum;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */