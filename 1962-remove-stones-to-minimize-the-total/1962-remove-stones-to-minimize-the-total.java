class Solution {
    public int minStoneSum(int[] piles, int k) {
        Queue<Integer> priorityQueue = new PriorityQueue<>(Comparator.reverseOrder());
        int sum = 0;
        for(int i : piles)
        {
            priorityQueue.offer(i);
            sum += i;
        }
        
        
        while(k --> 0 && !priorityQueue.isEmpty())
        {
            int i = priorityQueue.poll();
            if(i == 1)
                break;
            sum -= i/2;
            i -= i/2;
            priorityQueue.offer(i);
        }
        return sum;
    }
}