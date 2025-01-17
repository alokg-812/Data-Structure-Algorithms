https://leetcode.com/problems/validate-binary-search-tree/description/
https://leetcode.com/problems/validate-binary-search-tree/submissions/1511094573/

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
    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        TreeNode* curr = root;
        stack<TreeNode*>st;
        while(curr!=NULL || st.size()>0){
            while(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if(curr->val <=prev){
                return false;
            }
            prev = curr->val;
            curr = curr->right;
        }
        return true;
    }
};
