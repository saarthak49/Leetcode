/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
typedef ListNode Node;
class Solution {
public:
    Node* reverse(Node* head)
    {
        Node* ptr = head;
        Node* prev = NULL;
        while(ptr)
        {
            // cout<<"ran\n";
            Node* temp = ptr -> next;
            ptr -> next = prev;
            prev = ptr;
            ptr = temp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        Node* h = NULL;
        Node* t = NULL;
        stack<int> s;
        while(head)
        {
            int val = head->val;
            while(!s.empty() && s.top() < val)
            {
                s.pop();
            }
            s.push(val);
            head = head -> next;
        }
        
        while(!s.empty())
        {
            Node* node = new Node();
            node -> val = s.top();
            s.pop();
            if(!h)
            {
                h = node;
                t = node;
            }
            else
            {
                t -> next = node;
                t = node;
            }
        }
        // return h;
        // while(h)
        // {
        //     cout<<h->val<<" ";
        //     h = h->next;
        // }
        // cout<<endl;
        return reverse(h);
    }
};