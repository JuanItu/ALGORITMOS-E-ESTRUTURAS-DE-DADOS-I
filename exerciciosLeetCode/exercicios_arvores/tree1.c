/*
void inorder_dfs(struct TreeNode* root, int** result, int* size, int* capacity) {
    if (root == NULL) {
        return;
    }
    
    inorder_dfs(root->left, result, size, capacity);

    if (*size == *capacity) {
        
        *capacity = (*capacity == 0) ? 1 : *capacity * 2; 
        *result = (int*)realloc(*result, (*capacity) * sizeof(int));
        if (*result == NULL) {
            return; 
        }
    }

    (*result)[*size] = root->val;
    (*size)++;

    inorder_dfs(root->right, result, size, capacity);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = NULL;
    int size = 0;
    int capacity = 0;
    
    inorder_dfs(root, &result, &size, &capacity);

    *returnSize = size;
    
    return result;
}
*/