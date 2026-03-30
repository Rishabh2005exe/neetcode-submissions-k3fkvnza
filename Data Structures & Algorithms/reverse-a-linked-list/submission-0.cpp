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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* t ;
        t = head;
        head = nullptr;
        while(t)
        {
            ListNode* newNode = new ListNode;
            newNode->val = t->val;
            newNode->next = head;
            head = newNode;
            t=t->next;
        }
        
        return head;
    }
};
