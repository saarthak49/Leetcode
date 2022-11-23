class Solution {
    
    
    Map<Integer, Integer> findElementAtTail(int[] arr)
    {
        int count = 0;
        int n = arr.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i = 0; i<=n - 1; i++)
        {
            
            mp.put(i, i + count);
            if(arr[i] == 0)
                count++;
        }
        return mp;
    }
    
    
    
    public void duplicateZeros(int[] arr) {
        Map<Integer, Integer> mp = findElementAtTail(arr);
        int n = arr.length;
        int j = n-1;
        
        
        for(int i = n-1; i>=0; i--)
        {
            if(mp.get(i) <= n-1)
            {
                arr[mp.get(i)] = arr[i];
                if(arr[i] == 0 && mp.get(i) + 1 <= n-1)
                    arr[mp.get(i) + 1] = 0;
            }
        }
    }
}