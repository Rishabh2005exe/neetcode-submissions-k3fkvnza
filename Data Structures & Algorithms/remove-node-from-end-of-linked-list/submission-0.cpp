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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N =0;
        ListNode* curr= head;
        while(curr)
        {
            curr =curr->next;
            N++;
        }
        int remove = N-n;
        if(remove==0)
            return head->next;
        ListNode* temp = head;
        while(remove-1)
        {
            temp = temp->next;
            remove--;
        }
        temp->next = temp->next->next;
        return head;
    }
};
