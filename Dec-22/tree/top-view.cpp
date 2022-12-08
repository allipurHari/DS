https://bit.ly/3Gs76WV

void solve(TreeNode<int> * root, int val, int h, vector<pair<int, int> > &lv, vector<pair<int, int> > &rv){
    if(!root)
        return;
    if(val < 0){
        if(lv.size() < abs(val))
            lv.push_back({h, root->val});
        else if(lv[abs(val)-1].first > h)
            lv[abs(val)-1] = make_pair(h, root->val);
    }
    else{
        if(rv.size() < val+1)
            rv.push_back({h, root->val});
        else if(rv[val].first > h)
            rv[val] = make_pair(h, root->val);
    }
    solve(root->left, val-1, h+1, lv, rv);
    solve(root->right, val+1, h+1,  lv, rv);
        
}

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<pair<int, int> >lv, rv;
    solve(root, 0, 0, lv, rv);
    reverse(lv.begin(), lv.end());
    vector<int>ans;
    for(int i =0;i < lv.size();i++){
        ans.push_back(lv[i].second);
    }
    for(int i = 0;i < rv.size();i++){
        ans.push_back(rv[i].second);
    }
    return ans;
}
