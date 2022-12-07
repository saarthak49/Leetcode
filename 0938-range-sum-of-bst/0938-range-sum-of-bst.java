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

class Solution {
    
    private static int sum = 0;
    
    
    public void findSum(TreeNode root, int low, int high)
    {
        if(root == null)
            return;
        
        
        
        if(root.val >= low && root.val <= high)
            sum += root.val;
        
        
        if(root.val < low)
            findSum(root.right, low, high);
        else if( root.val > high)
            findSum(root.left, low, high);
        
        else
        {
            findSum(root.left, low, high);
            findSum(root.right, low ,high);
        }
    }
    
    
    
    
    public int rangeSumBST(TreeNode root, int low, int high) {
        sum = 0;
        findSum(root, low, high);
        return sum;
    }
}