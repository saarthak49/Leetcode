class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        
        
        int n = matches.length;
        
        Map<Integer, Boolean> played = new HashMap<>();
        
        Map<Integer, Integer> losses = new HashMap<>();
        
        
        for(int i = 0; i<=n-1; i++)
        {
            int w = matches[i][0];
            int l = matches[i][1];
            
            played.put(w, true);
            played.put(l, true);
            
            if(losses.containsKey(l))
            {
                int numberLoss = losses.get(l);
                losses.put(l, numberLoss + 1);
            }
            else
                losses.put(l, 1);
        }
        
        List<Integer> noLosses = new ArrayList<>();
        List<Integer> oneLoss = new ArrayList<>();
        
        for(Map.Entry<Integer, Boolean> entry : played.entrySet())
        {
            int id = entry.getKey();
            
            if(!losses.containsKey(id))
                noLosses.add(id);
            else if(losses.get(id) == 1)
                oneLoss.add(id);
        }
        
        Collections.sort(noLosses);
        Collections.sort(oneLoss);
        List<List<Integer> > ans = new ArrayList<>();
        ans.add(noLosses);
        ans.add(oneLoss);
        return ans;
        
    }
}