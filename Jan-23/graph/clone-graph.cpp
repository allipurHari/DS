https://leetcode.com/problems/clone-graph/description/

class Solution {
public:
    Node* solve(Node* node, unordered_map<Node*, Node*> &mp){
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for(auto nd : node->neighbors){
            if(mp.find(nd) == mp.end()){
                newNode->neighbors.push_back(solve(nd, mp));
            }
            else{
                newNode->neighbors.push_back(mp.find(nd)->second);
            }
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if(!node)return node;
        unordered_map<Node*, Node*> mp;
        return solve(node, mp);
    }
};
