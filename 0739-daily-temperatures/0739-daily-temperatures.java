class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        
        
        
        Stack<Integer> st = new Stack<>();
        int n = temperatures.length;
        int[] ans = new int[n];
        
        for(int i = 0; i<=n-1; i++)
        {
            
            while(!st.isEmpty() && temperatures[i] > temperatures[st.peek()])
            {
                int p = st.pop();
                ans[p] = i - p;
            }
            st.push(i);
        }
        
        while(!st.isEmpty())
        {
            int p = st.pop();
            ans[p] = 0;
        }
        
        return ans;
        
    }
}