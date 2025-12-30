/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // use hashset
        unordered_set<ListNode*> ust;

        while(headA != nullptr) {
            ust.insert(headA);
            headA = headA -> next;
        }

        while(headB != nullptr) {
            if(ust.find(headB) != ust.end()) return headB;
            headB = headB -> next;
        }

        return nullptr;
    }
};