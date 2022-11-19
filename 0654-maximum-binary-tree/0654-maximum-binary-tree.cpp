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
typedef TreeNode node;
class Solution {
    
public:
    
    int findHighestIndex(vector<int> nums, int start, int end)
    {
        int maxIndex = -1; 
        int maxSeen = INT_MIN;
        for(int i = start; i<=end; i++)
        {
            if(nums[i] > maxSeen)
            {
                maxSeen = nums[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
    
    TreeNode* buildTree(vector<int> nums, int start, int end)
    {
        if(start == end)
        {
            node *t = new node();
            t->val = nums[start];
            t->left = NULL;
            t->right = NULL;
            return t;
        }
        
        if(start > end)
            return NULL;
        
        
        int maxIndex = findHighestIndex(nums, start, end);
        node *t = new node();
        t->val = nums[maxIndex];
        t->left = buildTree(nums, start, maxIndex - 1);
        t->right = buildTree(nums, maxIndex + 1, end);
        return t;
            
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};