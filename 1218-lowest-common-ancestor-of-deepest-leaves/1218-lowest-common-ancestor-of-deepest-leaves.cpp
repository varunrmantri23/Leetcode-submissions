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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
    
    // Returns a pair: {LCA of deepest leaves in this subtree, depth of this subtree}
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (!node)
            return {nullptr, 0};
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        // If both subtrees have the same depth, then current node is the LCA.
        if (left.second == right.second)
            return {node, left.second + 1};
        else if (left.second > right.second)
            return {left.first, left.second + 1};
        else
            return {right.first, right.second + 1};
    }
};
