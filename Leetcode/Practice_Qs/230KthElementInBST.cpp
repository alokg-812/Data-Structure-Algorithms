https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1511144866/

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
    int kthSmallest(TreeNode* root, int k){
        TreeNode* curr = root;
        vector<int>ans;
        stack<TreeNode*> st;
        while(curr!=NULL || st.size()>0){
            while(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans[k-1];
    }
};
