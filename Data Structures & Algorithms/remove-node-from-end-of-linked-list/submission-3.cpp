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
        // One way to solve this might be to iterate over it, save a counter
        // then iterate again and compute which one to remove

        int size = 0;

        // edge case 
        if (head->next == nullptr && n == 1) return nullptr;

        // iteration to know the size of the linked list
        ListNode* node = head;
        while (node) {
            size++; // first node cnt = 1
            node = node->next;
        }

        // here we compute which node to delete
        int nodeToDelete = size - n;

        // edge case: we eliminate the head
        if (nodeToDelete == 0) return head->next;

        int cnt = 0;
        node = head;
        // now iterate again to find the node
        while (node) {
            if (size - cnt == n + 1) {
                node->next = node->next->next;
            }

            node = node->next;
            cnt++;
        }

        return head;
    }
};
