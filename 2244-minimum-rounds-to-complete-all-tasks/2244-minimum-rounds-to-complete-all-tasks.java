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
            count += (value + 2)/3;
        }
        return count;
    }
}