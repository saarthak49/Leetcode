class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> s = new Stack<>();
        
        int n = heights.length;
        int max_area = Integer.MIN_VALUE;
        for(int i = 0; i <= n - 1; i++)
        {
            if(s.isEmpty() || heights[i] >= heights[s.peek()])
            {
                s.push(i);
            }
            else
            {
                while(!s.isEmpty() && heights[s.peek()] > heights[i])
                {
                    int processedIndex = s.peek();
                    s.pop();
                    if(s.isEmpty())
                        max_area = Math.max(max_area, i * heights[processedIndex]);
                    else
                        max_area = Math.max(max_area, (i - s.peek() - 1) * heights[processedIndex]);
                }
                s.push(i);
            }
        }
        
        while(!s.isEmpty())
        {
            int processedIndex = s.peek();
            s.pop();
            if(s.isEmpty())
                max_area = Math.max(max_area, n * heights[processedIndex]);
            else
                max_area = Math.max(max_area, (n - s.peek() - 1) * heights[processedIndex]);
        }
        
        
        return max_area;
    }
}