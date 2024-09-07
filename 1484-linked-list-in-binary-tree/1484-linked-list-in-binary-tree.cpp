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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isThere = false;

    void solve(TreeNode* root , ListNode* head) {
        if(root == NULL  && head == NULL || head == NULL) {
            isThere = true;
            return;
        }
        if(root == NULL) return;

        if(root->val == head->val) {
            solve(root->left, head->next);
            solve(root->right, head->next);
        }
    }

    void preorder( TreeNode* root, ListNode* head) {
        if(root == NULL) {
            return;
        }
        if(root->val == head->val) {
            solve(root, head);
        }

        preorder( root->left, head);
        preorder( root->right, head);
    }
   
    bool isSubPath(ListNode* head, TreeNode* root) {

        preorder(root, head);
        return isThere;
    }
};