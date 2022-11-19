/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef ListNode node;
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if(!head)
            return false;
        
        if(head->next == NULL)
            return false;


        if(head->next->next == NULL)
            return false;

        node* slowPtr = head -> next;
        node* fastPtr = head -> next -> next;


        while(slowPtr && fastPtr && slowPtr != fastPtr)
        {
            slowPtr = slowPtr -> next;
            if(!fastPtr -> next)
                return false;
            fastPtr = fastPtr -> next -> next;
        }

        if(slowPtr == fastPtr)
            return true;

        return false;
    }
};