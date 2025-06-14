class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parentMap;
    int maxDepth = 0;
    vector<TreeNode*> deepestLeaves;


    void bfsParents(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, depth] = q.front(); q.pop();
            if (depth > maxDepth) {
                maxDepth = depth;
                deepestLeaves.clear();
                deepestLeaves.push_back(node);
            } else if (depth == maxDepth) {
                deepestLeaves.push_back(node);
            }
            if (node->left) {
                parentMap[node->left] = node;
                q.push({node->left, depth + 1});
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push({node->right, depth + 1});
            }
        }
    }

    TreeNode* lcaOfDeepestLeaves(TreeNode* root) {
        bfsParents(root);

        vector<TreeNode*> nodes = deepestLeaves;
        while (nodes.size() > 1) {
            unordered_set<TreeNode*> parents;
            for (auto node : nodes) {
                parents.insert(parentMap[node]);
            }
            nodes.assign(parents.begin(), parents.end());
        }
        return nodes[0];
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;
        parentMap[root] = nullptr;
        return lcaOfDeepestLeaves(root);
    }
};
