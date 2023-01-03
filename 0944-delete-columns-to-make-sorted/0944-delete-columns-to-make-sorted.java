class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs.length;
        int strSize = strs[0].length();
        
        int count = 0;
        for(int i = 0; i<=strSize - 1; i++)
        {
            for(int j = 1; j<=n-1; j++)
            {
                if(strs[j].charAt(i) < strs[j-1].charAt(i))
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}