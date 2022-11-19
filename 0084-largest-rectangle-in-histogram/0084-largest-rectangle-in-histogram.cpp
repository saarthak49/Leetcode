class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        int maxArea = 0;
        for(int i = 0; i<=n-1; i++)
        {
            if(s.empty() || heights[i]>= heights[s.top()])
                s.push(i);
            else
            {
                while(!s.empty() && heights[i] < heights[s.top()])
                {
                    int height = heights[s.top()];
                    int area = 0;
                    s.pop();
                    if(!s.empty())
                    {
                        area = height * (i - s.top() - 1);
                    }
                    else
                        area = height * i;
                    maxArea = max( maxArea, area);
                }
                s.push(i);
            }
        }
        
        while(!s.empty())
        {
            int height = heights[s.top()];
            int area = 0;
            s.pop();
            if(!s.empty())
            {
                area = height * (n - s.top() - 1);
            }
            else
                area = height * n;
            maxArea = max( maxArea, area);
        }
        
        return maxArea;
        
    }
};