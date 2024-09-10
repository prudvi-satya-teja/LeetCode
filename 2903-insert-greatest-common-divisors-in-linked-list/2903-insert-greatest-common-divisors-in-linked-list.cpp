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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;

        while(temp != NULL && temp->next != NULL) {
                ListNode* b = new ListNode(gcd(temp->next->val, temp->val));
                ListNode *t = temp->next;
                temp->next = b;
                b->next = t;
                temp=t;
        }
        return head;
    }
};