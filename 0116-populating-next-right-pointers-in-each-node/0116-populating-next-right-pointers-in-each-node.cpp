/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#define node Node
class Solution {
public:
    node* nextRight(node* curr)
    {
        curr = curr->next;
        while(curr)
        {
            if(curr->left)
                return curr->left;
            if(curr->right)
                return curr->right;
            curr = curr->next;
        }
        return NULL;
    }
    
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        
        root->next = NULL;
        node* currRoot = root;
        
        while(root)
        {
            node* curr = root;
            while(curr)
            {
                if(curr->left && curr->right)
                {
                    curr->left->next = curr->right;
                    curr->right->next = nextRight(curr);
                }
                else if(curr->left)
                    curr->left->next = nextRight(curr);
                else if(curr->right)
                    curr->right->next = nextRight(curr);
                curr = curr->next;
            }
            if(root->left)
                root = root->left;
            else if(root->right)
                root = root->right;
            else 
                root = nextRight(root);
        }
        return currRoot;
        
    }
};