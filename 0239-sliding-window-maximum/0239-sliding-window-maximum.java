class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {

        ArrayDeque<Integer> deque = new ArrayDeque<>();
        int n = nums.length;
        int arr[] = new int[n - k + 1];
        
        for(int i = 0; i<=k-1; i++)
        {
            if(deque.isEmpty() || nums[i] < nums[deque.peekLast()])
            {
                deque.offerLast(i);
            }
            else
            {
                while(!deque.isEmpty() && nums[deque.peekLast()] <= nums[i])
                {
                    deque.pollLast();
                }
                deque.offerLast(i);
            }
        }
        
        arr[0] = nums[deque.peekFirst()];
        int p = 1;
        
        for(int i = k; i<=n-1; i++)
        {
            if(deque.isEmpty() || nums[i] < nums[deque.peekLast()])
            {
                deque.offerLast(i);
            }
            else
            {
                while(!deque.isEmpty() && nums[deque.peekLast()] <= nums[i])
                {
                    deque.pollLast();
                }
                deque.offerLast(i);
            }
            
            while(!deque.isEmpty() && deque.peekFirst() < i - k + 1)
                deque.pollFirst();
            
            
            arr[p++] = nums[deque.peekFirst()];
            
        }
        
        
        return arr;
        
    }
}