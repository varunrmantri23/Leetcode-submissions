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
        //we can find maxdepth with recursion -> then find those nodes and check 
        //if they dont have any l or r , so they can just return their value to up, and similarly their parent will check if l and r came, so parent becomes lca, if either or, then that particular subree lca is the lca and we pass to root, and then finally we return the tree with lca node as root
        
        int maxDepth = getMaxDepth(root,0);
        // cout <<maxDepth;
        //now we dfs and if node depth match with maxdepth we do lca logic
        return dfs(root, 0 , maxDepth);
    }

    int getMaxDepth(TreeNode* root, int depth){
        if(root == nullptr) return 0;
        return max(depth,max(getMaxDepth(root->left, depth+1),getMaxDepth(root->right, depth + 1)));
    }

    TreeNode* dfs(TreeNode* root, int depth, int maxDepth){
        if(!root) return root; //root is null only so yes
        if(depth == maxDepth && root->left == nullptr && root->right ==nullptr){
            return root;
        }
        TreeNode* left = dfs(root->left, depth+1, maxDepth);
        TreeNode* right = dfs(root->right, depth+1, maxDepth);
        if(left && right) return root; //parent
        else if(left && !right) return left;
        else return right;
    }
};