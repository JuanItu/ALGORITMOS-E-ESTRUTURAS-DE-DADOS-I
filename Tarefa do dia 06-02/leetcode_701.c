
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */
/*
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        struct TreeNode* novoNo = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        novoNo->val = val;
        novoNo->left = NULL;
        novoNo->right = NULL;
        return novoNo;
    }
    
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    
    return root;
}
*/