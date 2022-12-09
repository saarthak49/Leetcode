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
    
    
    public void getLeaves(TreeNode root1, List<Integer> leaves)
    {
        if(root1 == null)
            return;
        
        if(root1.left == null && root1.right == null)
            leaves.add(root1.val);
        
        getLeaves(root1.left, leaves);
        getLeaves(root1.right, leaves);
            
    }
    
    
    public boolean same(List<Integer> l1, List<Integer> l2)
    {
        int n1 = l1.size();
        int n2 = l2.size();
        if(n1 != n2)
            return false;
        
        for(int i = 0; i<=n1-1; i++)
        {
            if(l1.get(i) != l2.get(i))
                return false;
        }
        return true;
    }
    
    
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> l1 = new ArrayList<>();
        List<Integer> l2 = new ArrayList<>();
        
        getLeaves(root1, l1);
        getLeaves(root2, l2);
        
        
        return same(l1, l2);
    }
}