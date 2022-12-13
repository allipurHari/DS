https://leetcode.com/problems/copy-list-with-random-pointer/solutions/?orderBy=most_votes

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        Node* node = head, *newHead, *curr;
        newHead = new Node(node->val);
        unordered_map<Node*, Node*> mp;
        mp[node] = newHead;
        node = node->next;
        curr = newHead;
        while(node){
            Node* temp = new Node(node->val);
            mp[node] = temp;
            curr->next = temp;
            curr = temp;
            node = node->next;
        }
        node = head;
        while(node){
            mp[node]->random = mp[node->random];
            node = node->next;
        }
        return newHead;
    }
};
