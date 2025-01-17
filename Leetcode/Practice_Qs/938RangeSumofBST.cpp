// https://leetcode.com/problems/range-sum-of-bst/
// https://leetcode.com/problems/range-sum-of-bst/submissions/1511170177/

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        vector<int>ans;
        TreeNode* curr = root;
        stack<TreeNode*> st;
        while(curr!=NULL or st.size()>0){
            while(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]>=low and ans[i]<=high){
                sum+=ans[i];
            }
        }
        return sum;
    }
};
