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
    
    void buildSegmentTree(vector<int> &segmentTree, int low, int high, int pos, vector<int> nodeLevel)
    {
        if(low > high)
            return;
        if( low == high)
        {
            segmentTree[pos] = low;
            return;
        }
        
        int mid = low + (high - low)/2;
        buildSegmentTree(segmentTree, low, mid, pos*2 + 1, nodeLevel);
        buildSegmentTree(segmentTree, mid + 1, high, pos*2 + 2, nodeLevel);
        
        
        int left = segmentTree[2*pos + 1];
        int right = segmentTree[2*pos + 2];
        
        segmentTree[pos] = nodeLevel[left]<nodeLevel[right]?left:right;
        
        
    }
    
    int query(vector<int> segmentTree, int low, int high, int qlow, int qhigh, int pos, vector<int> nodeLevel)
    {
        if(qlow <= low && qhigh >= high)
            return segmentTree[pos];
        else if(qlow > high || qhigh < low)
            return -1;      //returning an invalid index
    
        
        //else overlapping query both the sides and get their answers
        int mid = low + (high - low) / 2;
        int leftAnswer = query(segmentTree, low, mid, qlow, qhigh, 2 * pos + 1, nodeLevel);
        int rightAnswer = query(segmentTree, mid + 1, high, qlow, qhigh, 2 * pos + 2, nodeLevel);
        
        if(leftAnswer == -1)
            return rightAnswer;
        if(rightAnswer == -1)
            return leftAnswer;
        
        return nodeLevel[leftAnswer] < nodeLevel[rightAnswer]? leftAnswer: rightAnswer;
    }
    
    void buildEulerArray(node* root, vector<node* > &euler, int level, vector<int> &nodeLevel)
    {
        if(!root)
            return;
        euler.push_back(root);
        nodeLevel.push_back(level);
        if(root->left)
        {
            buildEulerArray(root->left, euler, level + 1, nodeLevel);
            euler.push_back(root);
            nodeLevel.push_back(level);
        }
        if(root->right)
        {
            buildEulerArray(root->right, euler, level + 1, nodeLevel);
            euler.push_back(root);
            nodeLevel.push_back(level);
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<node* > euler;
        vector<int> nodeLevel;
        buildEulerArray(root, euler, 0, nodeLevel);
        int n = euler.size();
        unordered_map<int, int> lfi;
        for(int i = 0; i<=n-1; i++)
        {
            if(lfi.find(euler[i]->val) == lfi.end())
                lfi[euler[i]->val] = i;
        }
        
        int first = p->val;
        int second = q->val;
        
        vector<int> segmentTree(4*n + 6, -1);
        
        buildSegmentTree(segmentTree, 0, n-1, 0, nodeLevel);
        int firstIndex = lfi[first];
        int secondIndex = lfi[second];
        int a = min(firstIndex, secondIndex);
        int b = max(firstIndex, secondIndex);
        firstIndex = a;
        secondIndex = b;
        int answerIndex = query(segmentTree, 0, n-1, firstIndex, secondIndex, 0, nodeLevel);
        
        return euler[answerIndex];
        
        
    }
};