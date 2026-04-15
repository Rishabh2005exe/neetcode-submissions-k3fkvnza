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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = l1;
        vector<int>arr1;
        while(curr)
        {
            arr1.push_back(curr->val);
            curr=curr->next;
        }

        ListNode* currr = l2;
        vector<int>arr2;
        while(currr)
        {
            arr2.push_back(currr->val);
            currr=currr->next;
        }
    
        vector<int>sum;
        int i=0,carry=0;

        while(i<arr1.size() || i< arr2.size() || carry)
        {
            int val = carry;

            if(i< arr1.size()) 
                val +=arr1[i];
            if(i <arr2.size())
                val += arr2[i];
            sum.push_back(val %10);
            carry = val/10;
            i++;
        }

    // create linked list
    ListNode* dummy = new ListNode(0);
    ListNode* cuurr = dummy;

    for (int x : sum) {
        cuurr->next = new ListNode(x);
        cuurr = cuurr->next;
    }

    return dummy->next;
    }
};
