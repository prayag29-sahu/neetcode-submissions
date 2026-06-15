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
    bool hasCycle(ListNode* head) {
        ListNode *first = head;
        ListNode *second = head;

        while(first && first->next){
            second = second->next;
            first = first->next->next;
            if(first==second){
                return true;
            }
        }
        return false;
    }
};
