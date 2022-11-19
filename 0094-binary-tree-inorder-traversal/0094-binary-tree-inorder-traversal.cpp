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
    
    void morrisInorder(vector<int> &inorder, node* root)
    {
        while(root)
        {
            if(!root->left)
            {
                inorder.push_back(root->val);
                root = root->right;
            }
            else
            {
                node* temp = root->left;
                while(temp->right && temp->right != root)
                {
                    temp = temp -> right;
                }
                
                if(temp->right == root)
                {
                    inorder.push_back(root->val);
                    temp->right = NULL;
                    root = root->right;
                }
                else
                {
                    temp->right = root;
                    root = root->left;
                }
            }
        }
    }
    
    
    node* getNext1(stack<node*> &s, node* &temp)
    {
        if(temp || !s.empty())
        {
            while(temp)
            {
                s.push(temp);
                temp = temp->left;
            }
            node* inorderElement = s.top();
            temp = inorderElement;
            s.pop();
            temp = temp -> right;
            return inorderElement;
        }
        return NULL;
    }
    
    void getNext0(TreeNode* &curr, TreeNode* &ans, stack<TreeNode*> &s)
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
    
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> fin;
        stack<TreeNode*> s;
        node* temp = root;
        node* ino = getNext1(s, temp);
        while(ino)
        {
            fin.push_back(ino->val);
            ino = getNext1(s, temp);
        }
        
        return fin;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> fin;
        morrisInorder(fin, root);
        return fin;
    }
};