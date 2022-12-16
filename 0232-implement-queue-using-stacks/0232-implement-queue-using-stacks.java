class MyQueue {
    
    private final Stack<Integer> stack1;
    private final Stack<Integer> stack2;
    
    public MyQueue() {
        this.stack1 = new Stack<>();
        this.stack2 = new Stack<>();
    }
    
    public void push(int x) {
        stack1.add(x);
    }
    
    public int pop() {
        while(!stack1.isEmpty())
        {
            stack2.add(stack1.peek());
            stack1.pop();
        }
        int answer = stack2.pop();
        
        while(!stack2.isEmpty())
        {
            stack1.add(stack2.peek());
            stack2.pop();
        }
        return answer;
    }
    
    public int peek() {
        while(!stack1.isEmpty())
        {
            stack2.add(stack1.peek());
            stack1.pop();
        }
        int answer = stack2.peek();
        
        while(!stack2.isEmpty())
        {
            stack1.add(stack2.peek());
            stack2.pop();
        }
        return answer;
    }
    
    public boolean empty() {
        return stack1.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */