/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findMinCover(TreeNode* root, int &count)
    {
        if(!root)
            return 2;
        
        int l = findMinCover(root->left, count);
        int r = findMinCover(root->right, count);
        // if any of the left or right node is not monitored
        if(l==1 || r==1 )
        {
            count++;
            return 3;
            // place the camera here
        }
        // if both my left and right nodes are monitored then its not mandatory to place 
        // camera here.
        if(l==2 && r==2)
            return 1;
        return 2;
    }
    int minCameraCover(TreeNode* root) {
        int count = 0;
        TreeNode* temp = root;
        int find = findMinCover(temp, count);
        if(find == 1)
            return count+1;
        return count;
            
        
    }
};