class Solution {
    public int minimumCardPickup(int[] cards) {
        int i = 0;
        int j = 0;
        int n = cards.length;
        
        Map<Integer, Integer> mp = new HashMap<>();
        
        int optimalLength = Integer.MAX_VALUE;
        
        while(i <= n - 1)
        {
            if(mp.containsKey(cards[i]))
            {
                int position = mp.get(cards[i]);
                //advance the pointer j by that much amount, making sure that you remove the keys in between
                optimalLength = Math.min( i - position + 1, optimalLength);
                
                
                while(j <= position)
                {
                    mp.remove(cards[j]);
                    j++;
                }
                
                
            }
            mp.put(cards[i], i);
            i++;
            
            
            
            
        }
        return optimalLength == Integer.MAX_VALUE ? -1 : optimalLength ;
    }
}