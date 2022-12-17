class Solution {
    public int evalRPN(String[] tokens) {
        
        
        int n = tokens.length;
        
        Stack<Integer> s = new Stack<>();
        
        for(int i = 0; i<=n-1; i++)
        {
            
            
            String token = tokens[i];
            
            if(token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/"))
            {
                int b = s.pop();
                int a = s.pop();
                
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
                s.add(result);
            }
            else
                s.add(Integer.parseInt(token));
            
        }
        
        return s.pop();
    }
}