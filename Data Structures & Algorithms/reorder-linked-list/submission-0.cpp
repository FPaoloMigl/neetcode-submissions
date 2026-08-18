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
    void reorderList(ListNode* head) {
        // we use slow and fast pointer to know the second half 
        // we stop when Fast is null
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) { // this is because in case of odd list it doesn't throw error memory
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = slow->next; // this is gonna be the start of the second half
        slow->next = nullptr; // this is because the list is gonna be split in two parts

        //reversing
        ListNode* prev = nullptr;
        while(second){
            auto tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // merge two halfs
        second = prev; // beginning of the second half
        auto first = head;

        while (second){
            auto tmp1 = first->next;
            auto tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
