
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        int totalSum = 0;

        while (!st.empty()) {
            auto [node, currentNum] = st.top();
            st.pop();

            if (!node) continue;

            currentNum = currentNum * 10 + node->val;

            // If its a leaf node
            if (!node->left && !node->right) {
                totalSum += currentNum;
            } else {
                if (node->right) st.push({node->right, currentNum});
                if (node->left) st.push({node->left, currentNum});
            }
        }

        return totalSum;
    }
};
