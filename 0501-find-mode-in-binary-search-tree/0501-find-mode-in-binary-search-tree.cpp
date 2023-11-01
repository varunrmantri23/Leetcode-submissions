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
    map<int,int> m;
public:
    vector<int> findMode(TreeNode* root) {
        if(root->right == NULL && root-> left == NULL) return {root->val};
        findModeHelper(root);
        vector<int> ans;
        int max_ = 0;
        for(auto a:m){
            if(a.second>0)
            {
                max_ = max(max_,a.second);
            }
        }
        for(auto a:m){
            if(a.second==max_)
                ans.push_back(a.first);
        }
        return ans;
    }
    void findModeHelper(TreeNode* root) {
        if(root == NULL)return ;

        m[root->val]++;
        if(root->right != NULL);
        findModeHelper(root->right);
        if(root->left != NULL)
        findModeHelper(root->left);
    }

};