class Solution {
public:
    int sumEvenGrandparent(TreeNode* root, TreeNode* parent = nullptr, TreeNode* grandparent = nullptr) {
        if (!root) return 0;

        int sum = 0;
        if (grandparent && grandparent->val % 2 == 0) {
            sum += root->val;
        }

        sum += sumEvenGrandparent(root->left, root, parent);
        sum += sumEvenGrandparent(root->right, root, parent);
        return sum;
    }
};
