class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int total = 0;
        int index = 0;
        int totalg = 0;
        int totalc = 0;
        for(int i = 0; i<=n-1; i++)
        {
            total += gas[i] - cost[i];
            if(total < 0)
            {
                index = i + 1;
                total = 0;
            }
            totalg += gas[i];
            totalc += cost[i];
        }
        return index == n ? -1 : (totalg < totalc) ? -1 : index;
    }
}