class Solution {
    public int minStoneSum(int[] piles, int k) {
        Queue<Integer> priorityQueue = new PriorityQueue<>(Comparator.reverseOrder());
        
        
        int sum = 0;
        for(int i : piles)
        {
            priorityQueue.offer(i);
            sum += i;
        }
        
        
        while(k --> 0)
        {
            int i = priorityQueue.peek();
            sum -= i/2;
            
            i -= i/2;
            priorityQueue.poll();
            priorityQueue.offer(i);
        }
        return sum;
        
    }
}