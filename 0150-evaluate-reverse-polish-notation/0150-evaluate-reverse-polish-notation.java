
// trying to make own stack to see if submission is faster


class Solution {
    
    
    private int[] stack;
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
        this.stack = new int[n];
        this.top = -1;
        
        
        for(int i = 0; i<=n-1; i++)
        {
            
            
            String token = tokens[i];
            
            if(tokens[i].equals("+") || tokens[i].equals("-") || tokens[i].equals("*") || tokens[i].equals("/"))
            {
                int b = pop();
                int a = pop();
                
                int result = 0;
                switch(tokens[i])
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
                push(Integer.parseInt(tokens[i]));
            
        }
        
        return pop();
    }
}