class Solution {
    
        class Pair implements Comparable<Pair>
        {
            int plantTime;
            int growTime;
            
            public Pair(int a, int b)
            {
                plantTime = a;
                growTime = b;
            }
            
            
            @Override
            public String toString()
            {
                return "[" + plantTime + " " + growTime + "]";
            }
            
            @Override
            public int compareTo(final Pair pair)
            {
                return pair.growTime - this.growTime;
            }
                
        }
    
    
    public int earliestFullBloom(int[] plantTime, int[] growTime) {
        

        PriorityQueue<Pair> priorityQueue = new PriorityQueue<Pair>();
        
        
        int n = plantTime.length;
        
        for(int i = 0; i<=n-1; i++)
        {
            priorityQueue.offer(new Pair(plantTime[i], growTime[i]));
        }
        
        
        Pair pair = priorityQueue.poll();
        
        int lastPlant = pair.plantTime - 1;
        int lastBloom = lastPlant + pair.growTime + 1;
        
        
        
        while(!priorityQueue.isEmpty())
        {
            Pair p = priorityQueue.poll();
            lastPlant = lastPlant + p.plantTime;
            lastBloom = Math.max(lastBloom, lastPlant + p.growTime + 1);
        }
        
        
        return lastBloom;
        
        
    }
}