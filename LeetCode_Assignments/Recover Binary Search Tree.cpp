class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *x = nullptr, *y = nullptr, *pred = nullptr;

        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();

            if (pred && root->val < pred->val) {
                y = root;
                if (!x) x = pred;
                else break;
            }
            pred = root;
            root = root->right;
        }
        if (x && y) {
            swap(x->val, y->val);
        }
    }
};
