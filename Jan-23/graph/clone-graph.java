https://leetcode.com/problems/clone-graph/description/

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    Map<Node, Node> map;
    Solution(){
        map = new HashMap<>();
    }
    public Node cloneGraph(Node node) {
        if(node == null)
            return node;
        Node newNode = new Node(node.val);
        map.put(node, newNode);
        for(Node itr: node.neighbors){
            if(map.containsKey(itr))
                newNode.neighbors.add(map.get(itr));
            else
                newNode.neighbors.add(cloneGraph(itr));
        }
        return newNode;
    }
}
