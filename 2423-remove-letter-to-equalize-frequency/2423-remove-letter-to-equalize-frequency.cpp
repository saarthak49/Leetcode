class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> mp;
        
        for(int i = 0; i<=word.size()-1; i++)
            mp[word[i]]++;
        
        if(mp.size() == 1)
            return true;
        
        if(mp.size() == 2)
        {
            int a = 0;
            int b = 0;
            for(auto it: mp)
            {
                if(it.second == 1)
                    return true;
                if(!a)
                    a = it.second;
                
                else if(!b)
                    b = it.second;
            }
            return abs(a-b) == 1;
        }
        unordered_map<int, int> a;
        for(auto it: mp)
        {
            a[it.second]++;
            if(a.size() == 3)
                return false;
        }
        
        int elem1 = 0;
        int elem2 = 0;
        int freq1 = 0;
        int freq2 = 0;
        
        for(auto it: a)
        {
            if(!elem1)
            {
                elem1 = it.first;
                freq1 = it.second;
            }
            else if(!elem2)
            {
                elem2 = it.first;
                freq2 = it.second;
            }
        }
        // cout<<elem1<<" "<<freq1<<endl;
        // cout<<elem2<<" "<<freq2<<endl;
        if(elem2 == 0 && elem1 == 1)
            return true;
        if(freq1 == 1 && (elem1 == 1 || elem1-1 == elem2) || freq2 == 1 && (elem2 == 1 || elem2-1 == elem1) )
            return true;
        return false;
    }
};