class Solution {
public:
    
    int getSum(int num)
    {
        int sum = 0;
        while(num != 0)
        {
            sum += num%10;
            num/=10;
        }
        return sum;
    }
    
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> mp;
        int maxNumber = 0;
        
        
        for(int i = lowLimit; i<=highLimit; i++)
        {
            int getAnswer = getSum(i);
            
            mp[getAnswer]++;
            if(mp[getAnswer] > maxNumber)
            {
                maxNumber = mp[getAnswer];
            }
        }
        
        return maxNumber;
        
    }
};