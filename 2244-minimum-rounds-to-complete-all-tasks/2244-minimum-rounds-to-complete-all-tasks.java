class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int task : tasks)
            mp.put(task, mp.getOrDefault(task,0)+1);
        int count = 0;
        for(int value : mp.values())
        {
            if(value == 1)
                return -1;
            count += Math.ceil(value/3.0);
        }
        return count;
    }
}