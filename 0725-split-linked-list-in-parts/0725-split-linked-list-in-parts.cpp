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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int count = 0;
        ListNode* temp =  head;
        while(temp != NULL) {
            temp = temp->next;
            count++;
        }

        int div = count / k;
        int rem = count % k;
        
        temp = head;
        ListNode* prev = NULL;

        
        vector<ListNode*> list;
        for(int i=0; i<rem; i++) {
            int curr = 1;
            list.push_back(temp);
            while(temp != NULL) {
                prev = temp;
                temp = temp->next;
                if(curr == div + 1) {
                    prev->next = NULL;
                    break;
                }
                curr++;
            }
        }
        for(int i= rem; i<k; i++) {
             int curr = 1;
            list.push_back(temp);
              while(temp != NULL) {
                prev = temp;
                temp = temp->next;
                if(curr == div) {
                    prev->next = NULL;
                    break;
                }
                curr++;
            }
        }

        return list;
        
    }
};