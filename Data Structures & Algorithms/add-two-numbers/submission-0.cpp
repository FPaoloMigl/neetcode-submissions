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
        ListNode dummy(0);
        ListNode* result = &dummy; 
        int carry(0);
        while(l1 || l2 || carry) {
            
            if (!l1) l1 = new ListNode(0);
            if (!l2) l2 = new ListNode(0);

            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* sumNode = new ListNode(sum);
            result->next = sumNode;
            l1 = l1->next;
            l2 = l2->next;
            result = result->next;
        }

        return dummy.next;
    }
};
