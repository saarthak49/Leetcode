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
    
    string findDuplicates(node* root, unordered_map<string, int > &mp, vector<node*> &finAns)
    {
        if(!root)
            return "#";
        
        string ld = findDuplicates(root->left, mp, finAns);
        string rd = findDuplicates(root->right, mp, finAns);
        string serial = to_string(root->val) + ";" + ld + rd;
        if(mp.find(serial) == mp.end() )
        {
            mp[serial]++;
        }
        else if(mp[serial] == 1)
        {
            finAns.push_back(root);
            mp[serial]++;
        }
        return serial;
        
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<node* > finAns;
        unordered_map<string, int > mp;
        findDuplicates(root, mp, finAns);
        return finAns;
    }
};