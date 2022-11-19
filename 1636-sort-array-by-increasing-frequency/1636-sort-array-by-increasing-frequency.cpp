class Solution {
public:
    
    static bool cmpSet(pair<int,int> a, pair<int, int> b)
    {
        if(a.second == b.second)
            return a.first>b.first;
        return a.second<b.second;
    }
    
    static bool cmpVector(pair<int,int> a, pair<int, int> b)
    {
        if(a.second == b.second)
            return a.first>b.first;
        return a.second<b.second;
        
    }
    
    vector<int> freqSortVectorMethod(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for(auto num: nums)
        {
            mp[num]++;
        }
        vector<pair<int, int> > sortArray;
        for(auto it: mp)
        {
            sortArray.push_back({it.first, it.second});
        }
        vector<int> finalAnswer;
        sort(sortArray.begin(), sortArray.end(), cmpVector);
        for(auto elem: sortArray)
        {
            int count = elem.second;
            while(count--)
                finalAnswer.push_back(elem.first);
        }
        return finalAnswer;
    }
    vector<int> freqSortSetMethod(vector<int> &nums)
    {
        set<pair<int, int>,  decltype(&cmpSet) > s(&cmpSet);
        unordered_map<int, int> mp;
        for(auto num: nums)
        {
            if(mp.find(num) == mp.end())
            {
                s.insert({num, 1});
                mp[num]++;
            }
            else
            {
                int freq = mp[num];
                s.erase(s.find({num, freq}));
                s.insert({num, freq + 1});
                mp[num]++;
            }
        }
        vector<int> finalAnswer;
        for(auto it: s)
        {
            int count = it.second;
            while(count--)
                finalAnswer.push_back(it.first);
        }
        return finalAnswer;
    }
    
    
    vector<int> frequencySort(vector<int>& nums) {
        return freqSortVectorMethod(nums);
        
    }
};