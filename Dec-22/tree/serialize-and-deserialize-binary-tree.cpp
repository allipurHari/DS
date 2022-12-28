https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> v;
        string s = "";
        queue<TreeNode*>q;
        if(!root)
            return s;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front){
                v.push_back(to_string(front->val));
                q.push(front->left);
                q.push(front->right);
            }
            else
                v.push_back("n");
        }
        for(int i = 0;i < v.size();i++){
            s += v[i] + " ";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<string>v;
        string word;
        while(ss >> word){
            v.push_back(word);
        }
        ss.clear();
        if(!v.size())
            return nullptr;
        queue<TreeNode*>q;
        int tval = stoi(v[0]);
        TreeNode *root = new TreeNode(tval);
        q.push(root);
        for(int i = 1;i < v.size();i++){
            TreeNode *p = q.front();
            q.pop();
            if(v[i] != "n"){
                int val = stoi(v[i]);
                TreeNode *temp = new TreeNode(val);
                p->left = temp;
                q.push(temp);
            }
            i++;
            if(v[i] != "n"){
                int val = stoi(v[i]);
                TreeNode *temp = new TreeNode(val);
                p->right = temp;
                q.push(temp);
            }
        }
        return root;
    }
};
