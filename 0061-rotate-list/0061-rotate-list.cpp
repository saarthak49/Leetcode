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
typedef ListNode node;
class Solution {
public:
    int findLength(node* head)
    {
        node* ptr = head;
        int count = 0;
        while(ptr)
        {
            ptr = ptr ->next;
            count++;
        }
        return count;
    }
    
    node* rotate(node* head)
    {
        node *ptr = head;
        
        if(!head)
            return NULL;
        
        if(ptr -> next == NULL)
            return head;
        while(ptr->next->next)
        {
            ptr = ptr->next;
        }
        node* lastNode = ptr->next;
        ptr->next = NULL;
        lastNode -> next = head;
        return lastNode;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(findLength(head) == 0)
            return NULL;
        
        k = k%findLength(head);
        // cout<<k<<endl;
        node* ptr = head;
        while(k --> 0)
            ptr = rotate(ptr);
        
        return ptr;
        
    }
};