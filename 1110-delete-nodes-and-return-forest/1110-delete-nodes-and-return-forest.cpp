class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        root = processNode(root, toDeleteSet, forest);

        // If the root is not deleted, add it to the forest
        if (root) {
            forest.push_back(root);
        }

        return forest;
    }

private:
    TreeNode* processNode(TreeNode* node, unordered_set<int>& toDeleteSet,
                          vector<TreeNode*>& forest) {
        if (!node) {
            return nullptr;
        }

        node->left = processNode(node->left, toDeleteSet, forest);
        node->right = processNode(node->right, toDeleteSet, forest);

        // Node Evaluation: Check if the current node needs to be deleted
        if (toDeleteSet.find(node->val) != toDeleteSet.end()) {
            // If the node has left or right children, add them to the forest
            if (node->left) {
                forest.push_back(node->left);
            }
            if (node->right) {
                forest.push_back(node->right);
            }
            // Delete the current node and return null to its parent
            delete node;
            return nullptr;
        }

        return node;
    }
};