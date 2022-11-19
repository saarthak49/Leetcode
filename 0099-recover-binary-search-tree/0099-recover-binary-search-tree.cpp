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
#define node TreeNode
class Solution {
public:
    void inorder(node* root, node* &marker1, node* &marker2, bool &found1, bool &found2, node* &prev)
    {
        if(!root)
            return;
        
        inorder(root->left, marker1, marker2, found1, found2, prev);
        if(prev && prev->val > root->val)
        {
            if(!found1)
            {
                found1 = true;
                marker1 = prev;
                marker2 = root;
            }
            else 
            {
                found2 = true;
                marker2 = root;
            }
        }
        prev = root;
        inorder(root->right, marker1, marker2, found1, found2, prev);
    }
    void recoverTree(TreeNode* root) {
        node* marker1 = NULL;
        node* marker2 = NULL;
        bool found1 = false;
        bool found2 = false;
        node* prev = NULL;
        
        inorder(root, marker1, marker2, found1, found2, prev);
        swap(marker1->val, marker2->val);
        
    }
};