class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counter;
        vector<TreeNode*> stack;
        stack.push_back(root);
        
        while (!stack.empty()) {
            TreeNode* node = stack.back();
            stack.pop_back();

            counter[node->val]++;
            if (node->left != nullptr) {
                stack.push_back(node->left);
            }
            if (node->right != nullptr) {
                stack.push_back(node->right);
            }
        }
        
        int maxFreq = 0;

        for (auto& [key, val] : counter) {
            maxFreq = max(maxFreq, val);
        }
        
        vector<int> ans;
        for (auto& [key, val] : counter) {
            if (val == maxFreq) {
                ans.push_back(key);
            } 
        }
        
        return ans;
    }
};