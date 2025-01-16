https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/1510710490/

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
    TreeNode* searchBST(TreeNode* root, int valu) {
        if(root == NULL) return NULL;
        else{
            if(root->val == valu){
                return root;
            }
            else if(root->val>valu){
                return searchBST(root->left, valu);
            }
            else{
                return searchBST(root->right, valu);
            }
        }
        return NULL;
        
    }
};
