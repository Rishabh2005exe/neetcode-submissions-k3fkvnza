class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL)
            return true;
        if(root ==NULL)
            return false;
        
        if(root->val == subRoot->val)
        {
            if(sametree(root,subRoot))
                return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right , subRoot);
    }

private:
    bool sametree(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL)
            return true;

        if(p == NULL || q == NULL)
            return false;

        if(p->val != q->val)
            return false;

        bool left = sametree(p->left, q->left);
        bool right = sametree(p->right, q->right);

        return left && right;
    }
};