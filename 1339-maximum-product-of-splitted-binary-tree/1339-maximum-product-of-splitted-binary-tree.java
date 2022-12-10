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
    
    private static long mod = (long) 1e9 + 7;
    
    
    private static long maxProduct = Long.MIN_VALUE;
    
    
    public long getMeSum(TreeNode root)
    {
        if(root == null)
            return 0;
        
        long sumL = getMeSum(root.left);
        long sumR = getMeSum(root.right);
        
        
        
        return sumL + sumR + root.val;
            
    }
    
    public long traverse(TreeNode root, long sum)
    {
        if(root == null)
            return 0;
        long suml = traverse(root.left, sum);
        long sumr = traverse(root.right, sum);
        
        long sumAtRoot = suml + sumr + root.val;
        
        long proHere = (sum - sumAtRoot) * (sumAtRoot);
        maxProduct = Math.max(maxProduct, proHere);
        // System.out.println(maxProduct + " was formed by " + (sum - sumAtRoot) + " and " + sumAtRoot);
        return sumAtRoot;
    }
    
    
    
    
    
    
    
    public int maxProduct(TreeNode root) {
        maxProduct = Long.MIN_VALUE;
        long sum = getMeSum(root);
        traverse(root, sum);
        int ans =(int) (maxProduct % mod);
        return ans;
    }
}