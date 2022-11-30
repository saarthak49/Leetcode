class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> mp = new HashMap<>();
        
        int n = arr.length;
        
        
        for(int i = 0; i<=n-1; i++)
        {
            if(mp.containsKey(arr[i]))
            {
                int occurences = mp.get(arr[i]);
                mp.put(arr[i], occurences + 1);
                continue;
            }
            mp.put(arr[i], 1);
        }
        
        Map<Integer, Integer> oc = new HashMap<>();
        
        for(int val : mp.values())
        {
            if(oc.containsKey(val))
                return false;
            oc.put(val, 1);
        }
        return true;
    }
}