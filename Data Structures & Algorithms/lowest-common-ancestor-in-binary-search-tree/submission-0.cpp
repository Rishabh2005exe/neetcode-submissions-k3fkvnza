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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( (p->val == root->val)||(q->val == root->val) )
            return root;
        int max = p->val > q->val ? p->val:q->val;
        int min = p->val < q->val ? p->val:q->val;
        if(max > root->val && min < root->val )
            return root;
        if(max < root->val)
            return lowestCommonAncestor(root->left,p,q);
        if(min > root->val)
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};
