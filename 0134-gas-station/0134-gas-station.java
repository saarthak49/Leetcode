class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int total = 0;
        int index = 0;
        for(int i = 0; i<=n-1; i++)
        {
            total += gas[i] - cost[i];
            if(total < 0)
            {
                index = i + 1;
                total = 0;
            }
            if(i >= 1)
            {
                gas[i] += gas[i-1];
                cost[i] += cost[i-1];
            }
        }
        return index == n ? -1 : (gas[n-1] < cost[n-1]) ? -1 : index;
    }
}