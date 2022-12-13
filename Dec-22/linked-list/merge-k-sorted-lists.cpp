https://leetcode.com/problems/merge-k-sorted-lists/

ListNode* mergeTwoLists(ListNode* f, ListNode* s){
    ListNode* ptr, *curr;
    if(!f)return s;
    if(!s) return f;
    if(f->val < s->val){
        ptr = f;
        f = f->next;
    }
    else{
        ptr = s;
        s = s->next;
    }
    curr = ptr;
    while(f && s){
        if(f->val < s->val){
            curr->next = f;
            f = f->next;
        }else{
            curr->next = s;
            s = s->next;
        }
        curr = curr->next;
    }
    if(f)
        curr->next = f;
    if(s)
        curr->next = s;
    return ptr;
}


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(!n)return NULL;
        ListNode* ans = lists[n-1];
        for(int i = n-2;i >= 0;i--){
            ans = mergeTwoLists(lists[i], ans);
        }
        return ans;
    }
};
