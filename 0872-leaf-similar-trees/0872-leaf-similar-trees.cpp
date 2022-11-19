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
    TreeNode* getNextv2( TreeNode* &temp, stack<TreeNode*> &s)
    {
        while(!s.empty() || temp)
        {
            if(temp)
            {
                s.push(temp);
                temp = temp->left;
            }
            else
            {
                if(!s.empty())
                {
                    temp = s.top();
                    s.pop();
                    TreeNode *retValue = temp;
                    temp = temp->right;
                    return retValue;
                }
                return NULL;
            }
        }
        return NULL;
    }
    
    void getNext(TreeNode* &curr, TreeNode* &ans, stack<TreeNode *> &s)
    {
        if(curr || !s.empty())
        {
            while(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr = s.top();
            s.pop();
            ans = curr;
            curr = curr->right;
            return;
        }
        ans = NULL;
        return;
    }
    bool isLeaf(TreeNode *ptr)
    {
        if(!ptr->left && !ptr->right)
            return true;
        return false;
    }
    
    bool checkSimilarLeaf( TreeNode *root1, TreeNode *root2)
    {
        TreeNode *curr1 = root1;
        TreeNode *curr2 = root2;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        TreeNode* first = getNextv2(curr1, s1);
        TreeNode* second = getNextv2(curr2, s2);
        
        
        while(first || second)
        {
            while(first && !isLeaf(first))
                first = getNextv2(curr1, s1);
            
            while(second && !isLeaf(second))
                second = getNextv2(curr2, s2);
            
            // if(first && second)
            // {
                // cout<<first->val<<endl;
                // cout<<second->val<<endl<<endl;
            // }
            
            if(!first && second || !second && first || first && second && first->val != second->val)
                return false;
            first = getNextv2(curr1, s1);
            second = getNextv2(curr2, s2);
        }
        return true;
    }
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return checkSimilarLeaf(root1, root2);
    }
};