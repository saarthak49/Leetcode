/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define node TreeNode
class Solution {
public:
    
    void printKDown1(node* root, int k, vector<int> &ans)
    {
        if(k<0 || !root)
            return;
        if(k == 0)
        {
            ans.push_back(root->val);
            return;
        }
        
        printKDown1(root->left, k-1, ans);
        printKDown1(root->right, k-1, ans);
    }
    
    
    int printDistanceK1(node* root, node* target, int &k, vector<int> &ans)
    {
        if(!root)
            return -1;
        if(root == target)
        {
            printKDown1(root, k, ans);
            return 1;
            
        }
        
        
        int left = printDistanceK1(root->left, target, k, ans);
        int right = printDistanceK1(root->right, target, k, ans);
        if(left == -1 && right == -1)
            return -1;
        
        
        if(left != -1)
        {
            
            if(k - left == 0)
                ans.push_back(root->val);
            printKDown1(root->right, k - left - 1, ans);
            return 1 + left;
        }
        
        
        if(k - right == 0)
            ans.push_back(root->val);
        printKDown1(root->left, k - right - 1, ans);
        return 1 + right;
    }
    
    void printKDown0(node* root, int k, vector<int> &ans)
    {
        if(k<0)
            return;
        if(!root)
            return;
        if(k == 0)
            ans.push_back(root->val);
        printKDown0(root->left, k-1, ans);
        printKDown0(root->right, k-1, ans);
    }
    
    
    int printDistanceK0(node *root, node *target, int k, vector<int> &ans)
    {
        if(!root)
            return -1;
        
        if(root == target)
        {
            printKDown0(root, k, ans);
            return 1;
        }
        
        int left = printDistanceK0(root->left, target, k, ans);
        int right = printDistanceK0(root->right, target, k, ans);
        
        if(left > 0)
        {
            if(k == left)
                ans.push_back(root->val);
            else
                printKDown0(root->right, k-left-1, ans);
            return left + 1;
        }
        else if(right > 0)
        {
            if(k == right)
                ans.push_back(root->val);
            else
                printKDown0(root->left, k-right-1, ans);
            return right + 1;
        }
        
        return -1;
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        printDistanceK1(root, target, k, ans);
        return ans;
    }
};