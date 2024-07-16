class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Find the Lowest Common Ancestor (LCA) of start and destination nodes
        TreeNode* lowestCommonAncestor =
            findLowestCommonAncestor(root, startValue, destValue);

        string pathToStart;
        string pathToDest;

        // Find paths from LCA to start and destination nodes
        findPath(lowestCommonAncestor, startValue, pathToStart);
        findPath(lowestCommonAncestor, destValue, pathToDest);

        string directions;

        // Add "U" for each step to go up from start to LCA
        directions.append(pathToStart.length(), 'U');

        // Append the path from LCA to destination
        directions.append(pathToDest);

        return directions;
    }

private:
    TreeNode* findLowestCommonAncestor(TreeNode* node, int value1, int value2) {
        if (node == nullptr) return nullptr;

        if (node->val == value1 || node->val == value2) return node;

        TreeNode* leftLCA =
            findLowestCommonAncestor(node->left, value1, value2);
        TreeNode* rightLCA =
            findLowestCommonAncestor(node->right, value1, value2);

        if (leftLCA == nullptr)
            return rightLCA;
        else if (rightLCA == nullptr)
            return leftLCA;
        else
            return node;  // Both values found, this is the LCA
    }

    bool findPath(TreeNode* node, int targetValue, string& path) {
        if (node == nullptr) return false;

        if (node->val == targetValue) return true;

        // Try left subtree
        path.push_back('L');
        if (findPath(node->left, targetValue, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        // Try right subtree
        path.push_back('R');
        if (findPath(node->right, targetValue, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        return false;
    }
};