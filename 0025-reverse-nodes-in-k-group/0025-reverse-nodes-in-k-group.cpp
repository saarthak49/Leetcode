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

#define node ListNode
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return NULL;
        
        node* t = head;
        int length = 0;
        while(t)
        {
            length++;
            t = t->next;
        }
        if(length<k)
            return head;
        int count = k;
        node* prev = NULL;
        node* curr = head;
        while(count && curr)
        {
            node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count--;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};