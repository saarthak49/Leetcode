class KV implements Comparable<KV>
{
    int k;
    int v;
    public KV(int k, int v)
    {
        this.k = k;
        this.v = v;
    }
    
    @Override
    public int compareTo(KV kv)
    {
        if(this.v > kv.v)
            return 1;
        else if(this.v == kv.v)
            return 0;
        return -1;
    }
}



class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
    
    
        Map<Integer, Integer> mp = new HashMap<>();
        int n = arr.length;
        
        for(int num: arr)
        {
            if(mp.containsKey(num))
                mp.put(num, mp.get(num) + 1);
            else
                mp.put(num, 1);
        }
        
        List<KV> list = new ArrayList<>();
        
        for(Map.Entry<Integer, Integer> entry: mp.entrySet())
        {
            KV kv = new KV(entry.getKey(), entry.getValue());
            list.add(kv);
        }
        Collections.sort(list);
        n = list.size();
        
        
        int i = 0;
        for(i = 0; i<=n-1; i++)
        {
            k -= list.get(i).v;
            
            if(k < 0)
                break;
        }
        return n - i;
        
    }
}