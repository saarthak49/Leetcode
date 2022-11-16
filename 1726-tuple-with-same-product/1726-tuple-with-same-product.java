class Pair
{
    int a;
    int b;
    
    public Pair(int a, int b)
    {
        this.a = a;
        this.b = b;
    }
    
    @Override
    public boolean equals(Object pp)
    {
        Pair p = (Pair) pp; 
        return a == p.a || b == p.b;
            
    }
}

class Solution {
    
    public int tupleSameProduct(int[] nums) {
        int n = nums.length;
        
        Map<Integer, Integer> mp = new HashMap<>();
        
        for(int i = 0; i<=n-1; i++)
        {
            for(int j = i + 1; j<=n-1; j++)
            {
                int product = nums[i] * nums[j];
                if(mp.containsKey(product))
                {
                    int val = mp.get(product);
                    mp.put(product, val + 1);
                }
                else
                {
                    mp.put(product, 1);
                }
                
            }
        }
        
        int countAns = 0;
        for(Map.Entry<Integer, Integer> entry: mp.entrySet())
        {
            int val = entry.getValue()* (entry.getValue() - 1) / 2;
            countAns += val * 8;
        }
        return countAns;
    }
}