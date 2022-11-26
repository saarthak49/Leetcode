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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        Node* head = NULL;
        Node* tail = NULL;
        while(l1 || l2)
        {
            int first = l1 != NULL ? l1 -> val : 0;
            int second = l2 != NULL ? l2 -> val : 0;
            
            int sum = first + second + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            Node* node = new Node();
            node -> val = sum;
            if(!head)
            {
                head = node;
                tail = node;
                node->next = NULL;
            }
            else
            {
                tail -> next = node;
                node -> next = NULL;
                tail = node;
            }
            l1 = l1 != NULL ? l1 -> next : NULL;
            l2 = l2 != NULL ? l2 -> next : NULL;
        }
        if(carry)
        {
            Node* node = new Node();
            node -> val = carry;
            tail -> next = node;
            node -> next = NULL;
            tail = node;
        }
        return head;
    }
};