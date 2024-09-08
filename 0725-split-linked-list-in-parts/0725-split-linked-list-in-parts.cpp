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
        for(int i=0; i<k; i++) {
            int curr = 1;
            list.push_back(temp);
            while(temp != NULL) {
                prev = temp;
                temp = temp->next;
                if(curr == div + 1 && rem > 0) {
                    prev->next = NULL;
                    rem--;
                    break;
                }
                else if(curr == div && rem == 0){
                     prev->next = NULL;
                     break;
                }
                curr++;
            }
        }

        return list;
        
    }
};