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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> v(m, vector<int> (n, -1));

        int startrow = 0;
        int startcol = 0;
        int endrow = n-1;
        int endcol = m-1;

        while(startrow <= endrow && startcol <= endcol && head != NULL) {
           
            // top
            for(int i=startrow; i<=endrow; i++) {
                    if(head == NULL) break;
                 v[startcol][i] = head->val;
                 head = head->next;
                //  if(head == NULL) break;
            }

            //right
            for(int i=startcol+1; i<=endcol; i++) {
                    if(head == NULL) break;
                v[i][endrow] = head->val; 
                head = head->next;
            }

            //bottom
            for(int i=endrow-1; i>=startrow; i--) {   
                 if(head == NULL) break;
                v[endcol][i] = head->val;
                head = head->next;

            }

            //left
            for(int i=endcol-1; i>startrow; i--) {
                    if(head == NULL) break;
                v[i][startrow] = head->val;
                  head = head->next;
                // if(head == NULL) break;
            }

            startrow++, startcol++, endrow--, endcol--;
        }
        return v;
    }
};