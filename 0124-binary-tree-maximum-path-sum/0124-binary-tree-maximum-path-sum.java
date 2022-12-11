/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */


class integer
{
    int i;
    public integer(int i)
    {
        this.i = i;
    }
}

class Solution {
    
    private static int maxSum;
    
    
    public int getMax(TreeNode root, int sum)
    {
        
        if(root == null)
            return Integer.MIN_VALUE;
        
        int valueForThisNode = sum + root.val;
        
        int left = getMax(root.left, valueForThisNode);
        int right = getMax(root.right, valueForThisNode);
        
        int leftAns = 0;
        int rightAns = 0;
        
        if(left != Integer.MIN_VALUE)
            leftAns = left - valueForThisNode;
        
        if(right != Integer.MIN_VALUE)
            rightAns = right - valueForThisNode;
        
        leftAns = leftAns > 0 ? leftAns : 0;
        rightAns = rightAns > 0 ? rightAns : 0;
        
        maxSum = Math.max(maxSum, leftAns + rightAns + root.val);
        
        
        return Math.max(valueForThisNode, Math.max(left, right));
    }
    
    public int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        int sum = 0;
        getMax(root, sum);
        return maxSum;
    }
}