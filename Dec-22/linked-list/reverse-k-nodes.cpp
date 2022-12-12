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
    bool lastBatch = false;
    ListNode *curr, *nxt = NULL;
    void solve(ListNode *node, int count, int k){
        if(node == NULL || node->next == NULL){
            if(count == 1){
                curr = nxt;
                nxt = node;
                lastBatch = false;
                return;
            }
            lastBatch = true;
            nxt = node;
            return;
        }
        if(count == 1){
            solve(node->next, k, k);
            curr = nxt;
            nxt = node;
            lastBatch = false;
            return;
        }
        solve(node->next, count-1, k);
        if(!lastBatch){
            node->next->next = node;
            node->next = curr;
        }else{
            nxt = node;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        solve(head, k, k);
        return nxt;
    }
};
