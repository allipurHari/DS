https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/859184340/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        TreeNode *curr = root, *prev;
        while(curr){
            ans.push_back(curr->val);
            if(curr->left == nullptr){
                // ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                prev = curr->left;
                while(prev->right && prev->right!= curr){
                    prev = prev->right;
                }
                if(prev->right == nullptr){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = nullptr;
                    ans.pop_back();
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
