
// trying to make own stack to see if submission is faster


class Solution {
    
    
    private int[] stack = new int[10001];
    private int top;
    
    
    private void push(int x)
    {
        stack[++top] = x;
    }
    
    
    
    private int pop()
    {
        return stack[top--];
    }
    
    
    
    public int evalRPN(String[] tokens) {
        
        
        
        int n = tokens.length;
        // this.stack = new int[n];
        this.top = -1;
        
        
        for(int i = 0; i<=n-1; i++)
        {
            
            
            String token = tokens[i];
            
            if(token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/"))
            {
                int b = pop();
                int a = pop();
                
                int result = 0;
                switch(token)
                {
                    case "+":
                        result = a + b;
                        break;
                    case "-":
                        result = a - b;
                        break;
                    case "*":
                        result = a * b;
                        break;
                    case "/":
                        result = a / b;
                        break;
                }
                push(result);
            }
            else
                push(Integer.parseInt(token));
            
        }
        
        return pop();
    }
}