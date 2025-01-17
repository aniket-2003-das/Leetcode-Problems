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
    // Function to delete a node from BST.
    TreeNode *deleteNode(TreeNode *root, int Key) {
        // your code goes here
        if(root==NULL) return NULL;
        if(root->val==Key) return helper(root);
        
        TreeNode* dummy = root;
        while(root!=NULL){
            if(root->val>Key){
                if(root->left!=NULL && root->left->val==Key){
                    root->left = helper(root->left);
                    break;
                }
                else root = root->left;
            }
            else{
                if(root->right!=NULL && root->right->val==Key){
                    root->right = helper(root->right);
                    break;
                }
                else root = root->right;
            }
        }
        return dummy;
    }
    
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    
    TreeNode* findLastRight(TreeNode* root){
        if(root->right==NULL) return root;
        return findLastRight(root->right);
    }
};