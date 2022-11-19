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
    
    vector<int> postorderTraversal(node* root)
    {
        stack<node*> s;
        vector<int> solution;
        node* temp = root;
        while(temp || !s.empty())
        {
            while(temp)
            {
                s.push(temp);
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            if(!s.empty() && temp == s.top())
            {
                temp = temp -> right;
            }
            else
            {
                solution.push_back(temp->val);
                temp = NULL;
            }
        }
        return solution;
    }
    
    
    vector<int> postorderTraversal0(TreeNode* root) {
        node* curr = root;
        vector<int> solution;
        while(curr)
        {
            if(!curr->left)
            {
                curr = curr->right;
            }
            else
            {
                node *ltemp = curr->left;
                while(ltemp && ltemp->right && ltemp->right != curr)
                {
                    ltemp = ltemp -> right;
                }
                if(ltemp->right == curr)
                {
                    //left side explored;
                    ltemp->right = NULL;
                    curr = curr->right;
                }
                else
                {
                    ltemp->left = curr;
                    node* rtemp = curr->right;
                    while(rtemp && rtemp->right && rtemp->right != curr)
                        rtemp = rtemp->left;
                    if(rtemp && rtemp->left == curr)
                    {
                        //explored right side already just print the node
                        
                    }
                    else
                    {
                        //right needs exploring
                    }
                }
            }
        }
        return solution;
    }
};