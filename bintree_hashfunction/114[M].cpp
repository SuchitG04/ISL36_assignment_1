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
    void flatten(TreeNode* root) {
        if (root)
            revPreOrder(root);
    }

    TreeNode* temp = nullptr;
    void revPreOrder(TreeNode* root) {
        if (root == nullptr) return;
        revPreOrder(root->right);
        revPreOrder(root->left);
        
        root->left = nullptr, root->right = temp, temp = root;
    }
};
