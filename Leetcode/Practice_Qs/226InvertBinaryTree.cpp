https://leetcode.com/problems/invert-binary-tree/submissions/1468957636/

class Solution {
public:
    void helper(TreeNode* root){
        if(root == NULL) return;
        swap(root->left, root->right);
        helper(root->left);
        helper(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
