class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        // If both nodes are null
        if (root1 == NULL && root2 == NULL)
            return NULL;
        
        // If one of them is null, return the other
        if (root1 == NULL)
            return root2;
        if (root2 == NULL)
            return root1;
        
        // Both nodes are present
        TreeNode* merged = new TreeNode(root1->val + root2->val);
        
        merged->left = mergeTrees(root1->left, root2->left);
        merged->right = mergeTrees(root1->right, root2->right);
        
        return merged;
    }
};
