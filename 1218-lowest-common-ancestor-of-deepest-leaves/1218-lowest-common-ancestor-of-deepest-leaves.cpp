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
 //The values of the nodes in the tree are unique.
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        //every node i need to check l subtree and r subtree and decide whether current node is lca or the subtree itself had inside , either l or r subtree has depth node then subtree can have lca

        // //calculate depth first and then on max depth we will do lca logic
        // //map node-> depth
        // unordered_map<int, int> depth;
        // dfsDepth(root, 0, depth);
        // // for(auto &i : depth){
        // //     cout << i.first << " " << i.second << endl;
        // // }
        
        int maxDepth = getDepth(root);
        return getLCA(root, 0, maxDepth);
    }
    //macx depth
    int getDepth(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(getDepth(node->left), getDepth(node->right));
    }

    // void dfsDepth(TreeNode* x, int d,unordered_map<int, int> &depth){
    //     if(x == nullptr) return;
    //     depth[x->val] = d;
    //     dfsDepth(x->left, d+1,depth);
    //     dfsDepth(x->right, d+1,depth);
    // }
    //get lca
     TreeNode* getLCA(TreeNode* n, int depth, int maxDepth) {
        if (!n) return nullptr;
        if (depth == maxDepth - 1 && !n->left && !n->right) return n;

        TreeNode* left = getLCA(n->left, depth + 1, maxDepth);
        TreeNode* right = getLCA(n->right, depth + 1, maxDepth);

        if (left && right) return n;
        return left ? left : right;
    }
};