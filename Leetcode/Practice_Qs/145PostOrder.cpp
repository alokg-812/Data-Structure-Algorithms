https://leetcode.com/problems/binary-tree-postorder-traversal/description/
https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/1514642481/

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
vector<int>post;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return post;
        else{
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            post.push_back(root->val);
        }
        return post;
    }
};
