class Solution {
    
    
    private int getSum(int num)
    {
        int sum = 0;
        while(num != 0)
        {
            sum += num%10;
            num/=10;
        }
        return sum;
    }
    
    
    public int countBalls(int lowLimit, int highLimit) {
        Map<Integer, Integer> mp = new HashMap<>();
        
        int maxAnswer = 1;
        
        for(int i = lowLimit; i<=highLimit; i++)
        {
            int ans = getSum(i);
            if(mp.containsKey(ans))
            {
                int balls = mp.get(ans);
                mp.put(ans, balls + 1);
                if(balls + 1 > maxAnswer)
                    maxAnswer = balls + 1;
                
            }
            else
                mp.put(ans, 1);
        }
        return maxAnswer;
    }
}