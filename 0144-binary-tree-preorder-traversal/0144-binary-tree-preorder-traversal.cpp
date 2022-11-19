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
    
    node* preOrderIterator(stack<node*> &s, node* &temp)
    {
        if(temp || !s.empty())
        {
            node* preElement = NULL;
            if(temp)
            {
                preElement = temp;
                s.push(temp);
                temp = temp->left;
                return preElement;
            }
            while(!s.empty() && !temp)
            {
                temp = s.top();
                s.pop();
                temp = temp->right;
            }
            if(temp){
                preElement = temp;
                s.push(temp);
                temp = temp->left;
                return preElement;
            }
        }
        return NULL;
    }
    
    
    void preOrderIterative(node* root, vector<int> &solution)
    {
        stack<node* > s;
        node* curr = root;
        while(curr || !s.empty())
        {
            if(curr)
            {
                s.push(curr);
                solution.push_back(curr->val);
                curr = curr->left;
            }
            else
            {
                curr = s.top();
                s.pop();
                curr = curr->right;
            }
        }
    }
    
    
    void preOrderMorris(node* root, vector<int> &solution)
    {
        node* curr = root;
        while(curr)
        {
            if(!curr->left)
            {
                solution.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode* temp = curr->left;
                while(temp && temp->right && temp->right!=curr)
                    temp = temp->right;
                
                if(temp && temp->right == curr)
                {
                    curr = curr->right;
                    temp->right = NULL;
                }
                else
                {
                    solution.push_back(curr->val);
                    temp->right = curr;
                    curr = curr->left;
                    
                }
                
            }
        }
        
    }
    
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> solution;
        // preOrderIterative(root, solution);
        
        stack<node*> s;
        node* temp = root;
        node* preElement = preOrderIterator(s, temp);
        while(preElement)
        {
            solution.push_back(preElement->val);
            preElement = preOrderIterator(s, temp);
        }
        
        return solution;
        
    }
};