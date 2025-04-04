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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = getDepth(root);
        return getLCA(root, 0, maxDepth);
    }

    //macx depth
    int getDepth(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(getDepth(node->left), getDepth(node->right));
    }

    TreeNode* getLCA(TreeNode* n, int depth, int maxDepth) {
        if (!n) return nullptr;
        if (depth == maxDepth - 1 && !n->left && !n->right) return n;

        TreeNode* left = getLCA(n->left, depth + 1, maxDepth);
        TreeNode* right = getLCA(n->right, depth + 1, maxDepth);

        if (left && right) return n;
        return left ? left : right;
    }
};