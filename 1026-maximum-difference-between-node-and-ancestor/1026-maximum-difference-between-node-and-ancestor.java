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
    
    
    private static int answer;
    
    
    public void getAnswer(TreeNode root, int low, int high)
    {
        if(root == null)
            return;
        
        if(low != Integer.MAX_VALUE)
            answer = Math.max(answer, Math.abs(root.val - low));
        
        if(high != Integer.MIN_VALUE)
            answer = Math.max(answer, Math.abs(root.val - high));
        
        
        
        high = Math.max(root.val, high);
        low = Math.min(root.val, low);
        getAnswer(root.left, low, high);
        getAnswer(root.right, low, high);
    }
    
    
    public int maxAncestorDiff(TreeNode root) {
        
        answer = Integer.MIN_VALUE;
        
        int low = Integer.MAX_VALUE;
        int high = Integer.MIN_VALUE;
        
        getAnswer(root, low, high);
        
        return answer;
        
    }
}